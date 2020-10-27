#pragma once

#include "application/core/Lobby.h"
#include <communication/IAdapter.h>
#include <application/core/GameObserver.h>

namespace application::adapters
{
    /* Maybe this class should implement the IPlayer class ? */
    class LocalAdapter : public communication::IAdapter, public core::GameObserver
    {
    public:
        LocalAdapter() = delete;
        LocalAdapter( const core::LobbyPtr& pLobby );

        void addAdapter( const communication::IAdapterPtr& pAdapter );

        /**
         * @brief IAdapter functionnality
         */
        ///@{
        void add( const domain::CheckerPtr& pChecker )                                          override;
        void move( const domain::CheckerPtr& pChecker, const domain::Position& pNewPos )        override;
        void newGame()                                                                          override;
        void remove( const domain::CheckerPtr& pChecker )                                       override;
        void requestMove( const domain::CheckerPtr& pChecker, const domain::Position& pNewPos ) override;
        ///@}

        /**
         * @brief GameObserver functionnality
         */
        ///@{
        void onAdded( const domain::CheckerPtr& pChecker )                                  override;
        void onMoved( const domain::CheckerPtr& pChecker, const domain::Position& pNewPos ) override;
        void onRemoved( const domain::CheckerPtr& pChecker )                                override;
        ///@}

    private:
        core::LobbyPtr              mLobby;
        communication::IAdapterPtr  mAdapter;
    };

    typedef std::shared_ptr<LocalAdapter> LocalAdapterPtr;
}
