#include "MainWindow.h"

#include <QDebug>

namespace frontend::gui
{
    MainWindow::MainWindow (QAbstractTableModel* pBoardModel, QWidget *parent ) :
        QMainWindow(parent),
        ui {std::make_shared< Ui::MainWindow >() }
    {
        ui->setupUi(this);

        setBoardModel( pBoardModel );
        connectWidgets();
    }

    void MainWindow::connectWidgets()
    {

    }

    void MainWindow::setBoardModel( QAbstractTableModel* pBoardModel )
    {
        ui->mBoardTable->setModel( pBoardModel );
    }
}
