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

    void LocalAdapter::requestMove( const domain::CheckerPtr& pChecker, const domain::Position& pNewPos )
    {
        /* Called from frontend --> going to the app layer */
        mAppAdapter->requestMove( pChecker, pNewPos );
    }

    void LocalAdapter::move( const domain::CheckerPtr& pChecker, const domain::Position& pNewPos )
    {
        /* Called from the app or comm layer --> going to the frontend */
    }

    void LocalAdapter::remove( [[maybe_unused]] const domain::CheckerPtr& pChecker )
    {
        /* frontend won't ever call this */
    }

    void LocalAdapter::newGame()
    {
        mAppAdapter->newGame();
    }
}
