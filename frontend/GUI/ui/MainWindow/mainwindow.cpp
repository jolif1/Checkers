#include "MainWindow.h"

#include <QDebug>

namespace frontend::gui
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

    }
}
