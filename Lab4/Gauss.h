#pragma once
#include <iostream>
#include <QVector>
#include <iomanip>
using namespace std;

void fillMatrix(QVector<QVector<double>>& matrix);

void fillMatrix(QVector<double>& matrix);

void resizeMatrix(QVector<QVector<double>>& matrix, int newSize);

void resizeMatrix(QVector<double>& matrix, int newSize);

QVector<double> calculate(QVector<QVector<double>> matrixA, QVector<double> matrixB);

void printMatrix(const QVector<QVector<double>>& matrix);

void printMatrix(const QVector<double>& matrix);

QVector<double> calculateNeviazku(const QVector<QVector<double>>& matrixA, const QVector<double>& matrixB, const QVector<double>& solution);

pair<double, int> maximum(const QVector<double>& matrix);

double relative_fault(QVector<QVector<double>> matrixA, const QVector<double>& solution);
