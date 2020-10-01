#pragma once

namespace frontend
{
    class IFrontend
    {
    public:
        virtual ~IFrontend() = default;

        /**
         * @brief Take the QWidget paradigm. This starts the Frontend.
         */
        virtual void show() = 0;
    private:

    };
}
