#pragma once

#include <domain/CheckerFactory.h>
#include <gmock/gmock.h>

namespace domain::test {

    class MockFactory : public CheckerFactory
    {
    public:
        MOCK_METHOD2( createChecker, CheckerPtr( const Position&, Checker::Team ) );

        static std::set<CheckerPtr> get5x5Checkers()
        {
            std::set<CheckerPtr> lExpecte5x5dCheckers
            {
                std::make_shared<Checker>( Position( 0, 1 ), Checker::Team::Black ),
                std::make_shared<Checker>( Position( 0, 3 ), Checker::Team::Black ),
                std::make_shared<Checker>( Position( 0, 5 ), Checker::Team::Black ),
                std::make_shared<Checker>( Position( 0, 7 ), Checker::Team::Black ),
                std::make_shared<Checker>( Position( 1, 0 ), Checker::Team::Black ),
                std::make_shared<Checker>( Position( 1, 2 ), Checker::Team::Black ),
                std::make_shared<Checker>( Position( 1, 4 ), Checker::Team::Black ),
                std::make_shared<Checker>( Position( 1, 6 ), Checker::Team::Black ),
                std::make_shared<Checker>( Position( 2, 1 ), Checker::Team::Black ),
                std::make_shared<Checker>( Position( 2, 3 ), Checker::Team::Black ),
                std::make_shared<Checker>( Position( 2, 5 ), Checker::Team::Black ),
                std::make_shared<Checker>( Position( 2, 7 ), Checker::Team::Black ),
                std::make_shared<Checker>( Position( 5, 0 ), Checker::Team::White ),
                std::make_shared<Checker>( Position( 5, 2 ), Checker::Team::White ),
                std::make_shared<Checker>( Position( 5, 4 ), Checker::Team::White ),
                std::make_shared<Checker>( Position( 5, 6 ), Checker::Team::White ),
                std::make_shared<Checker>( Position( 6, 1 ), Checker::Team::White ),
                std::make_shared<Checker>( Position( 6, 3 ), Checker::Team::White ),
                std::make_shared<Checker>( Position( 6, 5 ), Checker::Team::White ),
                std::make_shared<Checker>( Position( 6, 7 ), Checker::Team::White ),
                std::make_shared<Checker>( Position( 7, 0 ), Checker::Team::White ),
                std::make_shared<Checker>( Position( 7, 2 ), Checker::Team::White ),
                std::make_shared<Checker>( Position( 7, 4 ), Checker::Team::White ),
                std::make_shared<Checker>( Position( 7, 6 ), Checker::Team::White )
            };

            return lExpecte5x5dCheckers;
        }
    };

     typedef std::shared_ptr<MockFactory> MockFactoryPtr;
}
