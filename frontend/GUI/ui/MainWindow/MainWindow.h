#pragma once

#include <QMainWindow>
#include "ui_mainwindow.h"

namespace view::gui
{
    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow() = default;

    signals:
        void selectMissionPlanClicked();

    private:
        std::shared_ptr<Ui::MainWindow> ui;

        void connectWidgets();
    };
}

