#include "CheckerFactory.h"

namespace domain
{
    CheckerPtr CheckerFactory::createChecker( const Position& pPos, Checker::Team pTeam )
    {
        return std::make_shared<Checker>( pPos, pTeam );
    }
}
