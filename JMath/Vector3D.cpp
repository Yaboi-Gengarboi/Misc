// Vector3D.cpp
// Justyn P. Durnford
// Created on 2020-01-20
// Last updated on 2020-08-30
// Source file for the Vector3D class
// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#include "Point3D.h"
#include "Vector3D.h"

#include <ostream>
using std::ostream;

#include <string>
using std::string;
using std::to_string;

#include <cmath>
using std::pow;
using std::sqrt;
using std::acos;

Vector3D::Vector3D(double x, double y, double z)
{
	_x = x;
	_y = y;
	_z = z;
}

Vector3D::Vector3D(const double v_arr[3])
{
	_x = v_arr[0];
	_y = v_arr[1];
	_z = v_arr[2];
}

Vector3D::Vector3D(const Point3D& p)
{
	_x = p.x();
	_y = p.y();
	_z = p.z();
}

Vector3D::Vector3D(const Point3D& p, const Point3D& q)
{
	_x = q.x() - p.x();
	_y = q.y() - p.y();
	_z = q.z() - p.z();
}

double Vector3D::x() const
{
	return _x;
}

double Vector3D::y() const
{
	return _y;
}

double Vector3D::z() const
{
	return _z;
}

void Vector3D::setX(double x)
{
	_x = x;
}

void Vector3D::setY(double y)
{
	_y = y;
}

void Vector3D::setZ(double z)
{
	_z = z;
}

void Vector3D::setAll(double x, double y, double z)
{
	_x = x;
	_y = y;
	_z = z;
}

void Vector3D::setAll(const double v_arr[3])
{
	_x = v_arr[0];
	_y = v_arr[1];
	_z = v_arr[2];
}

void Vector3D::setAll(const Point3D& p)
{
	_x = p.x();
	_y = p.y();
	_z = p.z();
}

void Vector3D::setAll(const Vector3D& v)
{
	_x = v.x();
	_y = v.y();
	_z = v.z();
}

double Vector3D::magnitude() const
{
	return sqrt(pow(_x, 2) + pow(_y, 2) + pow(_z, 2));
}

string Vector3D::toString() const
{
	string str = "<";

	str += to_string(_x) + ", ";
	str += to_string(_y) + ", ";
	str += to_string(_z) + ">";

	return str;
}

Vector3D& Vector3D::operator += (const Vector3D& v)
{
	_x += v.x();
	_y += v.y();
	_z += v.z();

	return *this;
}

Vector3D& Vector3D::operator -= (const Vector3D& v)
{
	_x -= v.x();
	_y -= v.y();
	_z -= v.z();

	return *this;
}

Vector3D& Vector3D::operator *= (double d)
{
	_x *= d;
	_y *= d;
	_z *= d;

	return *this;
}

Vector3D& Vector3D::operator /= (double d)
{
	_x /= d;
	_y /= d;
	_z /= d;

	return *this;
}

Vector3D operator + (const Vector3D& v, const Vector3D& u)
{
	return Vector3D(v.x() + u.x(), v.y() + u.y(), v.z() + u.z());
}

Vector3D operator - (const Vector3D& v, const Vector3D& u)
{
	return Vector3D(v.x() - u.x(), v.y() - u.y(), v.z() - u.z());
}

Vector3D operator * (const Vector3D& v, double d)
{
	return Vector3D(v.x() * d, v.y() * d, v.z() * d);
}

Vector3D operator / (const Vector3D& v, double d)
{
	return Vector3D(v.x() / d, v.y() / d, v.z() / d);
}

bool operator == (const Vector3D& v, const Vector3D& u)
{
	if (v.x() != u.x())
		return false;

	if (v.y() != u.y())
		return false;

	if (v.z() != u.z())
		return false;

	return true;
}

bool operator != (const Vector3D& v, const Vector3D& u)
{
	if (v.x() != u.x())
		return true;

	if (v.y() != u.y())
		return true;

	if (v.z() != u.z())
		return true;

	return false;
}

ostream& operator << (ostream& os, const Vector3D& v)
{
	os << v.toString();
	return os;
}

double dot_product(const Vector3D& v, const Vector3D& u)
{
	return (v.x() * u.x() + v.y() * u.y() + v.z() * u.z());
}

Vector3D cross_product(const Vector3D& v, const Vector3D& u)
{
	return Vector3D(v.y() * u.z() - v.z() * u.y(), v.z() * u.x() - v.x() * u.z(), v.x() * u.y() - v.y() * u.x());
}

double angle_between(const Vector3D& v, const Vector3D& u)
{
	return acos(dot_product(v, u) / ( v.magnitude() * u.magnitude() ));
}

bool are_parallel(const Vector3D& v, const Vector3D& u)
{
	return false;
}

bool are_normal(const Vector3D& v, const Vector3D& u)
{
	if (dot_product(v, u) == PI / 2)
		return true;

	return false;
}

double scalar_proj(const Vector3D& v, const Vector3D& u)
{
	return ( dot_product(v, u) / v.magnitude() );
}

Vector3D vector_proj(const Vector3D& v, const Vector3D& u)
{
	return v * ( dot_product(v, u) / dot_product(v, v) );
}