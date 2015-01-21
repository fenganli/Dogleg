#ifndef dog_leg_h
#define dog_leg_h
#include <vector>
#include <math.h>
class Dog_leg
{
	private:
	//radius, derivative, heissan are the only three things we need right now
	double radius;
	vector<double> derivative;
	vector<vector<double> > heissan;

	//blow are some helper variables
	vector<double> pu;
	vector<double> pb;
	double t;

	//below are some helper functions
	getPu();
	getPb();
	double getT();
	public:
	Dog_leg(vector<double> & derivative, vector<vector<double> > heissan);
	vector<double> getDirection();
};
//below are some helper functions
//probably there are some generous methods, but here I just hard code it for the case of dimension 2
/bin/bash: pbcopy: command not found
double getLength(vector<double> inputVec)
{
	double length = 0;
	int dimension = inputVec.size();
	for (int i = 0; i < dimension; i++)
		length += inputVec[i] * inputVec[i];
	return sqrt(length);
}
#endif


