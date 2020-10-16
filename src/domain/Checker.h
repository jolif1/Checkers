#pragma once

#include "Position.h"
#include <memory>

namespace domain
{
    class Checker
    {
    public:
        enum class Team
        {
            White,
            Black
        };

        Checker( const Position& pPos, const Team& pTeam );

        /**
         * @brief Accessors
         */
        ///@{
        Team        getTeam()       const { return mTeam; }
        Position    getPosition()   const { return mPosition; }
        ///@}

    private:
        Position    mPosition;
        Team        mTeam;
    };

    typedef std::shared_ptr< Checker > CheckerPtr;
    bool operator==( const CheckerPtr& lhs, const CheckerPtr& rhs );
}
