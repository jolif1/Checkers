#include "Game.h"

#include <domain/Board.h>
#include <set>

namespace application::core
{
    using domain::Board;
    using domain::CheckerPtr;
    using domain::Checker;
    using domain::Position;

    void Game::newGame()
    {
        //Create Checkers. We play on the black tiles & top-left tile is white (0,0)
        //Create Black Checkers
        for( int i = 0; i < (Board::kNumberOfColumns/2 - 1) ; i++ )
        {
            for( int j = ((i+1)%2); j < Board::kNumberOfRows; j+=2 )
            {
                CheckerPtr lChecker = std::make_shared<Checker>( Position( i, j ), Checker::Team::Black );
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
