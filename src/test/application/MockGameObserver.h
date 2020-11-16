#pragma once

#include <application/core/GameObserver.h>
#include <gmock/gmock.h>

namespace application::core::test
{
    using namespace testing;

    class MockGameObserver : public application::core::GameObserver
    {
    public:
        MOCK_METHOD1( onAdded,      void ( const domain::CheckerPtr& pChecker ) );
        MOCK_METHOD2( onMoved,      void ( const domain::CheckerPtr& pChecker, const domain::Position& pNewPos ) );
        MOCK_METHOD1( onRemoved,    void ( const domain::CheckerPtr& pChecker ) );
    };
}
