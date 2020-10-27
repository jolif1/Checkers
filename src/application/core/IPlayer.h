#pragma once

#include "Game.h"
#include "GameObserver.h"

namespace application::core
{
    class IPlayer : public GameObserver
    {
    public:
        /**
         * @brief GameObserver functionnality
         */
        ///@{
        void onAdded( const domain::CheckerPtr& pChecker )                                  override;
        void onMoved( const domain::CheckerPtr& pChecker, const domain::Position& pNewPos ) override;
        void onRemoved( const domain::CheckerPtr& pChecker )                                override;
        ///@}

    private:
        GamePtr mGame;
    };
}
