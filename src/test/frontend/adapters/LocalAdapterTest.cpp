#include <frontend/adapters/LocalAdapter.h>
#include "gtest/gtest.h"
#include <test/frontend/IFrontendMock.h>

namespace frontend::adapters::test {
    using domain::Checker;
    using domain::CheckerPtr;
    using domain::Position;
    using frontend::adapters::LocalAdapter;
    using frontend::adapters::LocalAdapterPtr;
    using frontend::test::IFrontendMock;
    using testing::Test;

    class LocalAdapterTest : public Test
    {
    protected:
        void SetUp()
        {
            mMockFrontend = std::make_shared<IFrontendMock>();
            mLocalAdapter = std::make_shared<LocalAdapter>( mMockFrontend );
            mMockPtr = std::dynamic_pointer_cast<IFrontendMock>(mMockFrontend).get();
        }

        IFrontendMock*  mMockPtr;
        IFrontendPtr    mMockFrontend;
        LocalAdapterPtr mLocalAdapter;
    };

    TEST_F(LocalAdapterTest, newgame)
    {
        std::set<Position> lInitBlackCheckersPositions {
            Position( 0, 1 ),
            Position( 0, 3 ),
            Position( 0, 5 ),
            Position( 0, 7 ),
            Position( 0, 9 ),
            Position( 1, 0 ),
            Position( 1, 2 ),
            Position( 1, 4 ),
            Position( 1, 6 ),
            Position( 1, 8 ),
            Position( 2, 1 ),
            Position( 2, 3 ),
            Position( 2, 5 ),
            Position( 2, 7 ),
            Position( 2, 9 )
        };

        std::set<Position> lBlackCheckersPositions;

        for( int i=0; i<15; i++ )
        {
            EXPECT_CALL(*mMockPtr, add).WillRepeatedly( [&lBlackCheckersPositions](const CheckerPtr& ptr){lBlackCheckersPositions.insert(ptr->getPosition());} );
        }

        mLocalAdapter->newGame();

        ASSERT_EQ( lInitBlackCheckersPositions, lBlackCheckersPositions );
    }
}
