#include "../includes/mainwindow.h"

#include <QApplication>

/**
 * @brief This is the main C++ class.
 * only job here is to call the QApplication and readjust the size
 * and position of the GUI
 *
 * @param argc
 * @param argv[]
 * @return int
 */
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QGuiApplication::setApplicationDisplayName(" Taking Everyone to Space");

    const QRect availableSize = w.geometry();
    w.move((availableSize.width() - w.width()), (availableSize.height() - w.height()));
//    w.resize(availableSize.width() * 2, availableSize.height() * 2);
//    w.showMaximized();

    w.show();
    return a.exec();
}
