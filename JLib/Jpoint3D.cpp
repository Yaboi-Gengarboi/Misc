// Jpoint3D.cpp
// Justyn P. Durnford
// Created on 1/13/2020
// Last updated on 5/14/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#include "Jpoint3D.hpp"

// include <string>
using std::string;
using std::to_string;

#include <cmath>
using std::pow;
using std::sqrt;

Jpoint3D::Jpoint3D() { /* Default values are 0 */ }

Jpoint3D::Jpoint3D(double x, double y, double z)
{
	_x = x;
	_y = y;
	_z = z;
}

Jpoint3D::Jpoint3D(double pt_arr[3])
{
	_x = pt_arr[0];
	_y = pt_arr[1];
	_z = pt_arr[2];
}

Jpoint3D::Jpoint3D(const Jpoint3D& pt)
{
	_x = pt.x();
	_y = pt.y();
	_z = pt.z();
}

Jpoint3D::~Jpoint3D() { /* Destructor */ }

double Jpoint3D::x() const
{
	return _x;
}

double Jpoint3D::y() const
{
	return _y;
}

double Jpoint3D::z() const
{
	return _z;
}

void Jpoint3D::setX(double x)
{
	_x = x;
}

void Jpoint3D::setY(double y)
{
	_y = y;
}

void Jpoint3D::setZ(double z)
{
	_z = z;
}

void Jpoint3D::clear()
{
	_x = 0;
	_y = 0;
	_z = 0;
}

Jpoint3D Jpoint3D::copy() const
{
	Jpoint3D pt(_x, _y, _z);
	return pt;
}


string Jpoint3D::toString() const
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

double distance(const Jpoint3D& pt1, const Jpoint3D& pt2)
{
	double dist = 0.0;

	dist += pow(( pt1.x() - pt2.x() ), 2);
	dist += pow(( pt1.y() - pt2.y() ), 2);
	dist += pow(( pt1.z() - pt2.z() ), 2);
	dist = sqrt(dist);

	return dist;
}

bool operator == (const Jpoint3D& pt1, const Jpoint3D& pt2)
{
	return ( pt1.x() == pt2.x() ) && ( pt1.y() == pt2.y() ) && ( pt1.z() == pt2.z() );
}

bool operator == (const Jpoint3D& pt, double pt_arr[3])
{
	return ( pt.x() == pt_arr[0] ) && ( pt.y() == pt_arr[1] ) && ( pt.z() == pt_arr[2] );
}

bool operator != (const Jpoint3D& pt1, const Jpoint3D& pt2)
{
	return ( pt1.x() != pt2.x() ) || ( pt1.y() != pt2.y() ) || ( pt1.z() != pt2.z() );
}

bool operator != (const Jpoint3D& pt, double pt_arr[3])
{
	return ( pt.x() != pt_arr[0] ) || ( pt.y() != pt_arr[1] ) || ( pt.z() != pt_arr[2] );
}