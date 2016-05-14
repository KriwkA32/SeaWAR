#include "myserver.h"
#include <QDataStream>
#include <QTcpSocket>
#include <QTime>

MyServer::MyServer(QObject* parent):QTcpServer(parent)
{
    lastConnectionID = 0;
    connect(this, SIGNAL(newConnection()),
            this, SLOT(on_newConnection()));
}

MyServer::~MyServer()
{
}

void MyServer::startServer()
{
    if(this->isListening())
    {
        sendLog("ERROR: Server was started.");
        return;
    }
    if(this->listen(QHostAddress::Any, 52222))
    {
        sendLog("Start success!");
    }
    else
    {
        sendLog("ERROR: "+ this->errorString());
    }
}

void MyServer::stopServer()
{
    if(!this->isListening())
    {
        sendLog("ERROR: Server is not started.");
        this->errorString();
        return;
    }
    this->close();
    sendLog("Server is stoped.");
}

void MyServer::on_newConnection()
{
    QTcpSocket* client = this->nextPendingConnection();
    clientsList.append(client);
    connect(client,SIGNAL(readyRead()),
            this, SLOT(on_readMessageFromClient()));
    connect(client,SIGNAL(disconnected()),
            this,SLOT(on_connectionLost()));
}

void MyServer::on_readMessageFromClient()
{
    QTcpSocket* client = (QTcpSocket*)sender();
    QDataStream in(client);
    while(client->bytesAvailable())
    {

    }
    QByteArray array;
    quint64 messageLength = client->read(sizeof(quint64)).toInt();
}

void MyServer::on_connectionLost()
{

}

void MyServer::sendLog(const QString& message, const QString who)
{
    QString result;
    result += QTime::currentTime().toString() + ' ';
    result += who + ": ";
    result += message;
    emit sendLogMessage(message);
}
