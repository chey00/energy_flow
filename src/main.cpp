#include "viewmainwindow.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ViewMainWindow w;

    w.show();

    return a.exec();
}
