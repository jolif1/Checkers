#pragma once

namespace domain
{
    class Position
    {
    public:
        Position( int x, int y );
        Position( const Position& pOther );

        /**
         * @brief Accessors
         */
        ///@{
        int getX() const { return mX; }
        int getY() const { return mY; }
        ///@}

    private:
        int mX;
        int mY;
    };

    bool operator==( const domain::Position& lhs, const domain::Position& rhs );
    bool operator!=( const domain::Position& lhs, const domain::Position& rhs );
    bool operator<( const domain::Position& lhs, const domain::Position& rhs );
}
