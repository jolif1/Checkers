#pragma once

#include <frontend/IFrontend.h>
#include "ui/MainWindow/MainWindow.h"
#include "model/ViewModel.h"

namespace frontend::gui
{
    /**
     * @brief This is actually a controller-like class
     */
    class Controller : public frontend::IFrontend
    {
    public:
        Controller( std::shared_ptr<MainWindow>& pMainWindow, std::shared_ptr<ViewModel>& pModel );

        void show() override;
        void add( const domain::CheckerPtr& pChecker ) override;

    private:
        std::shared_ptr<MainWindow> mMainWindow;
        std::shared_ptr<ViewModel>  mModel;

        void connectWidgets();
    };
}
