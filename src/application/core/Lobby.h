#pragma once

#include <application/core/Game.h>
#include <memory>

namespace application::core
{
    class Lobby
    {
    public:
        Lobby( const GamePtr& pGame );

        GamePtr getGame() const { return mGame; }

    private:
        GamePtr mGame;
    };

    typedef std::shared_ptr<Lobby> LobbyPtr;
}
