// Jvector3f.hpp
// Justyn P. Durnford
// Created on 1/18/2020
// Last updated on 5/18/2020

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
	Jvector3f(double x, double y, double z);
	Jvector3f(double vec_arr[3]);
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
};

#endif // JVECTOR3F_HPP