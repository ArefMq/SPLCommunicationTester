#include "core.h"

Core::Core(SuperLabel& l) :
    label(l)
{
}

void Core::drawField()
{
    // [FIXME] : load the parameters from a config file.

    //-- Carpet
    label.clear(Qt::darkGreen);

    //-- Goals Net
    label.drawRect(-450, -80, -50, 160, QBrush(Qt::yellow, Qt::Dense6Pattern), QPen(Qt::yellow, 2));
    label.drawRect(+450, -80, +50, 160, QBrush(Qt::blue, Qt::Dense6Pattern), QPen(Qt::blue, 2));

    //-- Lines
    label.drawRect(-450, -300, 900, 600, Qt::NoBrush, QPen(Qt::white, 5)); //-- Field Border
    label.drawRect(-450, -110, +60, 220, Qt::NoBrush, QPen(Qt::white, 5)); //-- Penalty Box
    label.drawRect(+450, -110, -60, 220, Qt::NoBrush, QPen(Qt::white, 5)); //-- Penalty Box
    label.drawLine(0, -300, 0, +300, 5, Qt::white); //-- Half Line
    label.drawCircle(0, 0, 75, Qt::NoBrush, QPen(Qt::white, 5)); //-- Circle

    // [FIXME] : draw crosses and center circle marker

    //-- Self Goal Posts
    label.drawCircle(-450, -80, 10, Qt::white);
    label.drawCircle(-450, +80, 10, Qt::white);
    label.drawCircle(+450, -80, 10, Qt::white);
    label.drawCircle(+450, +80, 10, Qt::white);
}

void Core::drawInitialPoints()
{
    label.drawCircle(450, 0, 30, Qt::NoBrush, QPen(Qt::black, 3));
    label.drawText("T", 440, 10, 25);
    label.drawCircle(0, 0, 30, Qt::NoBrush, QPen(Qt::black, 3));
    label.drawText("R", -10, 10, 25);
}

void Core::drawPoints()
{
    //-- Selected Points
    for (std::vector<QPointF>::const_iterator i=selectedPoints.begin(); i<selectedPoints.end(); i++)
        label.drawCircle(i->x(), i->y(), 10, Qt::NoBrush, QPen(Qt::darkBlue, 3));

    //-- Transmitted Points
    for (std::vector<QPointF>::const_iterator i=transmittedPoints.begin(); i<transmittedPoints.end(); i++)
        label.drawCircle(i->x(), i->y(), 10, Qt::darkBlue, QPen(Qt::darkBlue, 3));

    //-- Recieved Points
    for (std::vector<QPointF>::const_iterator i=recievedPoints.begin(); i<recievedPoints.end(); i++)
        label.drawCross(i->x(), i->y(), 5, 2, Qt::red);
}

void Core::refresh()
{
    drawField();
    drawPoints();
    drawInitialPoints();
    label.refresh();
}

void Core::addPoint(const QPointF& p)
{
    selectedPoints.push_back(p);
}

void Core::transmitPoint(const QPointF& p)
{
    transmittedPoints.push_back(p);
}

void Core::recievePoint(const QPointF& p)
{
    recievedPoints.push_back(p);
}

void Core::transmitPoint(unsigned id)
{
    transmitPoint(selectedPoints.at(id));
}

