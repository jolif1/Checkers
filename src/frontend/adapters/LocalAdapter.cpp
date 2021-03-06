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

    void LocalAdapter::add( const domain::CheckerPtr& pChecker )
    {
        mFrontend->add( pChecker );
    }

    void LocalAdapter::requestMove( const domain::Position& pOldPos, const domain::Position& pNewPos )
    {
        /* Called from frontend --> going to the app layer */
        mAppAdapter->requestMove( pOldPos, pNewPos );
    }

    void LocalAdapter::move( const domain::CheckerPtr& pChecker, const domain::Position& pOldPos )
    {
        mFrontend->move( pChecker, pOldPos );
    }

    void LocalAdapter::remove( const domain::CheckerPtr& pChecker )
    {
        /* frontend won't ever call this */
        mFrontend->remove( pChecker );
    }

    void LocalAdapter::newGame()
    {
        mAppAdapter->newGame();
    }
}
