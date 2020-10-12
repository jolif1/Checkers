#pragma once

#include <communication/IAdapter.h>

namespace frontend
{
    class IFrontend
    {
    public:
        virtual ~IFrontend() = default;

        /**
         * @brief This starts the Frontend.
         */
        virtual void show() = 0;

        /**
         * @brief Getters & Setters
         */
        ///@{
        void addAdapter( const communication::IAdapterPtr& pAdapter ) { mAdapter = pAdapter; }
        ///@}

        /**
         * @brief Game-related functionnality
         */
        ///@{
        virtual void add( const domain::CheckerPtr& pChecker ) = 0;
        ///@}

    protected:
        communication::IAdapterPtr mAdapter;

        void requestMove( const domain::CheckerPtr& pChecker, const domain::Position& pNewPos );
        void requestNewGame();

    private:

    };

    typedef std::shared_ptr<IFrontend> IFrontendPtr;
}
