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

    mediaSetting = new MediaSetting(parent);
    qDebug() << "*****mediaSetting =" << mediaSetting->getCurrentPath() << "*****" << endl;

    //Model Init
    mediaModel = new QFileSystemModel();
    mediaModel->setRootPath(QDir::currentPath());

    //QTreeView Init
    QTreeView* &mediaTree = ui->MediaTree;
    mediaTree->setModel(mediaModel);
    mediaTree->setAnimated(false);
    mediaTree->setColumnWidth(0,300);
    mediaTree->setColumnWidth(3, 30);
    mediaTree->setSortingEnabled(true);
    mediaTree->show();
    this->load();
}


MainWindow::~MainWindow()
{
    delete mediaModel;
    delete ui;
    delete mediaSetting;
}

void MainWindow::load()
{
    QDir dir;
    dir.setPath(mediaSetting->getCurrentPath());
    ui->TitleLabel->setText(tr("Do You Like Van Youxi ?"));
}



void MainWindow::on_actionLoad_triggered()
{
    mediaSetting->load();
}
