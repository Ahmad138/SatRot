#include "includes/mainwindow.h"

#include <QApplication>

/**
 * @brief This here is the main
 *
 * @param argc
 * @param argv[]
 * @return int
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QGuiApplication::setApplicationDisplayName(" Taking Everyone to Space");

    const QRect availableSize = w.geometry();
//    w.resize(availableSize.width() * 2, availableSize.height() * 2);
    w.move((availableSize.width() - w.width()), (availableSize.height() - w.height()));
//    w.showMaximized();
    w.show();
    return a.exec();
}
