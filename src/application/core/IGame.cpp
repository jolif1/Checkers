#include "IGame.h"


namespace application::core
{
    void IGame::addObserver( GameObserver* pObserver )
    {
        mObservers.push_back( pObserver );
    }

    void IGame::added( const domain::CheckerPtr& pChecker )
    {
        for( auto lObserver : mObservers )
            lObserver->onAdded( pChecker );
    }

    void IGame::moved( const domain::CheckerPtr& pChecker, const domain::Position& pOldPos )
    {
        for( auto lObserver : mObservers )
            lObserver->onMoved( pChecker, pOldPos );
    }

    void IGame::removed( const domain::CheckerPtr& pChecker )
    {
        for( auto lObserver : mObservers )
            lObserver->onRemoved( pChecker );
    }
}
