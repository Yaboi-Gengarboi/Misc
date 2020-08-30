// Vector3D.h
// Justyn P. Durnford
// Created on 1/18/2020
// Last updated on 2020-08-29
// Header file for the Vector3D class
// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "Point3f.hpp"

#include <ostream>
#include <string>

const double PI = 3.14159265358979323846;

class Vector3D
{
	double _x = 0;
	double _y = 0;
	double _z = 0;

	public:

	// Automatic Constructors
	Vector3D() = default;
	Vector3D(const Vector3D& v) = default;
	Vector3D& operator = (const Vector3D& v) = default;
	Vector3D(Vector3D&& v) = default;
	Vector3D& operator = (Vector3D&& v) = default;

	// Manual Constructors
	Vector3D(double x, double y, double z);
	Vector3D(const double v_arr[3]);
	Vector3D(const Point3f& pt);
	Vector3D(const Point3f& pt1, const Point3f& pt2);

	// Destructor
	~Vector3D() = default;

	// Returns _x
	double x() const;

	// Returns _y
	double y() const;

	// Returns _z
	double z() const;

	// Sets _x to x
	void setX(double x);

	// Sets _y to y
	void setY(double y);

	// Sets _z to z
	void setZ(double z);

	// Sets _x to x
	// Sets _y to y
	// Sets _z to z
	void setAll(double x, double y, double z);

	// Sets _x to v_arr[0]
	// Sets _y to v_arr[1]
	// Sets _z to v_arr[2]
	void setAll(const double v_arr[3]);

	// Sets _x to p.x()
	// Sets _y to p.y()
	// Sets _z to p.z()
	void setAll(const Point3f& p);

	// Sets _x to v.x()
	// Sets _y to v.y()
	// Sets _z to v.z()
	void setAll(const Vector3D& v);

	// Returns the magnitude of the Vector3D
	double magnitude() const;

	// Returns a std::string representation of the Vector3D
	// In the format "<_x, _y, _z>"
	std::string toString() const;

	Vector3D& operator += (const Vector3D& v);
	Vector3D& operator -= (const Vector3D& v);

	Vector3D& operator *= (double d);
	Vector3D& operator /= (double d);
};

Vector3D operator + (const Vector3D& v, const Vector3D& u);
Vector3D operator - (const Vector3D& v, const Vector3D& u);

Vector3D operator * (const Vector3D& v, double d);
Vector3D operator / (const Vector3D& v, double d);

bool operator == (const Vector3D& v, const Vector3D& u);
bool operator != (const Vector3D& v, const Vector3D& u);

std::ostream& operator << (std::ostream& os, const Vector3D& v);

// Returns the dot product of the 2 given Vector3Ds
double dot_product(const Vector3D& v, const Vector3D& u);

// Returns the cross product of the 2 given Vector3Ds
Vector3D cross_product(const Vector3D& v, const Vector3D& u);

// Returns the angle between v and u
double angle_between(const Vector3D& v, const Vector3D& u);

// Returns true if 
bool are_parallel(const Vector3D& v, const Vector3D& u);

// Returns true if dot_product(v, u) == PI / 2
bool are_normal(const Vector3D& v, const Vector3D& u);

// Returns the scalar projection of v onto u.
double scalar_proj(const Vector3D& v, const Vector3D& u);

// Returns the vector projection of v onto u.
Vector3D vector_proj(const Vector3D& v, const Vector3D& u);

#endif // VECTOR3D_H