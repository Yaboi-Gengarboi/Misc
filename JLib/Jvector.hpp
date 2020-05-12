// Jvector.hpp
// Justyn P. Durnford
// Created on 1/18/2020
// Last updated on 4/30/2020

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