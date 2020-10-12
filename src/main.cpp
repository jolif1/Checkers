#include "frontend/IFrontend.h"
#include "frontend/GUI/GUIFrontendFactory.h"
#include "frontend/adapters/LocalAdapter.h"

#include <QApplication>
#include <memory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    frontend::gui::GUIFrontendFactory           lFrontendFactory;
    std::shared_ptr<frontend::IFrontend>        lFrontend       { lFrontendFactory.createGuiFrontend() };
    std::shared_ptr<communication::IAdapter>    lAdapter        { std::make_shared<frontend::adapters::LocalAdapter>( lFrontend ) };

    lFrontend->addAdapter( lAdapter );
    lFrontend->show();

    return a.exec();
}
