#pragma once

#include <communication/IAdapter.h>
#include <frontend/IFrontend.h>

namespace frontend::adapters
{
    class LocalAdapter : public communication::IAdapter
    {
    public:
        LocalAdapter( const IFrontendPtr& pFrontend );

        void add( const domain::CheckerPtr& pChecker )      override;
        void move( const domain::CheckerPtr& pChecker, const domain::Position& pNewPos )     override;
        void remove( const domain::CheckerPtr& pChecker )   override;

        void newGame() override;

    private:
        IFrontendPtr mFrontend;

    };

    typedef std::shared_ptr<LocalAdapter> LocalAdapterPtr;
}
