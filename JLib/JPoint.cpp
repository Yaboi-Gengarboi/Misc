// JPoint.cpp
// Justyn P. Durnford
// Created on 1/13/2020
// Last updated on 3/31/2020

#include "JPoint.hpp"
// <string>
using std::string;
using std::to_string;

#include <cmath>
using std::pow;
using std::sqrt;

JPoint::JPoint() { /* Default values are 0.0 */ }

JPoint::JPoint(double x, double y, double z)
{
	_x = x;
	_y = y;
	_z = z;
}

JPoint::JPoint(double pt_arr[3])
{
	_x = pt_arr[0];
	_y = pt_arr[1];
	_z = pt_arr[2];
}

JPoint::JPoint(const JPoint& pt)
{
	_x = pt.getX();
	_y = pt.getY();
	_z = pt.getZ();
}

JPoint::~JPoint() { /* Destructor */ }

double JPoint::getX() const
{
	return _x;
}

double JPoint::getY() const
{
	return _y;
}

double JPoint::getZ() const
{
	return _z;
}

void JPoint::setX(double x)
{
	_x = x;
}

void JPoint::setY(double y)
{
	_y = y;
}

void JPoint::setZ(double z)
{
	_z = z;
}

void JPoint::clear()
{
	_x = 0.0;
	_y = 0.0;
	_z = 0.0;
}

JPoint JPoint::copy() const
{
	JPoint pt(_x, _y, _z);
	return pt;
}


string JPoint::toString() const
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

double distance(const JPoint& pt1, const JPoint& pt2)
{
	double dist = 0.0;

	dist += pow((pt1.getX() - pt2.getX()), 2);
	dist += pow((pt1.getY() - pt2.getY()), 2);
	dist += pow((pt1.getZ() - pt2.getZ()), 2);
	dist = sqrt(dist);

	return dist;
}

bool operator == (const JPoint& pt1, const JPoint& pt2)
{
	return (pt1.getX() == pt2.getX()) && (pt1.getY() == pt2.getY()) && (pt1.getZ() == pt2.getZ());
}

bool operator == (const JPoint& pt, double pt_arr[3])
{
	return (pt.getX() == pt_arr[0]) && (pt.getY() == pt_arr[1]) && (pt.getZ() == pt_arr[2]);
}

bool operator != (const JPoint& pt1, const JPoint& pt2)
{
	return (pt1.getX() != pt2.getX()) || (pt1.getY() != pt2.getY()) || (pt1.getZ() != pt2.getZ());
}

bool operator != (const JPoint& pt, double pt_arr[3])
{
	return (pt.getX() != pt_arr[0]) || (pt.getY() != pt_arr[1]) || (pt.getZ() != pt_arr[2]);
}