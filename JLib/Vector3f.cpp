// Vector3f.cpp
// Justyn P. Durnford
// Created on 1/20/2020
// Last updated on 5/27/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#include "Vector3f.hpp"

#include <string>
using std::string;
using std::to_string;

#include <cmath>
using std::pow;
using std::sqrt;

Vector3f::Vector3f() { /* See Point3f.hpp and Vector3f.hpp to see default values */ }

Vector3f::Vector3f(float x, float y, float z)
{
	_x = x;
	_y = y;
	_z = z;

	// See Point3f.hpp to see default values for _origin
}

Vector3f::Vector3f(const Point3f& pt, float x, float y, float z)
{
	_origin = pt;
	_x = x;
	_y = y;
	_z = z;
}

Vector3f::Vector3f(const Point3f& pt, float vec_arr[3])
{
	_origin = pt;
	_x = vec_arr[0];
	_y = vec_arr[1];
	_z = vec_arr[2];
}

Vector3f::Vector3f(const Vector3f& vec)
{
	_origin = vec.origin();
	_x = vec.x();
	_y = vec.y();
	_z = vec.z();
}

Vector3f::~Vector3f() { /* Destructor */ }

Point3f Vector3f::origin() const
{
	return _origin;
}

float Vector3f::x() const
{
	return _x;
}

float Vector3f::y() const
{
	return _y;
}

float Vector3f::z() const
{
	return _z;
}

void Vector3f::setOrigin(const Point3f& pt)
{
	_origin = pt;
}

void Vector3f::setOrigin(const float pt_arr[3])
{
	_origin = ( Point3f(pt_arr[0], pt_arr[1], pt_arr[2]) );
}

void Vector3f::setX(float x)
{
	_x = x;
}

void Vector3f::setY(float y)
{
	_y = y;
}

void Vector3f::setZ(float z)
{
	_z = z;
}

float Vector3f::magnitude() const
{
	return sqrt(pow(_x, 2) + pow(_y, 2) + pow(_z, 2));
}

string Vector3f::toString() const
{
	string str = "<";

	str += to_string(_x) + ", ";
	str += to_string(_y) + ", ";
	str += to_string(_z) + ">";
	str += " @ ";
	str += _origin.toString();

	return str;
}

Point3f Vector3f::toPoint() const
{
	return Point3f(_x, _y, _z);
}

//Vector3f operator + (const Vector3f& vec1, const Vector3f& vec2)
//{
//	float x = vec1.x() + vec2.x();
//
//}
//
//Vector3f& operator += (Vector3f& vec1, const Vector3f& vec2)
//{
//
//}
//
//Vector3f operator - (const Vector3f& vec1, const Vector3f& vec2)
//{
//
//}
//
//Vector3f& operator -= (Vector3f& vec1, const Vector3f& vec2)
//{
//
//}
//
//Vector3f operator * (const Vector3f& vec1, const Vector3f& vec2)
//{
//
//}
//
//Vector3f& operator *= (Vector3f& vec, float f)
//{
//
//}
//
//Vector3f& operator *= (Vector3f& vec1, const Vector3f& vec2)
//{
//
//}
//
//Vector3f operator / (const Vector3f& vec1, const Vector3f& vec2)
//{
//
//}
//
//Vector3f& operator /= (Vector3f& vec, float f)
//{
//
//}
//
//Vector3f& operator /= (Vector3f& vec1, const Vector3f& vec2)
//{
//
//}

bool operator == (const Vector3f& vec1, const Vector3f& vec2)
{
	if (vec1.x() != vec2.x())
		return false;

	if (vec1.y() != vec2.y())
		return false;

	if (vec1.z() != vec2.z())
		return false;

	return true;
}

bool operator != (const Vector3f& vec1, const Vector3f& vec2)
{
	if (vec1.x() != vec2.x())
		return true;

	if (vec1.y() != vec2.y())
		return true;

	if (vec1.z() != vec2.z())
		return true;

	return false;
}