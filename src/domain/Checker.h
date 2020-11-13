#pragma once

#include "Position.h"
#include <memory>
#include <map>

namespace domain
{
    class Checker
    {
    public:
        enum class Team { White, Black };
        enum class Rank { Peon, King };

        Checker( const Position& pPos, const Team& pTeam );

        /**
         * @brief Getters & Setters
         */
        ///@{
        Team        getTeam()       const { return mTeam; }
        Position    getPosition()   const { return mPosition; }
        Rank        getRank()       const { return mRank; }

        void        setRank( Rank pRank ) { mRank = pRank; }
        ///@}

    private:
        Position    mPosition   ;
        Team        mTeam       ;
        Rank        mRank       { Rank::Peon };
    };

    typedef std::shared_ptr< Checker > CheckerPtr;
    typedef std::map<domain::Position, domain::CheckerPtr> IndexedCheckers;

    bool operator==( const CheckerPtr& lhs, const CheckerPtr& rhs );
}
