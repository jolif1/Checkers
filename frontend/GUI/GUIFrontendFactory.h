#pragma once

#include <frontend/GUI/Controller.h>

namespace frontend::gui
{
    class GUIFrontendFactory
    {
    public:
        GUIFrontendFactory() = default;

        std::shared_ptr<IFrontend> createGuiFrontend();

    private:
        QAbstractItemModel* mModel;
    };
}
