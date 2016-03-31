#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QtNetwork>
#include <qobject.h>
#include <qstring.h>
#include <qtcpsocket.h>

class TCPSocket : public QObject
{
    Q_OBJECT
public:
    TCPSocket(QObject* parent=0);
    ~TCPSocket();

    void start(QString address, int port);
    void terminate();

    // [FIXME] : this part is for debugging
    int x, y;

private slots:
    void startTransfer();

private:
    QTcpSocket client;
};

#endif // TCPSOCKET_H
