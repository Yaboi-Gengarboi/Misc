//Functions.hpp
//Justyn P. Durnford
//Created on 12/6/2019
//Last Updated on 12/6/2019

#include "Functions.hpp"

#include <cmath>
using std::abs;
using std::log;
using std::sin;
using std::cos;
using std::tan;
using std::pow;
using std::asin;
using std::acos;
using std::atan2;
using std::tgamma;

#include <random>
using std::random_device;
using std::default_random_engine;
using std::uniform_real_distribution;

//See Functions.hpp
bool compareDouble(const double& val, const double& comp, const double diff)
{
	if (diff < 0)
		return false;
	if (abs(val - comp) <= diff)
		return true;
	return false;
}

//See Functions.hpp
double getLog(const double& base, const double& val)
{
	double res = 0.0;

	if (val < 0)
	{

	}
	else
		res = log(val) / log(base);

	return res;
}

int getRandInt(const int& low, const int& high)
{

}