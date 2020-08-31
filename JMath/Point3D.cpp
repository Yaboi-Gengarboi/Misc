// Point3D.cpp
// Justyn P. Durnford
// Created on 2020-01-13
// Last updated on 2020-08-30
// Source file for Point3D class
// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#include "Point3D.h"

#include <string>
using std::string;
using std::to_string;

#include <cmath>
using std::pow;
using std::sqrt;

Point3D::Point3D(double x, double y, double z)
{
	_x = x;
	_y = y;
	_z = z;
}

Point3D::Point3D(const double p_arr[3])
{
	_x = p_arr[0];
	_y = p_arr[1];
	_z = p_arr[2];
}

double Point3D::x() const
{
	return _x;
}

double Point3D::y() const
{
	return _y;
}

double Point3D::z() const
{
	return _z;
}

void Point3D::setX(double x)
{
	_x = x;
}

void Point3D::setY(double y)
{
	_y = y;
}

void Point3D::setZ(double z)
{
	_z = z;
}

void Point3D::clear()
{
	_x = 0;
	_y = 0;
	_z = 0;
}

Point3D Point3D::copy() const
{
	return Point3D(_x, _y, _z);
}


string Point3D::toString() const
{
	string str = "(";

	str += to_string(_x) + ", ";
	str += to_string(_y) + ", ";
	str += to_string(_z) + ")";

	return str;
}

double distance(const Point3D& p, const Point3D& q)
{
	double dist = 0.0;

	dist += pow((p.x() - q.x()), 2);
	dist += pow((p.y() - q.y()), 2);
	dist += pow((p.z() - q.z()), 2);
	dist = sqrt(dist);

	return dist;
}

bool operator == (const Point3D& p, const Point3D& q)
{
	if (p.x() != q.x())
		return false;

	if (p.y() != q.y())
		return false;

	if (p.z() != q.z())
		return false;

	return true;
}

bool operator != (const Point3D& p, const Point3D& q)
{
	if (p.x() != q.x())
		return true;

	if (p.y() != q.y())
		return true;

	if (p.z() != q.z())
		return true;

	return false;
}