#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QListWidgetItem>
#include <QFileInfoList>
#include <QListWidget>
#include <QIcon>
#include <QLineEdit>
#include <QFileSystemModel>
#include <QTreeView>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    mediaTree = new QTreeView();
    mediaTree = ui->MediaTree;

    QFileSystemModel mediaModel;
    mediaSetting = new MediaSetting(parent);
    qDebug() << "*****mediaSetting =" << mediaSetting->getCurrentPath() << "*****" << endl;
 //   mediaModel.setRootPath(mediaSetting->getCurrentPath());
    mediaModel.setRootPath("");
    mediaTree->setModel(&mediaModel);
    mediaTree->setIndentation(40);
    mediaTree->setAnimated(false);
    mediaTree->setSortingEnabled(true);
    mediaTree->reset();
}

MainWindow::~MainWindow()
{
    delete mediaTree;
    delete ui;
    delete mediaSetting;
}

void MainWindow::load()
{
    QDir dir;
    dir.setPath(mediaSetting->getCurrentPath());

}



void MainWindow::on_actionLoad_triggered()
{
    mediaSetting->load();
}
