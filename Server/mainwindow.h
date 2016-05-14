#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QString;
class MyServer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void printServerLogMessage(const QString&);
private:
    Ui::MainWindow *ui;
    MyServer* server;
};

#endif // MAINWINDOW_H
