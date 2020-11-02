#pragma once

#include "Checker.h"

namespace domain
{
    class CheckerFactory
    {
    public:
        virtual CheckerPtr createChecker( const Position& pPos, Checker::Team pTeam );

    private:

    };

    typedef std::shared_ptr<CheckerFactory> CheckerFactoryPtr;
}
