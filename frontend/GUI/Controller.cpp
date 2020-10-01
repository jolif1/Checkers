#include "Controller.h"

#include <QDebug>

namespace frontend::gui
{
    Controller::Controller( std::shared_ptr<MainWindow>& pMainWindow ) :
        mMainWindow { pMainWindow }
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

