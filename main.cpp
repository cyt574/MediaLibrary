#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QIcon icon(":/image/logo/favicon.ico");
    w.setWindowIcon(icon);
    w.setWindowTitle("MediaLibrary");
    w.show();

    return a.exec();
}
