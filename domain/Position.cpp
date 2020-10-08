#include "Position.h"

namespace domain
{
    Position::Position( int x, int y )
        : mX{ x }, mY{ y }
    {

    }

    Position::Position( const Position& pOther )
        : Position( pOther.getX(), pOther.getY() )
    {

    }

    bool operator==( const domain::Position& lhs, const domain::Position& rhs )
    {
        return ( ( lhs.getX() == rhs.getX() ) && ( lhs.getY() && rhs.getY() ) );
    }

    bool operator<( const domain::Position& lhs, const domain::Position& rhs )
    {
        return ( ( lhs.getX() < rhs.getX() ) || ( lhs.getY() < lhs.getY() ) );
    }
}
