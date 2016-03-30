#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QResizeEvent>

#include "superlabel.h"
#include "core.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SuperLabel *label;
    Core *core;

    void resizeEvent(QResizeEvent *);

private slots:
    void onLabelClick(QPointF);
    void onLabelMove(QPointF);
};

#endif // MAINWINDOW_H
