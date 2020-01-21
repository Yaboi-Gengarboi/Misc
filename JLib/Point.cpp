//Point.cpp
//Justyn P. Durnford
//Created on 1/13/2020
//Last Updated on 1/21/2020
//https://github.com/Yaboi-Gengarboi/Misc/tree/master/JLib

#include "Point.hpp"

#include <array>
using std::array;

#include <string>
using std::string;
using std::to_string;

#include <cmath>
using std::pow;
using std::sqrt;

Point::Point() {/* Default values are 0.0 */}

Point::Point(double x, double y, double z)
{
	_x = x;
	_y = y;
	_z = z;
}

Point::Point(double pt_arr[3])
{
	_x = pt_arr[0];
	_y = pt_arr[1];
	_z = pt_arr[2];
}

Point::Point(array<double, 3> pt_arr)
{
	_x = pt_arr[0];
	_y = pt_arr[1];
	_z = pt_arr[2];
}

Point::~Point() {/* Destructor */}

double Point::get_x() const
{
	return _x;
}

void Point::set_x(const double& x)
{
	_x = x;
}

double Point::get_y() const
{
	return _y;
}

void Point::set_y(const double& y)
{
	_y = y;
}

double Point::get_z() const
{
	return _z;
}

void Point::set_z(const double& z)
{
	_z = z;
}

array<double, 3> Point::to_arr() const
{
	array<double, 3> arr = { _x, _y, _z };
	return arr;
}

string Point::to_str() const
{
	string str = "";

	str += "(";
	str += to_string(_x);
	str += ", ";
	str += to_string(_y);
	str += ", ";
	str += to_string(_z);
	str += ")";

	return str;
}

double distance(const Point& pt1, const Point& pt2)
{
	double return_value = 0.0;

	return_value += pow(pt1.get_x() - pt2.get_x(), 2);
	return_value += pow(pt1.get_y() - pt2.get_y(), 2);
	return_value += pow(pt1.get_z() - pt2.get_z(), 2);
	return_value = sqrt(return_value);

	return return_value;
}

bool are_collinear(const Point& pt1, const Point& pt2, const Point& pt3)
{
	double x[] = { pt1.get_x(), pt2.get_x(), pt3.get_x() };
	double y[] = { pt1.get_y(), pt2.get_y(), pt3.get_y() };
	double z[] = { pt1.get_z(), pt2.get_z(), pt3.get_z() };

	if (((y[1] - y[0]) * (z[2] - z[0]) - (y[2] - y[0]) * (z[1] - z[0])) != 0)
		return false;
	if (((x[2] - x[0]) * (z[1] - z[0]) - (x[1] - x[0]) * (z[2] - z[0])) != 0)
		return false;
	if (((x[1] - x[0]) * (y[2] - y[0]) - (x[2] - x[0]) * (y[1] - y[0])) != 0)
		return false;

	return true;
}