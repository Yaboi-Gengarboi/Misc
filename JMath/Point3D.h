// Point3D.hp
// Justyn P. Durnford
// Created on 2020-01-13
// Last updated on 2020-08-30
// Header file for Point3D class
// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

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

	public:

	// Automatic Constructors
	Point3D() = default;
	Point3D(const Point3D& v) = default;
	Point3D& operator = (const Point3D& v) = default;
	Point3D(Point3D&& v) = default;
	Point3D& operator = (Point3D&& v) = default;

	// Manual Constructors
	Point3D(double x, double y, double z);
	Point3D(const double p_arr[3]);

	// Destructor
	~Point3D();

	// Returns _x
	double x() const;

	// Returns _y
	double y() const;

	// Returns _z
	double z() const;

	// Sets the value of _x to x
	void setX(double x);

	// Sets the value of _y to y
	void setY(double y);

	// Sets the value of _z to z
	void setZ(double z);

	// Sets _x to x
	// Sets _y to y
	// Sets _z to z
	void setAll(double x, double y, double z);

	// Sets _x to p_arr[0]
	// Sets _y to p_arr[1]
	// Sets _z to p_arr[2]
	void setAll(const double p_arr[3]);

	// Sets _x to p.x()
	// Sets _y to p.y()
	// Sets _z to p.z()
	void setAll(const Point3D& p);

	// Clears the values of the Point3D
	void clear();

	// Returns a new copy of the Point3D
	Point3D copy() const;

	// Returns a std::string representation of the Point3D
	// in the format "(_x, _y, _z)"
	std::string toString() const;
};

// Uses the distance formula to calculate the distance between
// the two given Point3Ds
double distance(const Point3D& p, const Point3D& q);

bool operator == (const Point3D& p, const Point3D& q);
bool operator != (const Point3D& p, const Point3D& q);

#endif // POINT3D_H