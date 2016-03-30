#ifndef CORE_H
#define CORE_H

#include "superlabel.h"
#include <QPointF>
#include <vector>

class Core
{
public:
    Core(SuperLabel& label);

    void refresh();
    void addPoint(const QPointF& p);
    void transmitPoint(const QPointF& p);
    void transmitPoint(unsigned id);
    void recievePoint(const QPointF& p);


private:
    SuperLabel& label;
    std::vector<QPointF> selectedPoints;
    std::vector<QPointF> recievedPoints;
    std::vector<QPointF> transmittedPoints;

    void drawField();
    void drawPoints();
    void drawInitialPoints();
};

#endif // CORE_H
