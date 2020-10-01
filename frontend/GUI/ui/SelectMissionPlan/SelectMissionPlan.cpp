#include "SelectMissionPlan.h"

namespace view::gui
{
    SelectMissionPlan::SelectMissionPlan( QWidget* parent, QAbstractItemModel* pModel ) :
        QDialog( parent ),
        ui { std::make_shared<Ui::SelectMissionPlan>() }
    {
        ui->setupUi(this);

        ui->tableView->setModel( pModel );
    }
}
