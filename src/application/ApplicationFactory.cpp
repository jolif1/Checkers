#include "ApplicationFactory.h"

#include <application/adapters/LocalAdapter.h>
#include <application/core/Game.h>
#include <application/core/Lobby.h>
#include <domain/CheckerFactory.h>

namespace application::factory
{
    using adapters::LocalAdapter;
    using adapters::LocalAdapterPtr;
    using core::Game;
    using core::GamePtr;
    using core::Lobby;
    using core::LobbyPtr;
    using domain::CheckerFactory;
    using domain::CheckerFactoryPtr;

    application::adapters::LocalAdapterPtr ApplicationFactory::getLocalAdapter()
    {
        CheckerFactoryPtr   lFactory    { std::make_shared<CheckerFactory>() };
        GamePtr             lGame       { std::make_shared<Game>( lFactory ) };
        LobbyPtr            lLobby      { std::make_shared<Lobby>( lGame ) };
        LocalAdapterPtr     lAdapter    { std::make_shared<LocalAdapter>( lLobby ) };

        lGame->addObserver( lAdapter.get() );


        return lAdapter;
    }
}
