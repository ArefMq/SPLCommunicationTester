#include "tcpsocket.h"
#include <qhostaddress.h>
#include <stdlib.h>
#include <iostream>

TCPSocket::TCPSocket(QObject *parent) :
    QObject(parent)
{
    connect(&client, SIGNAL(connected()), this, SLOT(startTransfer()));
    connect(&client, SIGNAL(connected()), this, SLOT(startRecive()));
}

TCPSocket::~TCPSocket()
{
    terminate();
}

void TCPSocket::start()
{
    QHostAddress addr(address);
    client.connectToHost(addr, port);
}

void TCPSocket::setSocketData(QString Address, int Port)
{
    address = Address;
    port = Port;
}

void TCPSocket::startTransfer()
{
    client.write((const char*)&splStandardMessage, sizeof(SPLStandardMessage));
}

void TCPSocket::startRecive()
{
    //client.read((const char*)&splStandardMessage, sizeof(SPLStandardMessage));
}

void TCPSocket::terminate()
{
    client.close();
}

void TCPSocket::setLocationData(int x, int y)
{
    // [TODO] : ask TC if these data type should change in future
    splStandardMessage.ball[0] = x;
    splStandardMessage.ball[1] = y;
}
