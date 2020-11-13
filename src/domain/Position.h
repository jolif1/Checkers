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
        int getRow() const { return mRow; }
        int getCol() const { return mCol; }
        ///@}

    private:
        int mRow;
        int mCol;
    };

    bool operator==( const domain::Position& lhs, const domain::Position& rhs );
    bool operator!=( const domain::Position& lhs, const domain::Position& rhs );
    bool operator<( const domain::Position& lhs, const domain::Position& rhs );
    Position operator-( const domain::Position& lhs, const domain::Position& rhs );
    Position operator+( const domain::Position& lhs, const domain::Position& rhs );
}
