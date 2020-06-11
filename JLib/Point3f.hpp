// Point3f.hpp
// Justyn P. Durnford
// Created on 1/13/2020
// Last updated on 6/11/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

// This class allows for the representation of a
// single point in 3 dimensional space.
// A Point3f can be constructed by default, with 3 doubles, with a
// C-array or with another Point3f.
// Point3fs are not capable of arithmetic on their own due to
// their static nature, but there are functions that work with
// points.
// Point3fs can be compared to other Point3fs or C-arrays of doubles.
// A Point3f can be represented as a std::string with the toString method.

#ifndef POINT3F_HPP
#define POINT3F_HPP

#include <string>

class Point3f
{
	float _x = 0;
	float _y = 0;
	float _z = 0;

	public:

	//Constructors
	Point3f();
	Point3f(float x, float y, float z);
	Point3f(float pt_arr[3]);
	Point3f(const Point3f& pt);

	// Destructor
	~Point3f();

	// Returns _x
	float x() const;

	// Returns _y
	float y() const;

	// Returns _z
	float z() const;

	// Sets the value of _x to x
	void setX(float x);

	// Sets the value of _y to y
	void setY(float y);

	// Sets the value of _z to z
	void setZ(float z);

	// Clears the values of the Jpoint3D
	void clear();

	// Returns a new copy of the Jpoint3D
	Point3f copy() const;

	// Returns a std::string representation of the Jpoint3D
	std::string toString() const;
};

// Uses the distance formula to calculate the distance between
// the two given Jpoint3Ds
float distance(const Point3f& pt1, const Point3f& pt2);

// Equality operator
bool operator == (const Point3f& pt1, const Point3f& pt2);
bool operator == (const Point3f& pt, float pt_arr[3]);

// Inequality operator
bool operator != (const Point3f& pt1, const Point3f& pt2);
bool operator != (const Point3f& pt, float pt_arr[3]);

#endif // JPOINT3D_HPP