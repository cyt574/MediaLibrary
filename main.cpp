#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    translator.load("zh_CN.qm");
    a.installTranslator(&translator);
    MainWindow w;
    QIcon icon(":/image/logo/favicon.ico");
    w.setWindowIcon(icon);
    w.setWindowTitle("MediaLibrary");
    w.show();

    return a.exec();
}
