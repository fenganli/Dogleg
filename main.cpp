#include <cstdlib>
#include "trustRegion.h"
#include "dogleg.h"
double rosen(vector<double> point);
vector<double> rosenDeriv(vector<double> point);
vector<vector<double> > rosenHei(vector<double> point);
int main(int argc, char * argv[])
{
	vector<double> inputVec;
	inputVec.push_back(atof(argv[1]));
	inputVec.push_back(atof(argv[2]));
	double radMax = atof(argv[3]);
	double radius = atof(argv[4]);
	double eta = atof(argv[5]);
	TrustRegion trustRegion(rosen, rosenDeriv, rosenHei);
	trustRegion.setParameter(radMax, radius, eta);
	vector<double> finalPoint = trustRegion.searchMin(inputVec);
	cout << finalPoint[0] << "," <<  finalPoint[1] << endl;
	return 0;
}
double rosen(vector<double> point)
{
	return 100 * pow(point[1] - point[0] * point[0], 2) + pow(1 - point[0], 2);
}
vector<double> rosenDeriv(vector<double> point)
{
	vector<double> returnVec;
	returnVec.push_back(-400 * point[0] * point[1] + 400 * pow(point[0], 3) + 2 * point[0] -2);
	returnVec.push_back(200 * (point[1] - point[0] * point[0]));
	return returnVec;
}
vector<vector<double> > rosenHei(vector<double> point)
{
	vector<vector<double> > returnVec;
	vector<double> vec1, vec2;
	vec1.push_back(-400 * point[1] + 1200 * point[0] * point[0] + 2);
	vec1.push_back(-400 * point[0]);
	vec2.push_back(-400 * point[0]);
	vec2.push_back(200);
	returnVec.push_back(vec1);
	returnVec.push_back(vec2);
	return returnVec;
}
