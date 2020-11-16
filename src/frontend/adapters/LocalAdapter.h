#pragma once

#include <communication/IAdapter.h>
#include <frontend/IFrontend.h>

namespace frontend::adapters
{
    /*Is this class fully useless ? we could directly connect the IFrontend to the application adapter... */
    class LocalAdapter : public communication::IAdapter
    {
    public:
        LocalAdapter( const IFrontendPtr& pFrontend );

        void add( const domain::CheckerPtr& pChecker )      override;
        void requestMove( const domain::Position& pOldPos, const domain::Position& pNewPos )     override;
        void move( const domain::CheckerPtr& pChecker, const domain::Position& pOldPos )  override;
        void remove( const domain::CheckerPtr& pChecker )   override;

        void newGame() override;

    private:
        IFrontendPtr                mFrontend;
        communication::IAdapterPtr  mAppAdapter;

    };

    typedef std::shared_ptr<LocalAdapter> LocalAdapterPtr;
}
