#pragma once

#include <QMainWindow>
#include "ui_MainWindow.h"

namespace frontend::gui
{
    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        MainWindow( QAbstractTableModel* pBoardModel, QWidget *parent = nullptr );
        ~MainWindow() = default;

        QItemSelectionModel* getSelectionModel() { return ui->mBoardTable->selectionModel(); }

    signals:

    private:
        std::shared_ptr<Ui::MainWindow>         ui;

        void connectWidgets();
    };
}

