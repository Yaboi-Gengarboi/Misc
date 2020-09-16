// Point3D.cpp
// Justyn P.Durnford
// Created on 2020-01-13
// Last updated on 2020-09-16
// Source file for Point3D class
// This is free and unencumbered software released into the public domain.
// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software, either in source code form or as a compiled
// binary, for any purpose, commercial or non-commercial, and by any
// means.
// In jurisdictions that recognize copyright laws, the author or authors
// of this software dedicate any and all copyright interest in the
// software to the public domain. We make this dedication for the benefit
// of the public at large and to the detriment of our heirs and
// successors. We intend this dedication to be an overt act of
// relinquishment in perpetuity of all presentand future rights to this
// software under copyright law.
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
// OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
// For more information, please refer to http://unlicense.org/

#include "Point3D.h"

#include <string>
using std::string;
using std::to_string;

#include <cmath>
using std::pow;
using std::sqrt;

void Point3D::setValues(double x, double y, double z, char set)
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

Point3D::Point3D(double x, double y, double z)
{
	setValues(x, y, z, 3);
}

Point3D::Point3D(const double p_arr[3])
{
	setValues(p_arr[0], p_arr[1], p_arr[2], 3);
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
	setValues(x, 0, 0, 0);
}

void Point3D::setY(double y)
{
	setValues(0, y, 0, 1);
}

void Point3D::setZ(double z)
{
	setValues(0, 0, z, 2);
}

void Point3D::clear()
{
	setValues(0, 0, 0, 3);
}

void Point3D::setAll(double x, double y, double z)
{
	setValues(x, y, z, 3);
}

void Point3D::setAll(const double p_arr[3])
{
	setValues(p_arr[0], p_arr[1], p_arr[2], 3);
}

void Point3D::setAll(const Point3D& p)
{
	setValues(p.x(), p.y(), p.z(), 3);
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

	dist += pow(( p.x() - q.x() ), 2);
	dist += pow(( p.y() - q.y() ), 2);
	dist += pow(( p.z() - q.z() ), 2);
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