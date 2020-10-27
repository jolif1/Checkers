#include "GUIFrontendFactory.h"

#include "ui/MainWindow/MainWindow.h"
#include "model/ViewModel.h"

namespace frontend::gui
{
    std::shared_ptr<IFrontend> GUIFrontendFactory::createGuiFrontend()
    {
        auto lSelectionModl { std::make_shared<QItemSelectionModel>() };
        auto lModel         { std::make_shared<ViewModel>( lSelectionModl ) };
        auto lMainWindow    { std::make_shared<MainWindow>( lModel.get() ) };
        auto lController    { std::make_shared<Controller>( lMainWindow, lModel ) };

        return lController;
    }
}
