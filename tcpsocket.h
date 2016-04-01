#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QtNetwork>
#include <qobject.h>
#include <qstring.h>
#include <qtcpsocket.h>
#include <SPLStandardMessage.h>

class TCPSocket : public QObject
{
    Q_OBJECT
public:
    TCPSocket(QObject* parent=0);
    ~TCPSocket();

    //Mutated Functions
    void setLocationData(int x, int y);

    void start();
    void terminate();
    void setSocketData(QString Address, int Port);

private slots:
    void startTransfer();
    void startRecive();

private:
    QTcpSocket client;
    SPLStandardMessage splStandardMessage;
    QString address;
    int port;
};

#endif // TCPSOCKET_H
