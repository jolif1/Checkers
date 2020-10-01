#include "Controller.h"

#include <QDebug>

namespace view::gui
{
    Controller::Controller() :
        mMainWindow     { std::make_shared<MainWindow>() },
        mSelectMpDialog { std::make_shared<SelectMissionPlan>( static_cast<QWidget*>( mMainWindow.get() ) ) }
    {
        connectWidgets();
    }

    void Controller::show()
    {
        mMainWindow->show();
    }

    void Controller::connectWidgets()
    {
        QObject::connect( mMainWindow.get(), &MainWindow::selectMissionPlanClicked, [this]() { launchSelectMpDialog(); } );
    }

    void Controller::launchSelectMpDialog()
    {
        qDebug() << "GUIView:: launchSelectMpDialog";
        mSelectMpDialog->exec();
    }
}

