// JVector.hpp
// Justyn Durnford
// Created on 3/24/2020
// Last updated on 3/24/2020

#ifndef JVECTOR_HPP
#define JVECTOR_HPP

#include "JPoint.hpp"
// <string>

class JVector
{
	double _x = 0.0;
	double _y = 0.0;
	double _z = 0.0;

	public:

	// Constructors
	JVector();
	JVector(double x, double y, double z);
	JVector(double vec_arr[3]);
	JVector(const JPoint& pt1, const JPoint& pt2);

	// Destructor
	~JVector();

	// Returns the specified value.
	double getX() const;
	double getY() const;
	double getZ() const;

	// Sets the specified value to the given value.
	void setX(double x);
	void setY(double y);
	void setZ(double z);

	// Adds the given JVector vec onto the JVector.
	void add(const JVector& vec);

	// Subtracts the given JVector vec from the JVector.
	void subtract(const JVector& vec);

	// Returns a new copy of the JVector.
	JVector copy() const;

	// Copy operator
	JVector& operator = (const JVector& vec);

	// Multiplies the given scalar onto the JVector.
	void scale(double scalar);

	// Clears the values of the JVector.
	void clear();

	// Returns the length or magnitude of the Vector.
	double magnitude() const;

	// Returns a std::string representation of the JVector.
	std::string toString() const;

	//
	JPoint toJPoint() const;
};

// Returns the dot-product of JVector vec1 and vec2.
double dot_product(const JVector& vec1, const JVector& vec2);

// Returns the cross-product of JVector vec1 and vec2.
JVector cross_product(const JVector& vec1, const JVector& vec2);

// Returns the scalar projection of JVector vec1 onto vec2.
double scal_proj(const JVector& vec1, const JVector& vec2);

// Returns the vector projection of JVector vec1 onto vec2.
JVector vec_proj(const JVector& vec1, const JVector& vec2);

// Equality operator
bool operator == (const JVector& vec1, const JVector& vec2);

// Inequality operator
bool operator != (const JVector& vec1, const JVector& vec2);

#endif // JVECTOR_HPP