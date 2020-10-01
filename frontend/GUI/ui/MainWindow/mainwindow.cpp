#include "MainWindow.h"

#include <QDebug>

namespace view::gui
{
    MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui {std::make_shared< Ui::MainWindow >() }
    {
        ui->setupUi(this);

        connectWidgets();
    }

    void MainWindow::connectWidgets()
    {
        QObject::connect( ui->mSelectMPBtn, &QPushButton::clicked, [this](){ emit selectMissionPlanClicked(); } );
    }
}
