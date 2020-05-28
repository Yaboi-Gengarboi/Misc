// Jvector3f.cpp
// Justyn P. Durnford
// Created on 1/20/2020
// Last updated on 5/27/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#include "Jvector3f.hpp"

#include <string>
using std::string;
using std::to_string;

#include <cmath>
using std::pow;
using std::sqrt;

Jvector3f::Jvector3f() { /* See Jpoint3f.hpp and Jvector3f.hpp to see default values */ }

Jvector3f::Jvector3f(float x, float y, float z)
{
	_x = x;
	_y = y;
	_z = z;

	// See Jpoint3f.hpp to see default values for _origin
}

Jvector3f::Jvector3f(const Jpoint3f& pt, float x, float y, float z)
{
	_origin = pt;
	_x = x;
	_y = y;
	_z = z;
}

Jvector3f::Jvector3f(const Jpoint3f& pt, float vec_arr[3])
{
	_origin = pt;
	_x = vec_arr[0];
	_y = vec_arr[1];
	_z = vec_arr[2];
}

Jvector3f::Jvector3f(const Jvector3f& vec)
{
	_origin = vec.origin();
	_x = vec.x();
	_y = vec.y();
	_z = vec.z();
}

Jvector3f::~Jvector3f() { /* Destructor */ }

Jpoint3f Jvector3f::origin() const
{
	return _origin;
}

float Jvector3f::x() const
{
	return _x;
}

float Jvector3f::y() const
{
	return _y;
}

float Jvector3f::z() const
{
	return _z;
}

void Jvector3f::setOrigin(const Jpoint3f& pt)
{
	_origin = pt;
}

void Jvector3f::setOrigin(const float pt_arr[3])
{
	_origin = ( Jpoint3f(pt_arr[0], pt_arr[1], pt_arr[2]) );
}

void Jvector3f::setX(float x)
{
	_x = x;
}

void Jvector3f::setY(float y)
{
	_y = y;
}

void Jvector3f::setZ(float z)
{
	_z = z;
}

float Jvector3f::magnitude() const
{
	return sqrt(pow(_x, 2) + pow(_y, 2) + pow(_z, 2));
}

string Jvector3f::toString() const
{
	string str = "<";

	str += to_string(_x) + ", ";
	str += to_string(_y) + ", ";
	str += to_string(_z) + ">";
	str += " @ ";
	str += _origin.toString();

	return str;
}

Jpoint3f Jvector3f::toPoint() const
{
	return Jpoint3f(_x, _y, _z);
}

Jvector3f operator + (const Jvector3f& vec1, const Jvector3f& vec2)
{
	float x = vec1.x() + vec2.x();

}

Jvector3f& operator += (Jvector3f& vec1, const Jvector3f& vec2)
{

}

Jvector3f operator - (const Jvector3f& vec1, const Jvector3f& vec2)
{

}

Jvector3f& operator -= (Jvector3f& vec1, const Jvector3f& vec2)
{

}

Jvector3f operator * (const Jvector3f& vec1, const Jvector3f& vec2)
{

}

Jvector3f& operator *= (Jvector3f& vec, float f)
{

}

Jvector3f& operator *= (Jvector3f& vec1, const Jvector3f& vec2)
{

}

Jvector3f operator / (const Jvector3f& vec1, const Jvector3f& vec2)
{

}

Jvector3f& operator /= (Jvector3f& vec, float f)
{

}

Jvector3f& operator /= (Jvector3f& vec1, const Jvector3f& vec2)
{

}

bool operator == (const Jvector3f& vec1, const Jvector3f& vec2)
{
	if (vec1.x() != vec2.x())
		return false;

	if (vec1.y() != vec2.y())
		return false;

	if (vec1.z() != vec2.z())
		return false;

	return true;
}

bool operator != (const Jvector3f& vec1, const Jvector3f& vec2)
{
	if (vec1.x() != vec2.x())
		return true;

	if (vec1.y() != vec2.y())
		return true;

	if (vec1.z() != vec2.z())
		return true;

	return false;
}