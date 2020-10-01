#pragma once

#include <view/GUI/Controller.h>

namespace view::gui
{
    class GUIViewFactory
    {
    public:
        GUIViewFactory() = default;

        std::shared_ptr<Controller> createGuiView();

    private:
        QAbstractItemModel* mModel;
    };
}
