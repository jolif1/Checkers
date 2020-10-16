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
        std::vector<CheckerPtr> lInitBlackCheckers {
            std::make_shared<Checker>( Position( 0, 1 ), Checker::Team::Black ),
            std::make_shared<Checker>( Position( 0, 3 ), Checker::Team::Black ),
            std::make_shared<Checker>( Position( 0, 5 ), Checker::Team::Black ),
            std::make_shared<Checker>( Position( 0, 7 ), Checker::Team::Black ),
            std::make_shared<Checker>( Position( 0, 9 ), Checker::Team::Black ),
            std::make_shared<Checker>( Position( 1, 0 ), Checker::Team::Black ),
            std::make_shared<Checker>( Position( 1, 2 ), Checker::Team::Black ),
            std::make_shared<Checker>( Position( 1, 4 ), Checker::Team::Black ),
            std::make_shared<Checker>( Position( 1, 6 ), Checker::Team::Black ),
            std::make_shared<Checker>( Position( 1, 8 ), Checker::Team::Black ),
            std::make_shared<Checker>( Position( 2, 1 ), Checker::Team::Black ),
            std::make_shared<Checker>( Position( 2, 3 ), Checker::Team::Black ),
            std::make_shared<Checker>( Position( 2, 5 ), Checker::Team::Black ),
            std::make_shared<Checker>( Position( 2, 7 ), Checker::Team::Black ),
            std::make_shared<Checker>( Position( 2, 9 ), Checker::Team::Black )
        };

        for( auto it = lInitBlackCheckers.begin(); it != lInitBlackCheckers.end(); it++ )
        {
            EXPECT_CALL(*mMockPtr, add( *it ));
        }

        mLocalAdapter->newGame();
    }
}
