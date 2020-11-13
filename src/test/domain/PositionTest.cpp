#include <domain/Position.h>
#include "gtest/gtest.h"

namespace domain::test
{
    using testing::Test;

    class PositionTest : public Test
    {
    protected:
        void SetUp()
        {

        }
    };

    TEST_F( PositionTest, constructors_and_getters )
    {
        int lx {42};
        int ly {38};

        // Test standard constructor
        Position lPos { lx, ly };

        EXPECT_EQ( lx, lPos.getRow() );
        EXPECT_EQ( ly, lPos.getCol() );

        // Test copy constructor
        Position lOtherPos( lPos );

        EXPECT_EQ( lx, lOtherPos.getRow() );
        EXPECT_EQ( ly, lOtherPos.getCol() );
    }

    TEST_F( PositionTest, comparison_operators )
    {
        int lBigX   { 42 };
        int lBigY   { 58 };
        int lSmallX { lBigX - 1 };
        int lSmallY { lBigY - 1 };

        Position lPos       { lBigX, lBigY };
        Position lSamePos   { lPos };
        Position lDiffXPos  { lSmallX, lBigY };
        Position lDiffYPos  { lBigX, lSmallY };
        Position lOtherPos  { lSmallX, lSmallY };

        // Test == operator
        EXPECT_TRUE( lPos == lSamePos );
        EXPECT_FALSE( lPos == lDiffXPos );
        EXPECT_FALSE( lPos == lDiffYPos );
        EXPECT_FALSE( lPos == lOtherPos );

        // Test != operator
        EXPECT_FALSE( lPos != lSamePos );
        EXPECT_TRUE( lPos != lDiffXPos );
        EXPECT_TRUE( lPos != lDiffYPos );
        EXPECT_TRUE( lPos != lOtherPos );

        // Test < operator
        Position l1(0,0);
        Position l2(0,0);
        Position l3(0,1);
        Position l4(1,0);
        Position l5(1,1);

        EXPECT_FALSE( l1 < l2 );    // if equal, not <
        EXPECT_TRUE( l1 < l3 );
        EXPECT_FALSE( l3 < l1 );
        EXPECT_TRUE( l1 < l4 );
        EXPECT_FALSE( l4 < l1 );
        EXPECT_TRUE( l1 < l5 );
        EXPECT_FALSE( l5 < l1 );

        std::set<Position> lOrdering { l5, l4, l3, l2 };

        auto it = lOrdering.begin();

        EXPECT_EQ( *it, l2 );
        it++;
        EXPECT_EQ( *it, l3 );
        it++;
        EXPECT_EQ( *it, l4 );
        it++;
        EXPECT_EQ( *it, l5 );
    }

    TEST_F( PositionTest, operator_minus )
    {
        Position Pos1 { 5, 8 };
        Position Pos2 { 3, 2 };
        Position Pos3 { Pos1 - Pos2 };

        ASSERT_EQ( Pos3.getRow(), 2 );
        ASSERT_EQ( Pos3.getCol(), 6 );
    }
}
