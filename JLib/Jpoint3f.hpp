// Jpoint3f.hpp
// Justyn P. Durnford
// Created on 1/13/2020
// Last updated on 5/18/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

// This class allows for the representation of a
// single point in 3 dimensional space.
// A Jpoint3f can be constructed by default, with 3 doubles, with a
// C-array or with another Jpoint3f.
// Jpoint3fs are not capable of arithmetic on their own due to
// their static nature, but there are functions that work with
// points.
// Jpoint3fs can be compared to other Jpoint3fs or C-arrays of doubles.
// A Jpoint3f can be represented as a std::string with the toString method.

#ifndef JPOINT3F_HPP
#define JPOINT3F_HPP

#include <string>

class Jpoint3f
{
	float _x = 0;
	float _y = 0;
	float _z = 0;

	public:

	//Constructors
	Jpoint3f();
	Jpoint3f(float x, float y, float z);
	Jpoint3f(float pt_arr[3]);
	Jpoint3f(const Jpoint3f& pt);

	// Destructor
	~Jpoint3f();

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
	Jpoint3f copy() const;

	// Returns a std::string representation of the Jpoint3D
	std::string toString() const;
};

// Uses the distance formula to calculate the distance between
// the two given Jpoint3Ds
float distance(const Jpoint3f& pt1, const Jpoint3f& pt2);

// Equality operator
bool operator == (const Jpoint3f& pt1, const Jpoint3f& pt2);
bool operator == (const Jpoint3f& pt, float pt_arr[3]);

// Inequality operator
bool operator != (const Jpoint3f& pt1, const Jpoint3f& pt2);
bool operator != (const Jpoint3f& pt, float pt_arr[3]);

#endif // JPOINT3D_HPP