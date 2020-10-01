#pragma once

#include <frontend/IFrontend.h>
#include <frontend/GUI/ui/MainWindow/MainWindow.h>

namespace frontend::gui
{
    /**
     * @brief This is actually a controller-like class
     */
    class Controller : public frontend::IFrontend
    {
    public:
        Controller( std::shared_ptr<MainWindow>& pMainWindow );

        void show() override;
    private:
        std::shared_ptr<MainWindow> mMainWindow;

        void connectWidgets();
    };
}
