// Jpoint.cpp
// Justyn P. Durnford
// Created on 1/13/2020
// Last updated on 4/27/2020

#include "Jpoint.hpp"

// include <string>
using std::string;
using std::to_string;

#include <cmath>
using std::pow;
using std::sqrt;

Jpoint::Jpoint() { /* Default values are 0 */ }

Jpoint::Jpoint(double x, double y, double z)
{
	_x = x;
	_y = y;
	_z = z;
}

Jpoint::Jpoint(double pt_arr[3])
{
	_x = pt_arr[0];
	_y = pt_arr[1];
	_z = pt_arr[2];
}

Jpoint::Jpoint(const Jpoint& pt)
{
	_x = pt.x();
	_y = pt.y();
	_z = pt.z();
}

Jpoint::~Jpoint() { /* Destructor */ }

double Jpoint::x() const
{
	return _x;
}

double Jpoint::y() const
{
	return _y;
}

double Jpoint::z() const
{
	return _z;
}

void Jpoint::setX(double x)
{
	_x = x;
}

void Jpoint::setY(double y)
{
	_y = y;
}

void Jpoint::setZ(double z)
{
	_z = z;
}

void Jpoint::clear()
{
	_x = 0;
	_y = 0;
	_z = 0;
}

Jpoint Jpoint::copy() const
{
	Jpoint pt(_x, _y, _z);
	return pt;
}


string Jpoint::toString() const
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

double distance(const Jpoint& pt1, const Jpoint& pt2)
{
	double dist = 0.0;

	dist += pow(( pt1.x() - pt2.x() ), 2);
	dist += pow(( pt1.y() - pt2.y() ), 2);
	dist += pow(( pt1.z() - pt2.z() ), 2);
	dist = sqrt(dist);

	return dist;
}

bool operator == (const Jpoint& pt1, const Jpoint& pt2)
{
	return ( pt1.x() == pt2.x() ) && ( pt1.y() == pt2.y() ) && ( pt1.z() == pt2.z() );
}

bool operator == (const Jpoint& pt, double pt_arr[3])
{
	return ( pt.x() == pt_arr[0] ) && ( pt.y() == pt_arr[1] ) && ( pt.z() == pt_arr[2] );
}

bool operator != (const Jpoint& pt1, const Jpoint& pt2)
{
	return ( pt1.x() != pt2.x() ) || ( pt1.y() != pt2.y() ) || ( pt1.z() != pt2.z() );
}

bool operator != (const Jpoint& pt, double pt_arr[3])
{
	return ( pt.x() != pt_arr[0] ) || ( pt.y() != pt_arr[1] ) || ( pt.z() != pt_arr[2] );
}