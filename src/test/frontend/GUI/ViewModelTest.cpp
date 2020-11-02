#include <frontend/GUI/model/ViewModel.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

namespace test::frontend::gui {
    using domain::Checker;
    using domain::CheckerPtr;
    using domain::Position;
    using ::frontend::gui::ViewModel;
    using testing::Test;

    class ViewModelTest : public Test
    {
    protected:
        void SetUp() override
        {
            mSelectionModel = std::make_shared<QItemSelectionModel>(&mModel);
            mModel.setSelectionModel( mSelectionModel.get() );
        }

        ViewModel                               mModel;
        std::shared_ptr<QItemSelectionModel>    mSelectionModel;
    };

    TEST_F(ViewModelTest, HelloTest)
    {
        ASSERT_TRUE(true);
    }

    TEST_F(ViewModelTest, add_checker_and_data )
    {
        CheckerPtr lChecker1 { std::make_shared<Checker>( Position{1,1}, Checker::Team::Black ) };
        CheckerPtr lChecker2 { std::make_shared<Checker>( Position{2,2}, Checker::Team::White ) };

        mModel.addChecker( lChecker1 );
        mModel.addChecker( lChecker2 );

        EXPECT_EQ( mModel.data( mModel.index(1, 1), Qt::DisplayRole ).toInt(), Qt::black );
        EXPECT_EQ( mModel.data( mModel.index(2, 2), Qt::DisplayRole ).toInt(), Qt::white );
        EXPECT_FALSE( mModel.data( mModel.index(1, 2), Qt::DisplayRole ).isValid() );
    }

    TEST_F(ViewModelTest, selection_test)
    {
        int         lRequestMoveCallCount           { 0 };
        int         lRequestPossibleMovesCallCount  { 0 };
        CheckerPtr  lChecker                        { std::make_shared<Checker>( Position{1,1}, Checker::Team::Black ) };

        QObject::connect( &mModel, &ViewModel::requestMove, [&lRequestMoveCallCount](const domain::CheckerPtr& pChecker, const domain::Position& pNewPos) {
            lRequestMoveCallCount++;
        });

        QObject::connect( &mModel, &ViewModel::requestPossibleMoves, [&lRequestPossibleMovesCallCount](const domain::Position& pNewPos) {
            lRequestPossibleMovesCallCount++;
        });

        mModel.addChecker( lChecker );

        // Simulate some clicks on empty tiles --> nothing should happen
        QModelIndex lCurrent;
        QModelIndex lPrevious;

        for( int i = 0; i < 6 ; i++)
        {
            lPrevious   = lCurrent;
            lCurrent    = mModel.index( 2, i );

            mSelectionModel->currentChanged( lCurrent, lPrevious );
            ASSERT_EQ( lRequestPossibleMovesCallCount, 0 );
        }

        // Click on the checker --> possible moves
        mSelectionModel->currentChanged( mModel.index(1,1), lCurrent );
        ASSERT_EQ( lRequestPossibleMovesCallCount, 1 );
    }
}
