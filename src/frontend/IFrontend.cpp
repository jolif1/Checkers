#include "IFrontend.h"

namespace frontend
{
    void IFrontend::requestMove( const domain::Position& pOldPos, const domain::Position& pNewPos )
    {
        mAdapter->requestMove( pOldPos, pNewPos );
    }

    void IFrontend::requestNewGame()
    {
        mAdapter->newGame();
    }
}
