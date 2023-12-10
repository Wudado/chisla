#include "Functions.h"
#include <fstream>
using namespace std;

QVector<pair<double, double>> readFromFile(const string& filePath, int& N) {
    ifstream in(filePath);
    QVector<pair<double, double>> F;
	if (in.is_open()) {
		in >> N;
		double x;
		double y;
		for (int i = 0; i < N; ++i) {
			in >> x >> y;
			F.push_back({ x, y });
		}
	}
	in.close();
	return F;
}

int XFill(QVector <double>& X, float XMin, float XMax, float Steep) {
    int count = 0;
    double XVal = XMin;
    while(XVal<XMax) {
        X.push_back(XVal);
        XVal= XVal + Steep;
        count++;
    }
    return count;
}
