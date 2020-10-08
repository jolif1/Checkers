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
    }

    void Controller::connectWidgets()
    {
    }
}

