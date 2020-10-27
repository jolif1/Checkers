#include <application/ApplicationFactory.h>
#include <frontend/IFrontend.h>
#include <frontend/GUI/GUIFrontendFactory.h>
#include <frontend/adapters/LocalAdapter.h>

#include <QApplication>
#include <memory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    frontend::gui::GUIFrontendFactory                       lFrontendFactory;
    std::shared_ptr<frontend::IFrontend>                    lFrontend       { lFrontendFactory.createGuiFrontend() };
    std::shared_ptr<communication::IAdapter>                lFrontAdapter   { std::make_shared<frontend::adapters::LocalAdapter>( lFrontend ) };
    application::factory::ApplicationFactory                lAppFactory     ;
    std::shared_ptr<application::adapters::LocalAdapter>    lAppAdapter     { lAppFactory.getLocalAdapter() };

//    lFrontend->addAdapter( lFrontAdapter );
    lFrontend->addAdapter( lAppAdapter );
    lAppAdapter->addAdapter( lFrontAdapter );

    lFrontend->show();

    return a.exec();
}
