#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmessagebox.h>

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_back->setVisible(false);

    label = new SuperLabel(ui->page_location);
    label->setObjectName(QString::fromUtf8("label"));
    QResizeEvent(QSize(), QSize());
    label->setFrameShape(QFrame::Box);
    label->setText("");
    core = new Core(*label);

    ui->pushButton_send->raise();
    ui->pushButton_clear->raise();

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
    ui->stackedWidget->setGeometry(0, 0, this->width(), this->height()-21);
    ui->status->setGeometry(QRect(10, this->height()-20, this->width()-20, 20));

    //-- Home Page
    // [FIXME] : set geometry for home page

    //-- Location Page
    label->setGeometry(QRect(10, 10, ui->stackedWidget->width()-20, ui->stackedWidget->height()-20));

    //-- Data Page

    //-- Settings Page
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
    const float x = p.x() - label->width()/2;
    const float y = p.y() - label->height()/2;
    ui->status->setText(QString("(") + QString::number(x) + ", " + QString::number(y) + ")");
}

void MainWindow::on_pushButton_location_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->pushButton_back->setVisible(true);
}

void MainWindow::on_pushButton_data_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->pushButton_back->setVisible(true);
}

void MainWindow::on_pushButton_settings_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->pushButton_back->setVisible(true);
}

void MainWindow::on_pushButton_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->pushButton_back->setVisible(false);
}

void MainWindow::on_pushButton_clear_clicked()
{
    if (!core->selectedPointsSize())
        core->clearAll();
    else
        core->clearSelection();
}

void MainWindow::on_pushButton_send_clicked()
{
    if (!core->selectedPointsSize())
    {
        QMessageBox::critical(this, "Error", "Please select points on the field by clicking on the field.");
        return;
    }

    if (core->selectedPointsSize() < 3)
        if (QMessageBox::warning(this, "Warning", "You have selected less than 3 points,\naccourding to the rules.\n\nAre you sure you want to send the points?", QMessageBox::Cancel, QMessageBox::Yes) == QMessageBox::Cancel)
            return;
    if (core->selectedPointsSize() > 3)
        if (QMessageBox::warning(this, "Warning", "You have selected more than 3 points,\naccourding to the rules.\n\nAre you sure you want to send the points?", QMessageBox::Cancel, QMessageBox::Yes) == QMessageBox::Cancel)
            return;

    core->sendLocation();
}

void MainWindow::on_pushButton_packets_clicked()
{

}
