#include "Header.h"

void fillMatrix(vector<vector<float>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cin >> matrix[i][j];
        }
    }
}

void fillMatrix(vector<float>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        cin >> matrix[i];
    }
}

void resizeMatrix(vector<vector<float>>& matrix, int newSize) {
    matrix.resize(newSize);
    #pragma omp for
    for (int i = 0; i < matrix.size(); i++) {
        matrix[i].resize(newSize);
    }
}

void resizeMatrix(vector<float>& matrix, int newSize) {
    matrix.resize(newSize);
}

vector<float> solveSystem(vector<vector<float>>& coefficientsMatrix, vector<float>& solutionsVector) {
    int n = coefficientsMatrix.size();

    #pragma omp for
    for (int i = 0; i < n; ++i) {
        coefficientsMatrix[i].push_back(solutionsVector[i]);
    }

    for (int i = 0; i < n; ++i) {
        int max_row = i;
        for (int j = i + 1; j < n; ++j) {
            if (abs(coefficientsMatrix[j][i]) > abs(coefficientsMatrix[max_row][i])) {
                max_row = j;
            }
        }

        swap(coefficientsMatrix[i], coefficientsMatrix[max_row]);

        float main = coefficientsMatrix[i][i];
        for (int j = i; j <= n; ++j) {
            coefficientsMatrix[i][j] /= main;
        }

        float factor = 1;

        for (int j = 0; j < n; ++j) {
            if (j != i) {
                factor = coefficientsMatrix[j][i];
                for (int k = i; k <= n; ++k) {
                    coefficientsMatrix[j][k] -= factor * coefficientsMatrix[i][k];
                }
            }
        }
    }

    vector<float> solution;

    for (int i = 0; i < n; ++i) {
        solution.push_back(coefficientsMatrix[i][n]);
    }

    return solution;
}

void printMatrix(vector<vector<float>> matrix) {
    int size = matrix.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(11) << matrix[i][j];
        }
        cout << endl;
    }
}
