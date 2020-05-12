// Jvector.hpp
// Justyn P. Durnford
// Created on 1/18/2020
// Last updated on 5/11/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#ifndef JVECTOR_HPP
#define JVECTOR_HPP

#include <string>

class Jvector
{
	double _x = 0;
	double _y = 0;
	double _z = 0;

	public:

	Jvector();
	Jvector(double x, double y, double z);
	Jvector(double vec_arr[3]);
	Jvector(const Jvector& vec);

	~Jvector();

	double x() const;

	double y() const;

	double z() const;

	void setX(double d);

	void setY(double d);

	void setZ(double d);

	std::string toString() const;
};

#endif // JVECTOR_HPP