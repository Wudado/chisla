#pragma once
#include <fstream>
#include <vector>
#include <utility>
#include <QVector>
using namespace std;

QVector<pair<double, double>> readFromFile(const string& fileName, int& N);
int XFill(QVector <double>& X, float XMin, float XMax, float Steep);
