#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "seafield.h"
#include "shipplacement.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->playOffline, SIGNAL(triggered(bool)),
            this, SLOT(on_PlayOffline()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_PlayOffline()
{
    ShipPlacement* shipPl = new ShipPlacement(this);
    shipPl->show();
    shipPl->exec();
}
