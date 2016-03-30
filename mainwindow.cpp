#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    label = new SuperLabel(ui->centralWidget);
    label->setObjectName(QString::fromUtf8("label"));
    QResizeEvent(QSize(), QSize());
    label->setFrameShape(QFrame::Box);
    label->setText("");

    core = new Core(*label);

    connect(label, SIGNAL(onLabelClicked(QPointF)), this, SLOT(onLabelClick(QPointF)));
    connect(label, SIGNAL(onLabelMove(QPointF)), this, SLOT(onLabelMove(QPointF)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete core;
    delete label;
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    label->setGeometry(QRect(10, 10, this->width()-30, this->height()-30));
    ui->status->setGeometry(QRect(10, this->height()-20, this->width()-20, 20));
    core->refresh();
}

void MainWindow::onLabelClick(QPointF p)
{
    const float x = p.x() - label->width()/2;
    const float y = p.y() - label->height()/2;
    core->addPoint(QPointF(x, y));
    core->refresh();
}

void MainWindow::onLabelMove(QPointF p)
{
    ui->status->setText(QString("(") + QString::number(p.x()) + ", " + QString::number(p.y()) + ")");
}
