#pragma once

#include <view/IView.h>
#include <view/GUI/ui/MainWindow/MainWindow.h>
#include <view/GUI/ui/SelectMissionPlan/SelectMissionPlan.h>

namespace view::gui
{
    /**
     * @brief This is actually a controller-like class
     */
    class Controller : public view::IView
    {
    public:
        Controller();

        void show() override;
    private:
        std::shared_ptr<MainWindow>         mMainWindow;
        std::shared_ptr<SelectMissionPlan>  mSelectMpDialog;

        void connectWidgets();
        void launchSelectMpDialog();
    };
}
