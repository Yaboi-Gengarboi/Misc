// Point3D.h
// Justyn P.Durnford
// Created on 2020-01-13
// Last updated on 2020-09-16
// Header file for Point3D class
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

#ifndef POINT3D_H
#define POINT3D_H

#include <ostream>
#include <string>

// This class allows for the representation of a
// single point in 3 dimensional space.
class Point3D
{
	double _x = 0;
	double _y = 0;
	double _z = 0;

	// Sets _x to x if set == 0 or 3
	// Sets _y to y if set == 1 or 3
	// Sets _z to z if set == 2 or 3
	void setValues(double x, double y, double z, char set);

	public:

	// Constructors.
	Point3D() = default;
	Point3D(const Point3D& p) = default;
	Point3D(Point3D&& p) = default;
	Point3D(double x, double y, double z);
	Point3D(const double p_arr[3]);

	// Assignment operators.
	Point3D& operator = (const Point3D& p) = default;
	Point3D& operator = (Point3D&& p) = default;

	// Destructor.
	~Point3D() = default;

	// Returns _x.
	double x() const;

	// Returns _y.
	double y() const;

	// Returns _z.
	double z() const;

	// Sets the value of _x to x.
	void setX(double x);

	// Sets the value of _y to y.
	void setY(double y);

	// Sets the value of _z to z.
	void setZ(double z);

	// Sets _x to x.
	// Sets _y to y.
	// Sets _z to z.
	void setAll(double x, double y, double z);

	// Sets _x to p_arr[0].
	// Sets _y to p_arr[1].
	// Sets _z to p_arr[2].
	void setAll(const double p_arr[3]);

	// Sets _x to p.x().
	// Sets _y to p.y().
	// Sets _z to p.z().
	void setAll(const Point3D& p);

	// Clears the values of the Point3D.
	void clear();

	// Returns a std::string representation of the Point3D
	// in the format "(_x, _y, _z)".
	std::string toString() const;
};

// Uses the distance formula to calculate the distance between
// the two given Point3Ds
double distance(const Point3D& p, const Point3D& q);

// Equality comparison operator.
bool operator == (const Point3D& p, const Point3D& q);

// Inequality comparison operator.
bool operator != (const Point3D& p, const Point3D& q);

#endif // POINT3D_H