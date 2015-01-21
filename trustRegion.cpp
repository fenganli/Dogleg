#include "trustRegion.h"
TrustRegion::TrustRegion(double (*_func)(vector<double>), vector<double> (* _derivative)(vector<double>), vector<vector<double> >(* _heissan)(vector<double>)):func(_func), derivative(_derivative), heissan(_heissan)
{
	//below are some initial points
	radMax = 5;
	radius = 1;
	eta = 0.125;
}
void TrustRegion::setParameter(double _radMax, double _radius, double _eta)
{
	radMax = _radMax;
	radius = _radius;
	eta = _eta;
}
vector<double> TrustRegion::searchMin(vector<double> initPoint)
{
	vector<double> point = initPoint;
	while (true) //begin the loop
	{
		Dog_leg solver(derivative(point), heissan(point), radius);
		vector<double> pk = solver.getDirection();
	}
}
