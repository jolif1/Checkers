#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <application/core/Game.h>
#include <domain/CheckerFactory.h>
#include <test/application/MockGameObserver.h>
#include <test/domain/MockCheckerFactory.h>
#include <QObject>

namespace application::test
{
    using application::core::Game;
    using application::core::GamePtr;
    using application::core::test::MockGameObserver;
    using domain::Checker;
    using domain::CheckerPtr;
    using domain::CheckerFactory;
    using domain::CheckerFactoryPtr;
    using domain::Position;
    using domain::test::MockFactory;
    using domain::test::MockFactoryPtr;

    using namespace testing;

    class GameTest : public Test
    {
    protected:
        void SetUp() override
        {
            mMockFactory        = std::make_shared<MockFactory>();
            mFactory            = std::make_shared<CheckerFactory>();
            mUninitializedGame  = std::make_shared<Game>( mMockFactory );
            mGame               = std::make_shared<Game>( mFactory );

            mGame->newGame();
        }

        GamePtr                 mUninitializedGame;
        GamePtr                 mGame;
        MockFactoryPtr          mMockFactory;
        CheckerFactoryPtr       mFactory;

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

        mUninitializedGame->newGame();
    }

    TEST_F( GameTest, invalidMoves )
    {
        MockGameObserver mMockObserver;
        mGame->addObserver( &mMockObserver );

        EXPECT_CALL( mMockObserver, onMoved( _ , _ ) ).Times( 0 );

        // Try to move a checker onto another one
        mGame->requestMove( Position( 0, 1 ), Position( 1, 0 ) );

        // Try to move a checker outside of a diagonal
        mGame->requestMove( Position( 2, 1 ), Position( 3, 1 ) );

        // Try to jump over an allied checker
        mGame->requestMove( Position( 0, 1 ), Position( 2, 3 ) );
    }

    TEST_F( GameTest, validMoves )
    {
        MockGameObserver mMockObserver;
        mGame->addObserver( &mMockObserver );

        //Expect no checkers removed. Specific unit test covering that.
        EXPECT_CALL( mMockObserver, onRemoved( _ ) ).Times( 0 );

        // Valid move to an empty cell, black checker
        auto lChecker1  { std::make_shared<Checker>( Position( 3, 0 ), Checker::Team::Black ) };
        auto lOldPos1   { Position( 2,1 ) };

        EXPECT_CALL( mMockObserver, onMoved( lChecker1 , lOldPos1 ) ).Times(1);
        mGame->requestMove( Position(2,1), lChecker1->getPosition() );

        // Valid move to an empty cell, white checker
        auto lChecker2  { std::make_shared<Checker>( Position( 4, 1 ), Checker::Team::White ) };
        auto lOldPos2   { Position( 5,2 ) };

        EXPECT_CALL( mMockObserver, onMoved( lChecker2 , lOldPos2 ) ).Times(1);
        mGame->requestMove( Position(5,2), lChecker2->getPosition() );
    }

    TEST_F( GameTest, jumpMoves )
    {
//        (2,3,b) -> (3,2)
//        (5,2,w) -> (4,3)
//        3,2,b -> 4,1
//        4,3,w -> 3,4
//        JUMP 5,0,w -> 3,2 -> killed 4,1,b
//        JUMP 2,5,b -> 4,3 -> killed 3,4,w
        MockGameObserver mMockObserver;
        mGame->addObserver( &mMockObserver );

        mGame->requestMove( Position(2,3), Position(3,2) );


        // Valid move to an empty cell, black checker
        auto lChecker1  { std::make_shared<Checker>( Position( 3, 0 ), Checker::Team::Black ) };
        auto lOldPos1   { Position( 2,1 ) };

        EXPECT_CALL( mMockObserver, onMoved( lChecker1 , lOldPos1 ) ).Times(1);
        mGame->requestMove( Position( 2, 1 ), lChecker1->getPosition() );

        // Valid move to an empty cell, white checker
        auto lChecker2  { std::make_shared<Checker>( Position( 4, 1 ), Checker::Team::White ) };
        auto lOldPos2   { Position( 5,2 ) };

        EXPECT_CALL( mMockObserver, onMoved( lChecker2 , lOldPos2 ) ).Times(1);
        mGame->requestMove( Position( 5, 2 ), lChecker2->getPosition() );
    }
}
