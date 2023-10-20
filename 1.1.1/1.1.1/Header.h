#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void fillMatrix(vector<vector<float>>& matrix);

void fillMatrix(vector<float>& matrix);

void resizeMatrix(vector<vector<float>>& matrix, int newSize);

void resizeMatrix(vector<float>& matrix, int newSize);

vector<float> solveSystem(vector<vector<float>> coefficientsMatrix, vector<float> solutionsVector);

void printMatrix(vector<vector<float>> matrix);

vector<float> calculateResiduals(vector<vector<float>>& coefficientsMatrix, vector<float>& solutionsVector, vector<float>& solution);

float calculateRelativeError(const vector<float>& residuals, const vector<float>& solution);
