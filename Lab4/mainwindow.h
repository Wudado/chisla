#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include "Functions.h"
#include "Gauss.h"
//#include "qcustomplot.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void updateGraph(int value);
    void updateSliderValue(int value);
    QVector<pair<double, double>> graph(QCustomPlot *customPlot, int value);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
