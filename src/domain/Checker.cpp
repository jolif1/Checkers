#include "Checker.h"

namespace domain
{
    Checker::Checker( const Position& pPos, const Team& pTeam )
        : mPosition( pPos ), mTeam( pTeam )
    {

    }

    bool operator==( const CheckerPtr& lhs, const CheckerPtr& rhs )
    {
       return ( lhs->getPosition() == rhs->getPosition() ) && ( lhs->getTeam() == rhs->getTeam() );
    }
}
