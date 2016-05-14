#ifndef MYSERVER_H
#define MYSERVER_H
#include <QTcpServer>
#include <functional>

class QTcpSocket;
class QString;
template<typename T> class QList;

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    MyServer(QObject* parent = nullptr);
    virtual ~MyServer();
public slots:
    void startServer();
    void stopServer();
private slots:
    void on_newConnection();
    void on_readMessageFromClient();
    void on_connectionLost();
signals:
    void sendLogMessage(const QString&);
private:
    quint32 lastConnectionID;
    QList<QTcpSocket*> clientsList;
    void sendLog(const QString& message, const QString who = "Server");
};

#endif // MYSERVER_H
