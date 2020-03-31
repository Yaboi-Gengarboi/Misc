// JPoint.hpp
// Justyn P. Durnford
// Created on 1/13/2020
// Last Updated on 3/31/2020
// https://github.com/Yaboi-Gengarboi/Misc/blob/master/JLib/Point.hpp



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
	JPoint& operator = (const JPoint& pt);

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
};

// Uses the distance formula to calculate the distance between
// the two given points
double distance(const JPoint& pt1, const JPoint& pt2);

// Equality operator
bool operator == (const JPoint& pt1, const JPoint& pt2);

// Inequality operator
bool operator != (const JPoint& pt1, const JPoint& pt2);

#endif // JPOINT_HPP