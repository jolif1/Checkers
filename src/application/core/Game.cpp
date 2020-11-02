#include "Game.h"

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
        //Create Black Checkers. Rows 0 -> middle - 1
        for( int i = 0; i < (Board::kNumberOfColumns/2 - 1) ; i++ )
        {
            for( int j = ((i+1)%2); j < Board::kNumberOfRows; j+=2 )
            {
                auto lChecker { mCheckerFactory->createChecker( Position(i,j), Checker::Team::Black ) };

                mCheckers.insert( { lChecker->getPosition(), lChecker } );
                added( lChecker );
            }
        }

        //Create White Checkers. Rows middle + 1 -> end
        for( int i = (Board::kNumberOfColumns/2 + 1); i < Board::kNumberOfColumns; i++ )
        {
            for( int j = ((i+1)%2); j < Board::kNumberOfRows; j+=2 )
            {
                auto lChecker { mCheckerFactory->createChecker( Position(i,j), Checker::Team::White ) };

                mCheckers.insert( { lChecker->getPosition(), lChecker } );
                added( lChecker );
            }
        }
    }

    void Game::requestMove(  const domain::CheckerPtr& pChecker, const domain::Position& pNewPos )
    {
        validateMove( pChecker, pNewPos );
    }

    void Game::validateMove( const domain::CheckerPtr& pChecker, const domain::Position& pNewPos )
    {
        // you can move in a diagonal only
        // you cannot jump on a tile if it is already occupied
        // you must move forward, unless if your checker is a king
        // you can jump several ennemry checkers, as long as there is a free spot behind them and that they are on the same diagonal


    }
}
