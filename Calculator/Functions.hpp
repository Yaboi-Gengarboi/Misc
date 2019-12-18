//Functions.hpp
//Justyn P. Durnford
//Created on 12/6/2019
//Last Updated on 12/6/2019

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <cmath>

//Takes two doubles, val and comp and compares them, returning
//true if they are within diff difference of eachother.
//Returns false otherwise.
//Returns false if diff is negative.
bool compareDouble(const double& val, const double& comp, const double diff);

//Takes two doubles, base and val, and takes the log base base
//of val and returns the result.
//Throws an error if val is negative.
double getLog(const double& base, const double& val);

#endif //#ifndef FUNCTIONS_HPP