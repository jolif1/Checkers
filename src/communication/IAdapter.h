#pragma once

#include <domain/Checker.h>

namespace communication
{
    class IAdapter
    {
    public:
        virtual void add( const domain::CheckerPtr& pChecker )      = 0;
        virtual void move( const domain::CheckerPtr& pChecker, const domain::Position& pNewPos )     = 0;
        virtual void remove( const domain::CheckerPtr& pChecker )   = 0;

        virtual void newGame() = 0;
    };

    typedef std::shared_ptr<IAdapter> IAdapterPtr;
}
