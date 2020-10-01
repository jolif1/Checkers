#pragma once

#include <QDialog>
#include "ui_SelectMissionPlan.h"

namespace frontend::gui
{
    class SelectMissionPlan : public QDialog
    {
    public:
        SelectMissionPlan( QWidget* parent = nullptr, QAbstractItemModel* pModel );

    private:
        std::shared_ptr<Ui::SelectMissionPlan> ui;
    };
}
