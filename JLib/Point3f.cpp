// Point3f.cpp
// Justyn P. Durnford
// Created on 1/13/2020
// Last updated on 6/11/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#include "Point3f.hpp"

#include <string>
using std::string;
using std::to_string;

#include <cmath>
using std::pow;
using std::sqrt;

Point3f::Point3f() { /* Default values are 0 */ }

Point3f::Point3f(float x, float y, float z)
{
	_x = x;
	_y = y;
	_z = z;
}

Point3f::Point3f(float pt_arr[3])
{
	_x = pt_arr[0];
	_y = pt_arr[1];
	_z = pt_arr[2];
}

Point3f::Point3f(const Point3f& pt)
{
	_x = pt.x();
	_y = pt.y();
	_z = pt.z();
}

Point3f::~Point3f() { /* Destructor */ }

float Point3f::x() const
{
	return _x;
}

float Point3f::y() const
{
	return _y;
}

float Point3f::z() const
{
	return _z;
}

void Point3f::setX(float x)
{
	_x = x;
}

void Point3f::setY(float y)
{
	_y = y;
}

void Point3f::setZ(float z)
{
	_z = z;
}

void Point3f::clear()
{
	_x = 0;
	_y = 0;
	_z = 0;
}

Point3f Point3f::copy() const
{
	Point3f pt(_x, _y, _z);
	return pt;
}


string Point3f::toString() const
{
	string str = "(";

	str += to_string(_x) + ", ";
	str += to_string(_y) + ", ";
	str += to_string(_z) + ")";

	return str;
}

float distance(const Point3f& pt1, const Point3f& pt2)
{
	float dist = 0.0f;

	dist += pow(( pt1.x() - pt2.x() ), 2);
	dist += pow(( pt1.y() - pt2.y() ), 2);
	dist += pow(( pt1.z() - pt2.z() ), 2);
	dist = sqrt(dist);

	return dist;
}

bool operator == (const Point3f& pt1, const Point3f& pt2)
{
	return ( pt1.x() == pt2.x() ) && ( pt1.y() == pt2.y() ) && ( pt1.z() == pt2.z() );
}

bool operator == (const Point3f& pt, double pt_arr[3])
{
	return ( pt.x() == pt_arr[0] ) && ( pt.y() == pt_arr[1] ) && ( pt.z() == pt_arr[2] );
}

bool operator != (const Point3f& pt1, const Point3f& pt2)
{
	return ( pt1.x() != pt2.x() ) || ( pt1.y() != pt2.y() ) || ( pt1.z() != pt2.z() );
}

bool operator != (const Point3f& pt, double pt_arr[3])
{
	return ( pt.x() != pt_arr[0] ) || ( pt.y() != pt_arr[1] ) || ( pt.z() != pt_arr[2] );
}