#ifndef trust_region_h
#define trust_region_h
#include <iostream>
#include <vector>
using namespace std;
class TrustRegion
{
	private:
	double (* func)(vector<double>);
	vector<double> (*derivative)(vector<double>);
	vector<vector<double> > (*heissan)(vector<double>);
	double radMax, radius, eta;
	public:
	TrustRegion(double (*_func)(vector<double>), vector<double> (* _derivative)(vector<double>), vector<vector<double> >(* _heissan)(vector<double>));
	void setParameter(double _radMax, double _radius, double _eta);
	//this function searchs for the minPoint from initPoint
	vector<double> searchMin(vector<double> initPoint);
};
extern double getLength(vector<double> inputVec);
extern const double eps;  
#endif
