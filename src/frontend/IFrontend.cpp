#include "IFrontend.h"

namespace frontend
{
    void IFrontend::requestMove( const domain::CheckerPtr& pChecker, const domain::Position& pNewPos )
    {
        mAdapter->requestMove( pChecker, pNewPos );
    }

    void IFrontend::requestNewGame()
    {
        mAdapter->newGame();
    }
}
