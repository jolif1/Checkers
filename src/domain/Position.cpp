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
        return ( ( lhs.getX() == rhs.getX() ) && ( lhs.getY() == rhs.getY() ) );
    }

    bool operator!=( const domain::Position& lhs, const domain::Position& rhs )
    {
        return !operator==(lhs, rhs);
    }

    bool operator<( const domain::Position& lhs, const domain::Position& rhs )
    {
        bool lRet {false};

        if( lhs.getX() < rhs.getX() ) //x has priority, ie (0,12) < (1,0)
            lRet = true;
        else if( lhs.getX() == rhs.getX() )
        {
            if( lhs.getY() < rhs.getY() )
                lRet = true;
        }

        return lRet;
    }
}
