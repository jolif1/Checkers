#pragma once
#include <communication/IAdapter.h>

namespace communication
{
    class HTTP
    {
    public:
        void sendAddRequest();
        void sendMoveRequest();
        void sendRemoveRequest();
        void sendNewGameRequest();
    };

    class HTTPAdapter : public IAdapter
    {
    public:
        HTTPAdapter( const std::string& pTargetUrl );

        /* Sample code to illustrate the adapter concept */
        void add( const domain::CheckerPtr& pChecker ) override { mTransmitter.sendAddRequest() };
        void move( const domain::CheckerPtr& pChecker ) override { mTransmitter.sendMoveRequest() };
        void remove( const domain::CheckerPtr& pChecker ) override { mTransmitter.sendRemoveRequest() };

        void newGame() override { mTransmitter.sendNewGameRequest(); }


    private:
      HTTP mTransmitter;
    };
}
