// Vector3f.hpp
// Justyn P. Durnford
// Created on 1/18/2020
// Last updated on 6/11/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#ifndef VECTOR3F_HPP
#define VECTOR3F_HPP

#include "Point3f.hpp"

#include <string>

class Vector3f
{
	Point3f _origin;

	float _x = 0;
	float _y = 0;
	float _z = 0;

	public:

	Vector3f();
	Vector3f(float x, float y, float z);
	Vector3f(const Point3f& pt, float x, float y, float z);
	Vector3f(const Point3f& pt, float vec_arr[3]);
	Vector3f(const Vector3f& vec);

	~Vector3f();

	Point3f origin() const;

	float x() const;

	float y() const;

	float z() const;

	void setOrigin(const Point3f& pt);

	void setOrigin(const float pt_arr[3]);

	void setX(float x);

	void setY(float y);

	void setZ(float z);

	float magnitude() const;

	std::string toString() const;

	Point3f toPoint() const;
};

// Addition operator
Vector3f operator + (const Vector3f& vec1, const Vector3f& vec2);
Vector3f& operator += (Vector3f& vec1, const Vector3f& vec2);

// Subtraction operator
Vector3f operator - (const Vector3f& vec1, const Vector3f& vec2);
Vector3f& operator -= (Vector3f& vec1, const Vector3f& vec2);

// Muliplication operator
Vector3f operator * (const Vector3f& vec1, const Vector3f& vec2);
Vector3f& operator *= (Vector3f& vec, float f);
Vector3f& operator *= (Vector3f& vec1, const Vector3f& vec2);

// Division operator
Vector3f operator / (const Vector3f& vec1, const Vector3f& vec2);
Vector3f& operator /= (Vector3f& vec, float f);
Vector3f& operator /= (Vector3f& vec1, const Vector3f& vec2);

// Equality operator
bool operator == (const Vector3f& vec1, const Vector3f& vec2);

// Inequality operator
bool operator != (const Vector3f& vec1, const Vector3f& vec2);

#endif // VECTOR3F_HPP