#include "Controller.h"

#include <QDebug>

namespace frontend::gui
{
    Controller::Controller( std::shared_ptr<MainWindow>& pMainWindow, std::shared_ptr<ViewModel>& pModel ) :
        mMainWindow { pMainWindow }, mModel( pModel )
    {
        connectWidgets();
    }

    void Controller::show()
    {
        mMainWindow->show();
        this->requestNewGame();
    }

    void Controller::add( const domain::CheckerPtr& pChecker )
    {
        mModel->addChecker( pChecker );
    }

    void Controller::connectWidgets()
    {
        QObject::connect( mModel.get(), &ViewModel::requestMove, [this](const domain::CheckerPtr& t1, const domain::Position& t2){
           this->requestMove( t1, t2 );
        });
    }
}

