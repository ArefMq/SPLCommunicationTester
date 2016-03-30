#include "superlabel.h"

#include <iostream>
#include <cmath>

SuperLabel::SuperLabel(QWidget *parent, Qt::WindowFlags f) :
    QLabel(parent, f), painter(0), image(0)
{
    setMouseTracking(true);
}

SuperLabel::~SuperLabel()
{
    if (painter)
        delete painter;
    if (image)
        delete image;
}

void SuperLabel::setGeometry(const QRect &r)
{
    QLabel::setGeometry(r);
    initializeImageAndPainter();
}

void SuperLabel::setGeometry(int x, int y, int w, int h)
{
    QLabel::setGeometry(x,y,w,h);
    initializeImageAndPainter();
}

void SuperLabel::initializeImageAndPainter()
{
    if (painter)
        delete painter;
    if (image)
        delete image;

    image = new QImage(this->width(), this->height(), QImage::Format_RGB888);
    painter = new QPainter(image);
}

//-- Drawing Function
void SuperLabel::drawLine(float x1, float y1, float x2, float y2, int pen, QColor color)
{
    x1 += width()/2;
    x2 += width()/2;
    y1 += height()/2;
    y2 += height()/2;

    painter->setPen(QPen(color, pen));
    painter->drawLine(x1, y1, x2, y2);
}

void SuperLabel::drawRect(float x, float y, float w, float h, QBrush brush, QPen pen)
{
    x += width()/2;
    y += height()/2;

    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRect(x, y, w, h);
}

void SuperLabel::drawCircle(float cx, float cy, float r, QBrush brush, QPen pen)
{
    cx += width()/2;
    cy += height()/2;

    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawEllipse(QPoint(cx, cy), (int)r, (int)r);
}

void SuperLabel::drawElipse(float x, float y, float w, float h, QBrush brush, QPen pen)
{
    x += width()/2;
    y += height()/2;

    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawEllipse(QPoint(x, y), (int)(w/2), (int)(h/2));
}

void SuperLabel::drawArrow(float x1, float y1, float x2, float y2, int pen, QColor color)
{
    // [FIXME] : this function is not working correctly...
//    x += width()/2;
//    y += height()/2;

//    using namespace std;

//    painter->setPen(QPen(color, pen));
//    painter->drawLine(x1 + width()/2, height()/2 + y1, x2 + width()/2, height()/2 + y2);

//    double theta = atan2(y2-y1 , x2-x1);
//    painter->drawLine(x2 - cos(theta)*10, y2 - sin(theta)*10, x1 + cos(theta)*10, y1 + sin(theta)*10);
//    painter->drawLine(x2 - cos(theta)*10, y2 - sin(theta)*10, x2 - cos(theta+0.2)*30, y2 - sin(theta+0.2)*30);
//    painter->drawLine(x2 - cos(theta)*10, y2 - sin(theta)*10, x2 - cos(theta-0.2)*30, y2 - sin(theta-0.2)*30);
}

void SuperLabel::drawCross(float x, float y, float r, int pen, QColor color)
{
    x += width()/2;
    y += height()/2;

    painter->setPen(QPen(color, pen));
    painter->drawLine(x-r, y-r, x+r, y+r);
    painter->drawLine(x-r, y+r, x+r, y-r);
}

void SuperLabel::drawText(const QString& text, float x, float y, int size, QColor color)
{
    x += width()/2;
    y += height()/2;

    painter->setPen(QPen(color));
    painter->setFont(QFont("Helvetica", size));
    painter->drawText(x, y, text);
}

void SuperLabel::clear(QColor color)
{
    painter->setBrush(QBrush(color));
    painter->drawRect(0, 0, width(), height());
}

void SuperLabel::refresh()
{
    this->setPixmap(QPixmap::fromImage(*image));
}

void SuperLabel::mousePressEvent(QMouseEvent *ev)
{
    if (ev->button() != Qt::LeftButton) return;
    emit onLabelClicked(QPointF(ev->x(), ev->y()));
}

void SuperLabel::mouseReleaseEvent(QMouseEvent *)
{
}

void SuperLabel::mouseMoveEvent(QMouseEvent *ev)
{
    emit onLabelMove(QPointF(ev->x(), ev->y()));
}






