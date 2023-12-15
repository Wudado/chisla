#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include <iomanip>
using namespace std;

void fillMatrix(vector<vector<double>>& matrix);

void fillMatrix(vector<double>& matrix);

void resizeMatrix(vector<vector<double>>& matrix, int newSize);

void resizeMatrix(vector<double>& matrix, int newSize);

vector<double> calculate(vector<vector<double>> matrixA, const vector<double>& matrixB);

void printMatrix(const vector<vector<double>>& matrix);

void printMatrix(const vector<double>& matrix);

vector<double> calculateNeviazku(const vector<vector<double>>& matrixA, const vector<double>& matrixB, const vector<double>& solution);

pair<double, int> maximum(const vector<double>& matrix);

double relative_fault(vector<vector<double>> matrixA, const vector<double>& solution);