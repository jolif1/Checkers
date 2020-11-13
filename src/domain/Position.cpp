#include "Position.h"

namespace domain
{
    Position::Position( int x, int y )
        : mRow{ x }, mCol{ y }
    {

    }

    Position::Position( const Position& pOther )
        : Position( pOther.getRow(), pOther.getCol() )
    {

    }

    bool operator==( const domain::Position& lhs, const domain::Position& rhs )
    {
        return ( ( lhs.getRow() == rhs.getRow() ) && ( lhs.getCol() == rhs.getCol() ) );
    }

    bool operator!=( const domain::Position& lhs, const domain::Position& rhs )
    {
        return !operator==(lhs, rhs);
    }

    bool operator<( const domain::Position& lhs, const domain::Position& rhs )
    {
        bool lRet {false};

        if( lhs.getRow() < rhs.getRow() ) //x has priority, ie (0,12) < (1,0)
            lRet = true;
        else if( lhs.getRow() == rhs.getRow() )
        {
            if( lhs.getCol() < rhs.getCol() )
                lRet = true;
        }

        return lRet;
    }

    Position operator-( const domain::Position& lhs, const domain::Position& rhs )
    {
        return Position( lhs.getRow() - rhs.getRow(), lhs.getCol() - rhs.getCol() );
    }

    Position operator+( const domain::Position& lhs, const domain::Position& rhs )
    {
        return Position( lhs.getRow() + rhs.getRow(), lhs.getCol() + rhs.getCol() );
    }
}
