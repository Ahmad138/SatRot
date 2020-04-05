#include "includes/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    const QRect availableSize = w.geometry();
    w.resize(availableSize.width() * 2, availableSize.height() * 2);
    w.move((availableSize.width() - w.width()) / 2, (availableSize.height() - w.height()) / 2);

    w.show();
    return a.exec();
}
