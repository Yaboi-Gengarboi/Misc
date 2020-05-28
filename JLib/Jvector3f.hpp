// Jvector3f.hpp
// Justyn P. Durnford
// Created on 1/18/2020
// Last updated on 5/27/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#ifndef JVECTOR3F_HPP
#define JVECTOR3F_HPP

#include "Jpoint3f.hpp"

#include <string>

class Jvector3f
{
	Jpoint3f _origin;

	float _x = 0;
	float _y = 0;
	float _z = 0;

	public:

	Jvector3f();
	Jvector3f(float x, float y, float z);
	Jvector3f(const Jpoint3f& pt, float x, float y, float z);
	Jvector3f(const Jpoint3f& pt, float vec_arr[3]);
	Jvector3f(const Jvector3f& vec);

	~Jvector3f();

	Jpoint3f origin() const;

	float x() const;

	float y() const;

	float z() const;

	void setOrigin(const Jpoint3f& pt);

	void setOrigin(const float pt_arr[3]);

	void setX(float x);

	void setY(float y);

	void setZ(float z);

	float magnitude() const;

	std::string toString() const;

	Jpoint3f toPoint() const;
};

// Addition operator
Jvector3f operator + (const Jvector3f& vec1, const Jvector3f& vec2);
Jvector3f& operator += (Jvector3f& vec1, const Jvector3f& vec2);

// Subtraction operator
Jvector3f operator - (const Jvector3f& vec1, const Jvector3f& vec2);
Jvector3f& operator -= (Jvector3f& vec1, const Jvector3f& vec2);

// Muliplication operator
Jvector3f operator * (const Jvector3f& vec1, const Jvector3f& vec2);
Jvector3f& operator *= (Jvector3f& vec, float f);
Jvector3f& operator *= (Jvector3f& vec1, const Jvector3f& vec2);

// Division operator
Jvector3f operator / (const Jvector3f& vec1, const Jvector3f& vec2);
Jvector3f& operator /= (Jvector3f& vec, float f);
Jvector3f& operator /= (Jvector3f& vec1, const Jvector3f& vec2);

// Equality operator
bool operator == (const Jvector3f& vec1, const Jvector3f& vec2);

// Inequality operator
bool operator != (const Jvector3f& vec1, const Jvector3f& vec2);

#endif // JVECTOR3F_HPP