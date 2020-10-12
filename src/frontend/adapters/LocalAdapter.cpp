#include "LocalAdapter.h"

namespace frontend::adapters
{
    using domain::Position;
    using domain::Checker;
    using domain::CheckerPtr;

    LocalAdapter::LocalAdapter( const IFrontendPtr& pFrontend ) :
        mFrontend( pFrontend )
    {

    }

    void LocalAdapter::add( [[maybe_unused]] const domain::CheckerPtr& pChecker )
    {
        /* frontend won't ever call this */
    }

    void LocalAdapter::move( const domain::CheckerPtr& pChecker, const domain::Position& pNewPos )
    {

    }

    void LocalAdapter::remove( [[maybe_unused]] const domain::CheckerPtr& pChecker )
    {
        /* frontend won't ever call this */
    }

    void LocalAdapter::newGame()
    {
        //Create Checkers. We play on the black tiles & top-left tile is white (0,0)
        //Create Black Checkers
        for( int i = 0; i < 3 ; i++ )
        {
            for( int j = ((i+1)%2); j < 10; j+=2 )
            {
                CheckerPtr lChecker = std::make_shared<Checker>( Position( i, j ), Checker::Team::Black );
                mFrontend->add( lChecker );
            }
        }
    }
}
