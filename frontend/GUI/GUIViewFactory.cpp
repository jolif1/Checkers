#include "GUIViewFactory.h"

#include "ui/MainWindow/MainWindow.h"

namespace frontend::gui
{
    std::shared_ptr<IFrontend> GUIFrontendFactory::createGuiFrontend()
    {

        auto lMainWindow    = std::make_shared<MainWindow>();
        auto lController    = std::make_shared<Controller>( lMainWindow );


        return lController;
    }
}
