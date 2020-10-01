#include "view/IView.h"
#include "view/GUI/GUIViewFactory.h"

#include <QApplication>
#include <memory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    view::gui::GUIViewFactory lViewFactory;
    std::shared_ptr<view::IView> lView = lViewFactory.createGuiView();
    lView->show();

    return a.exec();
}
