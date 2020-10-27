#include "LocalAdapter.h"

#include <cassert>

namespace application::adapters
{
    LocalAdapter::LocalAdapter( const core::LobbyPtr& pLobby ) :
        mLobby( pLobby )
    {

    }

    void LocalAdapter::addAdapter( const communication::IAdapterPtr& pAdapter )
    {
        mAdapter = pAdapter;
    }

    void LocalAdapter::add( const domain::CheckerPtr& pChecker )
    {
        assert(false);
    }

    void LocalAdapter::move( const domain::CheckerPtr& pChecker, const domain::Position& pNewPos )
    {
        assert(false);
    }

    void LocalAdapter::requestMove( const domain::CheckerPtr& pChecker, const domain::Position& pNewPos )
    {

    }

    void LocalAdapter::remove( const domain::CheckerPtr& pChecker )
    {

    }

    void LocalAdapter::newGame()
    {
        mLobby->getGame()->newGame();
    }

    void LocalAdapter::onAdded( const domain::CheckerPtr& pChecker )
    {
        mAdapter->add( pChecker );
    }

    void LocalAdapter::onMoved( const domain::CheckerPtr& pChecker, const domain::Position& pNewPos )
    {
        mAdapter->move( pChecker, pNewPos );
    }

    void LocalAdapter::onRemoved( const domain::CheckerPtr& pChecker )
    {
        mAdapter->remove( pChecker );
    }
}
