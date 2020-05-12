// Jmatrix.hpp
// Justyn Durnford
// Created on 4/6/2020
// Last updated on 4/15/2020

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