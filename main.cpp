#include "frontend/IFrontend.h"
#include "frontend/GUI/GUIFrontendFactory.h"

#include <QApplication>
#include <memory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    frontend::gui::GUIFrontendFactory       lFrontendFactory;
    std::shared_ptr<frontend::IFrontend>    lFrontend       = lFrontendFactory.createGuiFrontend();

    lFrontend->show();

    return a.exec();
}
