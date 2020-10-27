#include "ApplicationFactory.h"

#include <application/adapters/LocalAdapter.h>
#include <application/core/Game.h>
#include <application/core/Lobby.h>

namespace application::factory
{
    using adapters::LocalAdapter;
    using adapters::LocalAdapterPtr;
    using core::Game;
    using core::GamePtr;
    using core::Lobby;
    using core::LobbyPtr;

    application::adapters::LocalAdapterPtr ApplicationFactory::getLocalAdapter()
    {
        GamePtr         lGame       { std::make_shared<Game>() };
        LobbyPtr        lLobby      { std::make_shared<Lobby>( lGame ) };
        LocalAdapterPtr lAdapter    { std::make_shared<LocalAdapter>( lLobby ) };

        lGame->addObserver( lAdapter.get() );


        return lAdapter;
    }
}
