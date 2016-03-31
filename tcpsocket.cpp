#include "tcpsocket.h"
#include <qhostaddress.h>
#include <stdlib.h>
#include <iostream>

TCPSocket::TCPSocket(QObject *parent) :
    QObject(parent)
{
    connect(&client, SIGNAL(connected()), this, SLOT(startTransfer()));
}

TCPSocket::~TCPSocket()
{
    terminate();
}

void TCPSocket::start(QString address, int port)
{
    QHostAddress addr(address);
    client.connectToHost(addr, port);
}

#define BUFFER_SIZE 1024
void TCPSocket::startTransfer()
{
    unsigned char buffer[BUFFER_SIZE];
    unsigned i=0;

    memcpy((void*) buffer+i, (const void*)&x, sizeof(int));
    i+= sizeof(int);
    memcpy((void*) buffer+i, (const void*)&y, sizeof(int));
    i+= sizeof(int);

    client.write((const char*)buffer, BUFFER_SIZE);
}

void TCPSocket::terminate()
{
    client.close();
}
