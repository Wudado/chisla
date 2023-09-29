#pragma once
#include <iostream>
#include <vector>
#include <clocale>
#include <iomanip>
using namespace std;

void fillMatrix(vector<vector<float>>& matrix);

void fillMatrix(vector<float>& matrix);

void resizeMatrix(vector<vector<float>>& matrix, int newSize);

void resizeMatrix(vector<float>& matrix, int newSize);

vector<float> solveSystem(vector<vector<float>>& coefficientsMatrix, vector<float>& solutionsVector);

void printMatrix(vector<vector<float>> matrix);
