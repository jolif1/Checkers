#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <application/core/Game.h>
#include <QObject>

namespace application::test
{
    using application::core::Game;
    using application::core::GamePtr;
    using domain::Checker;
    using domain::CheckerPtr;
    using domain::CheckerFactory;
    using domain::CheckerFactoryPtr;
    using domain::Position;

    using namespace testing;

    class MockFactory : public CheckerFactory
    {
    public:
        MOCK_METHOD2( createChecker, CheckerPtr( const Position&, Checker::Team ) );
    };

    typedef std::shared_ptr<MockFactory> MockFactoryPtr;

    class GameTest : public Test
    {
    protected:
        void SetUp() override
        {
            mFactory        = std::make_shared<MockFactory>();
            mGame           = std::make_shared<Game>( mFactory );
            mMockFactory    = std::static_pointer_cast<MockFactory>( mFactory ).get();
        }

        GamePtr                 mGame;
        CheckerFactoryPtr       mFactory;
        MockFactory*            mMockFactory;

        std::set<CheckerPtr>    mExpecte5x5dCheckers
        {
            std::make_shared<Checker>( Position( 0, 1 ), Checker::Team::Black ),
            std::make_shared<Checker>( Position( 0, 3 ), Checker::Team::Black ),
            std::make_shared<Checker>( Position( 0, 5 ), Checker::Team::Black ),
            std::make_shared<Checker>( Position( 0, 7 ), Checker::Team::Black ),
            std::make_shared<Checker>( Position( 1, 0 ), Checker::Team::Black ),
            std::make_shared<Checker>( Position( 1, 2 ), Checker::Team::Black ),
            std::make_shared<Checker>( Position( 1, 4 ), Checker::Team::Black ),
            std::make_shared<Checker>( Position( 1, 6 ), Checker::Team::Black ),
            std::make_shared<Checker>( Position( 2, 1 ), Checker::Team::Black ),
            std::make_shared<Checker>( Position( 2, 3 ), Checker::Team::Black ),
            std::make_shared<Checker>( Position( 2, 5 ), Checker::Team::Black ),
            std::make_shared<Checker>( Position( 2, 7 ), Checker::Team::Black ),
            std::make_shared<Checker>( Position( 5, 0 ), Checker::Team::White ),
            std::make_shared<Checker>( Position( 5, 2 ), Checker::Team::White ),
            std::make_shared<Checker>( Position( 5, 4 ), Checker::Team::White ),
            std::make_shared<Checker>( Position( 5, 6 ), Checker::Team::White ),
            std::make_shared<Checker>( Position( 6, 1 ), Checker::Team::White ),
            std::make_shared<Checker>( Position( 6, 3 ), Checker::Team::White ),
            std::make_shared<Checker>( Position( 6, 5 ), Checker::Team::White ),
            std::make_shared<Checker>( Position( 6, 7 ), Checker::Team::White ),
            std::make_shared<Checker>( Position( 7, 0 ), Checker::Team::White ),
            std::make_shared<Checker>( Position( 7, 2 ), Checker::Team::White ),
            std::make_shared<Checker>( Position( 7, 4 ), Checker::Team::White ),
            std::make_shared<Checker>( Position( 7, 6 ), Checker::Team::White )
        };
    };

    TEST_F( GameTest, helloTest )
    {
        ASSERT_TRUE( true );
    }

    TEST_F( GameTest, newgame_5x5 )
    {
        ASSERT_TRUE( !mExpecte5x5dCheckers.empty() );

        for( CheckerPtr lChecker : mExpecte5x5dCheckers )
            EXPECT_CALL( *mMockFactory, createChecker( lChecker->getPosition(), lChecker->getTeam() ) ).WillOnce( Return( lChecker ) );

        mGame->newGame();
    }

    TEST_F( GameTest, validMoves )
    {
        ASSERT_TRUE( !mExpecte5x5dCheckers.empty() );

        for( CheckerPtr lChecker : mExpecte5x5dCheckers )
            EXPECT_CALL( *mMockFactory, createChecker( lChecker->getPosition(), lChecker->getTeam() ) ).WillOnce( Return( lChecker ) );

        mGame->newGame();

        //Try to move a checker onto another one --> expect failure
        EXPECT_ANY_THROW( mGame->requestMove( std::make_shared<Checker>( Position( 2, 1 ), Checker::Team::Black ), Position( 2, 3 ) ) );
    }
}
