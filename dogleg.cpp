#include  "dogleg.h"
Dog_leg::Dog_leg(vector<double> & deri, vector<vector<double> > hei, double rad) derivative(deri), heissan(hei), radius(rad){} 

//in this function, we can find the direction of the 
vector<double> Dog_leg::getDirection()
{

}
Dog_leg::getPu()
{
	int dimension = derivative.size();
	double nominator = 0;
	for (int i = 0; i < dimension; i++)
		nominator += derivative[i] * derivative[i];
	double denominator = 0;
	for (int i = 0; i < dimension; i++)
		for (int j = 0; j < dimension; j++)
			denominator += derivative[i] * heissan[i][j] * derivative[j];
	double lambda = (0 - nominator) / denominator;
	for (int i = 0; i < dimension; i++)
		pu[i] = lambda * derivative[i];
}
Dog_leg::getPb()
{
	vector<vector<double> > inverseHei = getInverse(heissan);
	int dimension = derivative.size();
	for (int i = 0; i < dimension; i++)
	{
		pb[i] = 0;
		for (int j = 0; j < dimension; j++)
			pb[i] -= inverseHei[i][j] * derivative[j];
	}
}
vector<vector<double> > getInverse(vector<vector<double> & heissan)
{
	double a = heissan[0][0];
	double b = heissan[0][1];
	double c = heissan[1][0];
	double d = heissan[1][1];
	double denominator = a * d - b * c;
	vector<vector<double> > invHeissan;
	vector<double> row0;
	vector<double> row1;
	row0.push_back(d / denominator);
	row0.push_back(-b / denominator);
	row1.push_back(-c / denominator);
	row1.push_back( a / denominator);
	invHeissan.push_back(row0);
	invHeissan.push_back(row1);
	return invHeissan;
}

