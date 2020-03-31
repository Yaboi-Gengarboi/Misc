//Point.cpp
//Justyn Durnford
//Created on 2/18/2020
//Last Updated on 2/18/2020
//

#include "JSpace.hpp"

using std::string;
using std::to_string;

JSpace::Point::Point() {/* Default values are 0.0 */}

JSpace::Point::Point(float x, float y, float z)
{
	_x = x;
	_y = y;
	_z = z;
}

JSpace::Point::Point(float pt_arr[3])
{
	_x = pt_arr[0];
	_y = pt_arr[1];
	_z = pt_arr[2];
}

JSpace::Point::Point(const Point& pt)
{
	_x = pt.get_x();
	_y = pt.get_y();
	_z = pt.get_z();
}

JSpace::Point::~Point() {/* Destructor */}

float JSpace::Point::get_x() const
{
	return _x;
}

void JSpace::Point::set_x(float x)
{
	_x = x;
}

float JSpace::Point::get_y() const
{
	return _y;
}

void JSpace::Point::set_y(float y)
{
	_y = y;
}

float JSpace::Point::get_z() const
{
	return _z;
}

void JSpace::Point::set_z(float z)
{
	_z = z;
}

string JSpace::Point::to_str() const
{
	string str = "";

	str += "(" + to_string(_x) + ", ";
	str += to_string(_y) + ", ";
	str += to_string(_z) + ")";

	return str;
}