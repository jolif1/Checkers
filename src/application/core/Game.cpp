#include "Game.h"

#include <cmath>
#include <domain/Board.h>
#include <set>

namespace application::core
{
    using domain::Board;
    using domain::CheckerPtr;
    using domain::Checker;
    using domain::CheckerFactoryPtr;
    using domain::Position;

    Game::Game( const CheckerFactoryPtr& pCheckerFactory ) :
        mCheckerFactory( pCheckerFactory )
    {

    }

    void Game::newGame()
    {
        // We assume here that the top-left cell index is (0,0) and the bot right cell index is ( kNumberofRows, kNumberOfColumns )
        //Create Black Checkers. Rows 0 -> middle - 1
        for( int i = 0; i < (Board::kNumberOfRows/2 - 1) ; i++ )
        {
            for( int j = ((i+1)%2); j < Board::kNumberOfRows; j+=2 )
            {
                auto lChecker { mCheckerFactory->createChecker( Position(i,j), Checker::Team::Black ) };

                mCheckers.insert( { lChecker->getPosition(), lChecker } );
                added( lChecker );
            }
        }

        //Create White Checkers. Rows middle + 1 -> end
        for( int i = (Board::kNumberOfRows/2 + 1); i < Board::kNumberOfColumns; i++ )
        {
            for( int j = ((i+1)%2); j < Board::kNumberOfColumns; j+=2 )
            {
                auto lChecker { mCheckerFactory->createChecker( Position(i,j), Checker::Team::White ) };

                mCheckers.insert( { lChecker->getPosition(), lChecker } );
                added( lChecker );
            }
        }
    }

    void Game::requestMove( const domain::Position& pOldPos, const domain::Position& pNewPos )
    {
        std::string lErrMsg;
        auto        lCheckerIt { mCheckers.find( pOldPos ) };
        CheckerPtr  lChecker { nullptr };

        try
        {
            if( mCheckers.end() == lCheckerIt )
                throw std::runtime_error("There's no checkers at the given initial position!");

            lChecker = lCheckerIt->second;
            validateMove( lChecker, pNewPos ); //TODO: pass Position* optional. If not NULL, fill it when computing jump
        }
        catch ( std::runtime_error& ex )
        {
            lErrMsg = ex.what();
        }

        if( lErrMsg.empty() )
        {
            // Remove any checker that may have been jumped
            if( std::abs( lChecker->getPosition().getRow() - pNewPos.getRow() ) == 2 )
            {
                int         lMidRow         { ( lChecker->getPosition().getRow() + pNewPos.getRow() ) / 2 };
                int         lMidCol         { ( lChecker->getPosition().getCol() + pNewPos.getCol() ) / 2 };
                Position    lJumpedPos      { lMidRow, lMidCol };
                auto        lRemovedChecker { mCheckers.at( lJumpedPos ) };

                mCheckers.erase( lJumpedPos );
                removed( lRemovedChecker );
            }

            // Move the checker
            auto lOldPos { lChecker->getPosition() };
            auto lNode { mCheckers.extract( lOldPos ) };

            lNode.key() = pNewPos;
            lChecker->setPosition( pNewPos );
            mCheckers.insert( std::move( lNode ) );

            moved( lChecker, lOldPos );
        }
        else
        {
            //notify the frontend ?
        }
    }

    std::set<Position> computeNeighbors( const domain::CheckerPtr& pChecker )
    {
        std::set<Position>  lRet;
        auto                lPos { pChecker->getPosition() };

        if( lPos.getRow() > 0 )
        {
            if( lPos.getCol() > 0 ) //add top left cell
                lRet.insert( { pChecker->getPosition() - Position{ 1,-1} } );

            if( lPos.getCol() < Board::kNumberOfColumns ) //add top right cell
                lRet.insert( { pChecker->getPosition() - Position{ 1, 1} } );
        }

        if( lPos.getRow() < Board::kNumberOfRows )
        {
            if( lPos.getCol() > 0 ) // add bottom left cell
                lRet.insert( { pChecker->getPosition() - Position{-1,-1} } );

            if( lPos.getCol() < Board::kNumberOfColumns ) // add bottom right cell
                lRet.insert( { pChecker->getPosition() - Position{-1, 1} } );
        }

        return lRet;
    }

    void Game::validateMove( const domain::CheckerPtr& pChecker, const domain::Position& pNewPos )
    {
        // you can move in a diagonal only
        // you cannot jump on a tile if it is already occupied
        // you must move forward, unless if your checker is a king
        // you can jump several ennemry checkers, as long as there is a free spot behind them and that they are on the same diagonal

        // We assume that the frontend is smart enough not to provide a new position outside of the board (like [-1, 3])
        // We assume that the checker is indeed at the given position.

        //Check for valid position
        std::set<Position>  lValidPositions      { computeNeighbors( pChecker ) };
        Position lTopLeftDelta { -1, -1 };
        Position lTopRightDelta { -1, 1 };
        Position lBotLeftDelta { 1, -1 };
        Position lBotRightDelta { 1, 1 };

        //Remove invalid positions form neighboring cells
        if( Checker::Rank::Peon == pChecker->getRank() ) // Checker not a king
        {
            if( Checker::Team::White == pChecker->getTeam() )  // Checker white
            {
                //Remove bottom positions (neighbor.row > checker.row)
                auto lLeftIt = lValidPositions.find( pChecker->getPosition() + lBotLeftDelta );
                auto lRightIt = lValidPositions.find( pChecker->getPosition() + lBotRightDelta );

                if( lValidPositions.end() != lLeftIt )
                    lValidPositions.erase( lLeftIt );
                if( lValidPositions.end() != lLeftIt )
                    lValidPositions.erase( lRightIt );
            }
            else // Checker black
            {
                //Remove top positions (neighbor.row < checker.row)
                auto lLeftIt = lValidPositions.find( pChecker->getPosition() + lTopLeftDelta );
                auto lRightIt = lValidPositions.find( pChecker->getPosition() + lTopRightDelta );

                if( lValidPositions.end() != lLeftIt )
                    lValidPositions.erase( lLeftIt );
                if( lValidPositions.end() != lRightIt )
                    lValidPositions.erase( lRightIt );
            }
        }

        std::set<Position> lValidJumps;
        for( auto lValidPosIt = lValidPositions.begin(); lValidPosIt != lValidPositions.end();  )
        {
            auto it = mCheckers.find( *lValidPosIt );

            if( it != mCheckers.end() ) // A checker is present on this position
            {
                lValidPosIt = lValidPositions.erase( lValidPosIt );

                if( pChecker->getTeam() != it->second->getTeam() )
                {
                    // Compute position diagonnally oposite of the present checker.
                    // ex: moved checker (3,3), present checker (4,4) --> compute (5,5)
                    auto lJumpPos   { it->first + ( it->first - pChecker->getPosition() ) };
                    auto lJumpPosIt { mCheckers.find( lJumpPos ) };

                    //If the position is free, jump is valid
                    if( mCheckers.end() == lJumpPosIt )
                        lValidJumps.insert( lJumpPos );
                }
                else
                {
                    //Checkers belong to the same team -> no jump possible
                }
            }
            else // The cell is empty --> valid move
            {
                lValidPosIt++;
            }
        }

        for( auto lValidJump : lValidJumps )
            lValidPositions.insert( lValidJump );

        if( lValidPositions.end() == lValidPositions.find( pNewPos ) )
            throw std::runtime_error("Invalid move !");
    }
}
