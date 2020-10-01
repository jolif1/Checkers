#include "GUIViewFactory.h"

#include <qtable
#include "ui/MainWindow/MainWindow.h"
#include "ui/SelectMissionPlan/SelectMissionPlan.h"

namespace view::gui
{
    std::shared_ptr<GUIView> GUIViewFactory::createGuiView()
    {

        auto lMainWindow    = std::make_shared<MainWindow>();
        auto lSelectMp      = std::make_shared<SelectMissionPlan>( static_cast<QWidget*>( lMainWindow.get() ), mModel);
        auto lController    = std::make_shared<GUIView>( lMainWindow, lSelectMp );


        return lController;
    }
}
