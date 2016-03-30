#ifndef SUPERLABEL_H
#define SUPERLABEL_H

#include <qlabel.h>
#include <qpainter.h>
#include <qimage.h>
#include <QMouseEvent>

class SuperLabel : public QLabel
{
    Q_OBJECT
public:
    explicit SuperLabel(QWidget *parent=0, Qt::WindowFlags f=0);
    ~SuperLabel();

    void setGeometry(const QRect &Rect);
    void setGeometry(int x, int y, int w, int h);

    //-- Drawing Function
    void drawLine(float x1, float y1, float x2, float y2, int pen=1, QColor color=Qt::black);
    void drawRect(float x, float y, float w, float h, QBrush brush=QBrush(), QPen pen=QPen());
    void drawCircle(float cx, float cy, float r, QBrush brush=QBrush(), QPen pen=QPen());
    void drawElipse(float x, float y, float w, float h, QBrush brush=QBrush(), QPen pen=QPen());
    void drawArrow(float x1, float y1, float x2, float y2, int pen=1, QColor color=Qt::black);
    void drawCross(float x, float y, float r=10, int pen=1, QColor color=Qt::black);
    void drawText(const QString& text, float x, float y, int size=-1, QColor color=Qt::black);
    void clear(QColor color=Qt::white);
    void refresh();

    QPainter *painter; // [FIXME] : make this parameter private
private:
    QImage *image;

    void initializeImageAndPainter();

signals:
    void onLabelClicked(QPointF);
    void onLabelMove(QPointF);

private slots:
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
};

#endif // SUPERLABEL_H
