#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Functions.h"
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->table->setColumnCount(2);
    ui->table->setColumnWidth(0, 90);
    ui->table->setHorizontalHeaderLabels(QStringList() << "X" << "Y");

    ui->Slider->setRange(1, 20); // Установка диапазона значений
    int PresetValue = 3;
    ui->Slider->setValue(PresetValue);
    ui->SliderValueLabel->setText(QString::number(PresetValue));

    connect(ui->Slider, &QSlider::valueChanged, this, &MainWindow::updateGraph);
    connect(ui->Slider, &QSlider::sliderMoved, this, &MainWindow::updateSliderValue);

    updateGraph(ui->Slider->value());
}

void MainWindow::updateSliderValue(int value)
{
    ui->SliderValueLabel->setText(QString::number(value));
}

void MainWindow::updateGraph(int value)
{
    QVector<pair<double, double>> F = graph(ui->Nigra, value);

    int rowCount = F.size();
    ui->table->setRowCount(rowCount);

    for (int i = 0; i < rowCount; ++i) {
        QTableWidgetItem *xItem = new QTableWidgetItem(QString::number(F[i].first));
        QTableWidgetItem *yItem = new QTableWidgetItem(QString::number(F[i].second));

        ui->table->setItem(i, 0, xItem);
        ui->table->setItem(i, 1, yItem);
    }

    ui->table->show();

    ui->Nigra->replot();
}

QVector<pair<double, double>> MainWindow::graph(QCustomPlot *customPlot, int m)
{
    double xMin = 0; //x range
    double xMax = 100; //
    //int m = 3; //degree of approximating polynomial

    int N = 21;
    QVector<pair<double, double>> F = {
        {0, 1.00762},
        {5, 1.00392},
        {10, 1.00153},
        {15, 1.00000},
        {20, 0.99907},
        {25, 0.99852},
        {30, 0.99826},
        {35, 0.99818},
        {40, 0.99828},
        {45, 0.99849},
        {50, 0.99878},
        {55, 0.99919},
        {60, 0.99967},
        {65, 1.00024},
        {70, 1.00091},
        {75, 1.00167},
        {80, 1.00253},
        {85, 1.00351},
        {90, 1.00461},
        {95, 1.00586},
        {100, 1.00721}
    };

    //int N;
    //QVector<pair<double, double>> F = readFromFile("\\a.txt", N);

    for (int i = 0; i < N; i++) {
        cout << F[i].first << "  " << F[i].second << endl;
    }

    QVector<QVector<double>> SUMX(m + 1);

    for (int i = 1; i <= m; ++i) {
        SUMX[i].resize(m + 1);
        for (int j = 0; j <= m; ++j) {
            double sum = 0;
            for (int k = 0; k < N; ++k) {
                sum += pow(F[k].first, i + j);
            }
            SUMX[i][j] = sum;
        }
    }

    SUMX[0].resize(m + 1);
    SUMX[0][0] = N;

    QVector<double> PRAW(m + 1);
    for (int l = 0; l <= m; ++l) {
        for (int i = 0; i < N; ++i) {
            PRAW[l] += F[i].second * pow(F[i].first, l);
        }
    }

    QVector<double> A = calculate(SUMX, PRAW);

    for (int i = 0; i < A.size(); ++i) {
        cout << A[i] << "   ";
    }

    QVector<double> x, y;

    int count = XFill(x, 0.0, 100.0, 0.5);

    for(int i = 0; i < count; i++){
        double Y = 0;
        for(int j = m; j >= 0; j--){
            Y = Y + A[j]*pow(x[i], j);
        }
        y.push_back(Y);
    }

    customPlot->addGraph();
    customPlot->setBackground(QBrush(QColor(53, 53, 53)));
    customPlot->xAxis->setBasePen(QPen(Qt::white));
    customPlot->yAxis->setBasePen(QPen(Qt::white));

    customPlot->xAxis->setTickLabelColor(Qt::white);
    customPlot->yAxis->setTickLabelColor(Qt::white);
    customPlot->graph(0)->setPen(QPen(QColor(42, 130, 218)));

    QPen graphPen = customPlot->graph(0)->pen();
    graphPen.setWidth(5);
    customPlot->graph(0)->setPen(graphPen);

    customPlot->graph(0)->setData(x, y);

    customPlot->xAxis->setRange(xMin, xMax);
    customPlot->yAxis->setRange(*min_element(y.begin(), y.end())-0.01, *max_element(y.begin(), y.end())+0.01);

    return(F);
}

MainWindow::~MainWindow()
{
    delete ui;
}
