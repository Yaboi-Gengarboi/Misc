// Vector3D.h
// Justyn P. Durnford
// Created on 2020-01-18
// Last updated on 2020-09-16
// Header file for the Vector3D class
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

#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "Constants.h"
#include "Point3D.h"

#include <ostream>
#include <string>

class Vector3D
{
	double _x = 0;
	double _y = 0;
	double _z = 0;

	// Sets _x to x if set == 0 or 3.
	// Sets _y to y if set == 1 or 3.
	// Sets _z to z if set == 2 or 3.
	void setValues(double x, double y, double z, char set);

	public:

	// Constructors.
	Vector3D() = default;
	Vector3D(const Vector3D& v) = default;
	Vector3D(Vector3D&& v) = default;
	Vector3D(double x, double y, double z);
	Vector3D(const double v_arr[3]);
	Vector3D(const Point3D& p);
	Vector3D(const Point3D& p, const Point3D& q);

	// Assignment operators.
	Vector3D& operator = (const Vector3D& v) = default;
	Vector3D& operator = (Vector3D&& v) = default;

	// Destructor.
	~Vector3D() = default;

	// Returns _x.
	double x() const;

	// Returns _y.
	double y() const;

	// Returns _z.
	double z() const;

	// Sets _x to x.
	void setX(double x);

	// Sets _y to y.
	void setY(double y);

	// Sets _z to z.
	void setZ(double z);

	// Sets _x to x.
	// Sets _y to y.
	// Sets _z to z.
	void setAll(double x, double y, double z);

	// Sets _x to v_arr[0].
	// Sets _y to v_arr[1].
	// Sets _z to v_arr[2].
	void setAll(const double v_arr[3]);

	// Sets _x to p.x().
	// Sets _y to p.y().
	// Sets _z to p.z().
	void setAll(const Point3D& p);

	// Sets _x to v.x().
	// Sets _y to v.y().
	// Sets _z to v.z().
	void setAll(const Vector3D& v);

	// Clears the values of the Vector3D.
	void clear();

	// Returns the magnitude of the Vector3D.
	double magnitude() const;

	// Returns a std::string representation of the Vector3D
	// in the format "<_x, _y, _z>".
	std::string toString() const;

	// Addition assignment operator.
	Vector3D& operator += (const Vector3D& v);

	// Subtraction assignment operator.
	Vector3D& operator -= (const Vector3D& v);

	// Multiplication assignment operator.
	Vector3D& operator *= (double d);

	// Division assignment operator.
	Vector3D& operator /= (double d);
};

// Addition operator.
Vector3D operator + (const Vector3D& v, const Vector3D& u);

// Subtraction operator.
Vector3D operator - (const Vector3D& v, const Vector3D& u);

// Multiplication operator.
Vector3D operator * (const Vector3D& v, double d);

// Division operators.
Vector3D operator / (const Vector3D& v, double d);

// Equality comparison operator.
bool operator == (const Vector3D& v, const Vector3D& u);

// Inequality comparison operator.
bool operator != (const Vector3D& v, const Vector3D& u);

// ostream insertion operator.
std::ostream& operator << (std::ostream& os, const Vector3D& v);

// Returns the dot product of the 2 given Vector3Ds.
double dot_product(const Vector3D& v, const Vector3D& u);

// Returns the cross product of the 2 given Vector3Ds.
Vector3D cross_product(const Vector3D& v, const Vector3D& u);

// Returns the angle between v and u.
double angle_between(const Vector3D& v, const Vector3D& u);

// Returns true if 
bool are_parallel(const Vector3D& v, const Vector3D& u);

// Returns true if dot_product(v, u) == JLib::PI / 2.
bool are_normal(const Vector3D& v, const Vector3D& u);

// Returns the scalar projection of v onto u.
double scalar_proj(const Vector3D& v, const Vector3D& u);

// Returns the vector projection of v onto u.
Vector3D vector_proj(const Vector3D& v, const Vector3D& u);

#endif // VECTOR3D_H