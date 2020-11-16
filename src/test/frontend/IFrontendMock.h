#pragma once

#include <frontend/IFrontend.h>
#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace frontend::test
{
    class IFrontendMock : public IFrontend
    {
    public:
        MOCK_METHOD0( show  , void() );
        MOCK_METHOD1( add   , void( const domain::CheckerPtr& ) );
        MOCK_METHOD2( move  , void( const domain::CheckerPtr&, const domain::Position& ) );
        MOCK_METHOD1( remove, void( const domain::CheckerPtr& ) );
    };
}
