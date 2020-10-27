#pragma once

#include <application/adapters/LocalAdapter.h>

namespace application::factory
{
    class ApplicationFactory
    {
    public:
        application::adapters::LocalAdapterPtr getLocalAdapter();
    };
}
