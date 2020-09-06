/*
Vector3D.cpp
Justyn P. Durnford
Created on 2020-01-20
Last updated on 2020 - 09 - 06
Source file for the Vector3D class

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non - commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain.We make this dedication for the benefit
of the public at largeand to the detriment of our heirsand
successors.We intend this dedication to be an overt act of
relinquishment in perpetuity of all presentand future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>
*/

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

void Vector3D::setValues(double x, double y, double z, char set)
{
	switch (set)
	{
		case 0:
			_x = x;
			break;
		case 1:
			_y = y;
			break;
		case 2:
			_z = z;
			break;
		default:
			_x = x;
			_y = y;
			_z = z;
			break;
	}
}

Vector3D::Vector3D(double x, double y, double z)
{
	setValues(x, y, z, 3);
}

Vector3D::Vector3D(const double v_arr[3])
{
	setValues(v_arr[0], v_arr[1], v_arr[2], 3);
}

Vector3D::Vector3D(const Point3D& p)
{
	setValues(p.x(), p.y(), p.z(), 3);
}

Vector3D::Vector3D(const Point3D& p, const Point3D& q)
{
	setValues(q.x() - p.x(), q.y() - p.y(), q.z() - p.z(), 3);
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
	setValues(x, 0, 0, 0);
}

void Vector3D::setY(double y)
{
	setValues(0, y, 0, 1);
}

void Vector3D::setZ(double z)
{
	setValues(0, 0, z, 2);
}

void Vector3D::setAll(double x, double y, double z)
{
	setValues(x, y, z, 3);
}

void Vector3D::setAll(const double v_arr[3])
{
	setValues(v_arr[0], v_arr[1], v_arr[2], 3);
}

void Vector3D::setAll(const Point3D& p)
{
	setValues(p.x(), p.y(), p.z(), 3);
}

void Vector3D::setAll(const Vector3D& v)
{
	setValues(v.x(), v.y(), v.z(), 3);
}

void Vector3D::clear()
{
	setValues(0, 0, 0, 3);
}

Vector3D Vector3D::copy() const
{
	return Vector3D(_x, _y, _z);
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