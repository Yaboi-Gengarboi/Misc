// Jpoint.hpp
// Justyn P. Durnford
// Created on 1/13/2020
// Last Updated on 4/27/2020

// This class allows for the representation of a
// single point in 3 dimensional space.
// A Jpoint can be constructed by default, with 3 doubles, with a
// C-array or with another Jpoint.
// Jpoints are not capable of arithmetic on their own due to
// their static nature, but there are functions that work with
// points.
// Jpoints can be compared to other Jpoints or C-arrays of doubles.
// A Jpoint can be represented as a std::string with the toString method.

#ifndef JPOINT_HPP
#define JPOINT_HPP

#include <string>

class Jpoint
{
	double _x = 0;
	double _y = 0;
	double _z = 0;

	public:

	//Constructors
	Jpoint();
	Jpoint(double x, double y, double z);
	Jpoint(double pt_arr[3]);
	Jpoint(const Jpoint& pt);

	// Destructor
	~Jpoint();

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

	// Clears the values of the Jpoint
	void clear();

	// Returns a new copy of the Jpoint
	Jpoint copy() const;

	// Returns a std::string representation of the Jpoint
	std::string toString() const;
};

// Uses the distance formula to calculate the distance between
// the two given Jpoints
double distance(const Jpoint& pt1, const Jpoint& pt2);

// Equality operator
bool operator == (const Jpoint& pt1, const Jpoint& pt2);
bool operator == (const Jpoint& pt, double pt_arr[3]);

// Inequality operator
bool operator != (const Jpoint& pt1, const Jpoint& pt2);
bool operator != (const Jpoint& pt, double pt_arr[3]);

#endif // JPOINT_HPP