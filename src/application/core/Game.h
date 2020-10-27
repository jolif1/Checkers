#pragma once

#include "IGame.h"

namespace application::core
{
    class Game : public IGame
    {
    public:
        void newGame();
        void requestMove(  const domain::CheckerPtr& pChecker, const domain::Position& pNewPos );

    private:
        domain::IndexedCheckers mCheckers;

        void validateMove( const domain::CheckerPtr& pChecker, const domain::Position& pNewPos );
    };

    typedef std::shared_ptr<Game> GamePtr;
}
