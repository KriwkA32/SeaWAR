#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myserver.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server = new MyServer(this);
    //server->addLogReceiver();

    connect(ui->actionStart_Server,SIGNAL(triggered(bool)),
            server, SLOT(startServer()));
    connect(ui->actionStop_Server,SIGNAL(triggered(bool)),
            server, SLOT(stopServer()));
    connect(server, SIGNAL(sendLogMessage(QString)),
            this, SLOT(printServerLogMessage(QString)));

    connect(ui->actionExit, SIGNAL(triggered(bool)),
            this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete server;
    delete ui;
}

void MainWindow::printServerLogMessage(const QString & message)
{
    ui->serverView->append(message);
}
