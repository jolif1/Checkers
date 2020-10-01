#pragma once

namespace view
{
    class IView
    {
    public:
        virtual ~IView() = default;

        /**
         * @brief Take the QWidget paradigm. This starts the GUI.
         */
        virtual void show() = 0;
    private:

    };
}
