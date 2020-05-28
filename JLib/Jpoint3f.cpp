// Jpoint3f.cpp
// Justyn P. Durnford
// Created on 1/13/2020
// Last updated on 5/27/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#include "Jpoint3f.hpp"

#include <string>
using std::string;
using std::to_string;

#include <cmath>
using std::pow;
using std::sqrt;

Jpoint3f::Jpoint3f() { /* Default values are 0 */ }

Jpoint3f::Jpoint3f(float x, float y, float z)
{
	_x = x;
	_y = y;
	_z = z;
}

Jpoint3f::Jpoint3f(float pt_arr[3])
{
	_x = pt_arr[0];
	_y = pt_arr[1];
	_z = pt_arr[2];
}

Jpoint3f::Jpoint3f(const Jpoint3f& pt)
{
	_x = pt.x();
	_y = pt.y();
	_z = pt.z();
}

Jpoint3f::~Jpoint3f() { /* Destructor */ }

float Jpoint3f::x() const
{
	return _x;
}

float Jpoint3f::y() const
{
	return _y;
}

float Jpoint3f::z() const
{
	return _z;
}

void Jpoint3f::setX(float x)
{
	_x = x;
}

void Jpoint3f::setY(float y)
{
	_y = y;
}

void Jpoint3f::setZ(float z)
{
	_z = z;
}

void Jpoint3f::clear()
{
	_x = 0;
	_y = 0;
	_z = 0;
}

Jpoint3f Jpoint3f::copy() const
{
	Jpoint3f pt(_x, _y, _z);
	return pt;
}


string Jpoint3f::toString() const
{
	string str = "(";

	str += to_string(_x) + ", ";
	str += to_string(_y) + ", ";
	str += to_string(_z) + ")";

	return str;
}

float distance(const Jpoint3f& pt1, const Jpoint3f& pt2)
{
	float dist = 0.0f;

	dist += pow(( pt1.x() - pt2.x() ), 2);
	dist += pow(( pt1.y() - pt2.y() ), 2);
	dist += pow(( pt1.z() - pt2.z() ), 2);
	dist = sqrt(dist);

	return dist;
}

bool operator == (const Jpoint3f& pt1, const Jpoint3f& pt2)
{
	return ( pt1.x() == pt2.x() ) && ( pt1.y() == pt2.y() ) && ( pt1.z() == pt2.z() );
}

bool operator == (const Jpoint3f& pt, double pt_arr[3])
{
	return ( pt.x() == pt_arr[0] ) && ( pt.y() == pt_arr[1] ) && ( pt.z() == pt_arr[2] );
}

bool operator != (const Jpoint3f& pt1, const Jpoint3f& pt2)
{
	return ( pt1.x() != pt2.x() ) || ( pt1.y() != pt2.y() ) || ( pt1.z() != pt2.z() );
}

bool operator != (const Jpoint3f& pt, double pt_arr[3])
{
	return ( pt.x() != pt_arr[0] ) || ( pt.y() != pt_arr[1] ) || ( pt.z() != pt_arr[2] );
}