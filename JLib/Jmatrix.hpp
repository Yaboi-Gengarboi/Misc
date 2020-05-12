// Jmatrix.hpp
// Justyn Durnford
// Created on 4/6/2020
// Last updated on 5/11/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#ifndef JMATRIX_HPP
#define JMATRIX_HPP

#include <string>

class Jmatrix
{
	double** _matrix = nullptr;
	unsigned int* _rows = nullptr;
	unsigned int* _cols = nullptr;

	void alloc();
	void realloc();

	public:

	Jmatrix();
	Jmatrix(unsigned int rows, unsigned int cols);
	Jmatrix(unsigned int rows, unsigned int cols, double init_val);
	Jmatrix(const Jmatrix& mat);
	Jmatrix& operator = (const Jmatrix& mat);

	~Jmatrix();

	unsigned int rows() const;
	unsigned int cols() const;

	void setRows(unsigned int rows);
	void setCols(unsigned int cols);

	std::string toString() const;
};

#endif // JMATRIX_HPP