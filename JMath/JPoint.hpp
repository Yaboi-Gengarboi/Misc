// JPoint.hpp
// Justyn P. Durnford
// Created on 1/13/2020
// Last Updated on 4/2/2020

// This class allows for the representation of a
// single point in 3 dimensional space. 
// A JPoint can be constructed by default, with 3 doubles, with a
// C-array or with another JPoint.
// JPoints are not capable of arithmetic on their own due to
// their static nature, but there are functions that work with
// points.
// JPoints can be compared to other JPoints or C-arrays of doubles.
// A JPoint can be represented as a std::string with the toString method.

#ifndef JPOINT_HPP
#define JPOINT_HPP

#include <string>

class JPoint
{
	double _x = 0.0;
	double _y = 0.0;
	double _z = 0.0;

	public:

	//Constructors
	JPoint();
	JPoint(double x, double y, double z);
	JPoint(double pt_arr[3]);
	JPoint(const JPoint& pt);

	// Destructor
	~JPoint();

	// Returns _x.
	double getX() const;

	// Returns _y
	double getY() const;

	// Returns _z
	double getZ() const;

	// Sets the value of _x to x
	void setX(double x);

	// Sets the value of _y to y
	void setY(double y);

	// Sets the value of _z to z
	void setZ(double z);

	// Clears the values of the JPoint
	void clear();

	// Returns a new copy of the JPoint
	JPoint copy() const;

	// Returns a std::string representation of the JPoint
	std::string toString() const;

	JPoint operator = (const JPoint& pt);
	JPoint operator = (double pt_arr[3]);
};

// Uses the distance formula to calculate the distance between
// the two given JPoints
double distance(const JPoint& pt1, const JPoint& pt2);

// Equality operator
bool operator == (const JPoint& pt1, const JPoint& pt2);
bool operator == (const JPoint& pt, double pt_arr[3]);

// Inequality operator
bool operator != (const JPoint& pt1, const JPoint& pt2);
bool operator != (const JPoint& pt, double pt_arr[3]);

#endif // JPOINT_HPP