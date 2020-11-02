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
}
