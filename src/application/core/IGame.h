#pragma once

#include <domain/Checker.h>
#include "GameObserver.h"
#include <list>

namespace application::core
{
    class  IGame
    {
    public:
        /**
         * @brief Constructors & Destructors
         */
        ///@{
        IGame()             = default;
        virtual ~IGame()    = default;
        ///@}

        /**
         * @brief   Add a game observer. It will be notified whenever something important happens in the game
         *          (adding a piece, moving a piece, ... )
         */
        void addObserver( GameObserver* pObserver );

        /**
         * @brief Game-related functionnality
         * TODO: should this really be public ?
         */
        ///@{
        void added( const domain::CheckerPtr& pChecker );
        void moved( const domain::CheckerPtr& pChecker, const domain::Position& pNewPos );
        void removed( const domain::CheckerPtr& pChecker );
        ///@}

    private:
        std::list<GameObserver*> mObservers;

    };
}
