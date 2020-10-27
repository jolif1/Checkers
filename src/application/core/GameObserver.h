#pragma once

#include <domain/Checker.h>

namespace application::core
{
    class GameObserver
    {
    public:
        virtual void onAdded( const domain::CheckerPtr& pChecker ) = 0;
        virtual void onMoved( const domain::CheckerPtr& pChecker, const domain::Position& pNewPos ) = 0;
        virtual void onRemoved( const domain::CheckerPtr& pChecker ) = 0;
    };
}
