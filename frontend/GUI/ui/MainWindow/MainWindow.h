#pragma once

#include <QMainWindow>
#include "ui_mainwindow.h"

namespace frontend::gui
{
    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        MainWindow( QAbstractTableModel* pBoardModel, QWidget *parent = nullptr );
        ~MainWindow() = default;

    signals:

    private:
        std::shared_ptr<Ui::MainWindow>         ui;

        void connectWidgets();
        void setBoardModel( QAbstractTableModel* pBoardModel );
    };
}

