#ifndef CORE_H
#define CORE_H

#include <QPointF>
#include <vector>
#include <qthread.h>
#include <iostream>

#include "superlabel.h"
#include "tcpsocket.h"

class Core
{
    class SenderTimer : public QThread
    {
        Q_OBJECT
    public:
        //-- SenderTimer(
        //          TransferInterval : Time wait till next message
        SenderTimer(unsigned TransferInterval, QObject* parent=0) : QThread(parent), transferInterval(TransferInterval) {}

    private:
        unsigned transferInterval;

        void run()
        {
            for (unsigned i=0; ;++i)
            {
                sleep(1);
                std::cout << "hi" << std::endl;
            }
        }

    signals:
        void tick(int);
        void nextTransfer();
    };

public:
    Core(SuperLabel& label);

    //-- Location Message
    void refresh();
    void addPoint(const QPointF& p);
    void transmitPoint(const QPointF& p);
    void transmitPoint(unsigned id);
    void recievePoint(const QPointF& p);

    unsigned selectedPointsSize();
    void clearSelection();
    void clearAll();

    void sendLocation();


private:
    SuperLabel& label;
    TCPSocket *transmitterSocket;
    TCPSocket *recieverSocket;
    std::vector<QPointF> selectedPoints;
    std::vector<QPointF> recievedPoints;
    std::vector<QPointF> transmittedPoints;

    void drawField();
    void drawPoints();
    void drawInitialPoints();
};

#endif // CORE_H
