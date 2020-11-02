#pragma once

#include <domain/CheckerFactory.h>
#include "IGame.h"

namespace application::core
{
    class Game : public IGame
    {
    public:
        Game( const domain::CheckerFactoryPtr& pCheckerFactory );

        /**
         * @brief Game-related functionnality
         */
        ///@{
        void newGame();
        void requestMove(  const domain::CheckerPtr& pChecker, const domain::Position& pNewPos );
        ///@}

    private:
        domain::IndexedCheckers     mCheckers;
        domain::CheckerFactoryPtr   mCheckerFactory;

        void validateMove( const domain::CheckerPtr& pChecker, const domain::Position& pNewPos );
    };

    typedef std::shared_ptr<Game> GamePtr;
}
