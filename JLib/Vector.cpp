//Vector.cpp
//Justyn P. Durnford
//Created on 1/20/2020
//Last Updated on 1/20/2020
//

#include "Vector.hpp"
#include "Point.hpp"

#include <array>
using std::array;

#include <string>
using std::string;
using std::to_string;

#include <cmath>
using std::sqrt;
using std::pow;

Vector::Vector() {/* Default values are 0.0 */}

Vector::Vector(double x, double y, double z)
{
	_x = x;
	_y = y;
	_z = z;
}

Vector::Vector(double vec_arr[3])
{
	_x = vec_arr[0];
	_y = vec_arr[1];
	_z = vec_arr[2];
}

Vector::Vector(const array<double, 3>& vec_arr)
{
	_x = vec_arr[0];
	_y = vec_arr[1];
	_z = vec_arr[2];
}

Vector::Vector(const Point& pt)
{
	_x = pt.get_x();
	_y = pt.get_y();
	_z = pt.get_z();
}

Vector::Vector(const Point& pt1, const Point& pt2)
{
	_x = pt2.get_x() - pt1.get_x();
	_y = pt2.get_y() - pt1.get_y();
	_z = pt2.get_z() - pt1.get_z();
}

Vector::~Vector() {/* Destructor */}

double Vector::get_x() const
{
	return _x;
}

void Vector::set_x(double x)
{
	_x = x;
}

double Vector::get_y() const
{
	return _y;
}

void Vector::set_y(double y)
{
	_y = y;
}

double Vector::get_z() const
{
	return _z;
}

void Vector::set_z(double z)
{
	_z = z;
}

void Vector::clear()
{
	_x = 0;
	_y = 0;
	_z = 0;
}

double Vector::length()
{
	double length = 0.0;
	length = pow(_x, 2) + pow(_y, 2) + pow(_z, 2);
	length = sqrt(length);
	return length;
}

void Vector::add(const Vector& vec)
{

}

void Vector::subtract(const Vector& vec)
{
	
}

void Vector::scale(double scalar)
{
	_x *= scalar;
	_y *= scalar;
	_z *= scalar;
}

Vector Vector::copy() const
{
	Vector vec(_x, _y, _z);
	return vec;
}

Point Vector::to_point() const
{
	Point pt(_x, _y, _z);
	return pt;
}

array<int, 3> Vector::to_arr() const
{
	array<int, 3> arr = { _x, _y, _z };
	return arr;
}

string Vector::to_str() const
{
	string str = "<";
	str += to_string(_x);
	str += ", ";
	str += to_string(_y);
	str += ", ";
	str += to_string(_z);
	str += ">";
	return str;
}

double dot_product(const Vector& vec1, const Vector& vec2)
{
	double d = 0.0;
	d = (vec1.get_x() * vec2.get_x());
	d += (vec1.get_y() * vec2.get_y());
	d += (vec1.get_z() * vec2.get_z());
	return d;
}

Vector cross_product(const Vector& vec1, const Vector& vec2)
{
	double x = (vec1.get_y() * vec2.get_z()) - (vec1.get_z() * vec2.get_y());
	double y = (vec1.get_z() * vec2.get_x()) - (vec1.get_x() * vec2.get_z());
	double z = (vec1.get_x() * vec2.get_y()) - (vec1.get_y() * vec2.get_x());
	Vector vec(x, y, z);
	return vec;
}