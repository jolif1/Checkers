#include "MainWindow.h"

#include <QDebug>

namespace frontend::gui
{
    MainWindow::MainWindow (QAbstractTableModel* pBoardModel, QWidget *parent ) :
        QMainWindow(parent),
        ui {std::make_shared< Ui::MainWindow >() }
    {
        ui->setupUi(this);

        ui->mBoardTable->setModel( pBoardModel );
        connectWidgets();
    }

    void MainWindow::connectWidgets()
    {

    }
}
