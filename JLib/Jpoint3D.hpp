// Jpoint3D.hpp
// Justyn P. Durnford
// Created on 1/13/2020
// Last updated on 5/14/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

// This class allows for the representation of a
// single point in 3 dimensional space.
// A Jpoint3D can be constructed by default, with 3 doubles, with a
// C-array or with another Jpoint3D.
// Jpoint3Ds are not capable of arithmetic on their own due to
// their static nature, but there are functions that work with
// points.
// Jpoint3Ds can be compared to other Jpoint3D3Ds or C-arrays of doubles.
// A Jpoint3D can be represented as a std::string with the toString method.

#ifndef JPOINT3D_HPP
#define JPOINT3D_HPP

#include <string>

class Jpoint3D
{
	double _x = 0;
	double _y = 0;
	double _z = 0;

	public:

	//Constructors
	Jpoint3D();
	Jpoint3D(double x, double y, double z);
	Jpoint3D(double pt_arr[3]);
	Jpoint3D(const Jpoint3D& pt);

	// Destructor
	~Jpoint3D();

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

	// Clears the values of the Jpoint3D
	void clear();

	// Returns a new copy of the Jpoint3D
	Jpoint3D copy() const;

	// Returns a std::string representation of the Jpoint3D
	std::string toString() const;
};

// Uses the distance formula to calculate the distance between
// the two given Jpoint3Ds
double distance(const Jpoint3D& pt1, const Jpoint3D& pt2);

// Equality operator
bool operator == (const Jpoint3D& pt1, const Jpoint3D& pt2);
bool operator == (const Jpoint3D& pt, double pt_arr[3]);

// Inequality operator
bool operator != (const Jpoint3D& pt1, const Jpoint3D& pt2);
bool operator != (const Jpoint3D& pt, double pt_arr[3]);

#endif // JPOINT3D_HPP