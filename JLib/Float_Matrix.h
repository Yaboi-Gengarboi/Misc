// Float_Matrix.h
// Justyn Durnford
// Created on 7/22/2020
// Last updated on 7/22/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#ifndef FLOAT_MATRIX_H
#define FLOAT_MATRIX_H

#include <string>

// This class is able to function as a 
//
//
// This class manages its own memory. Do not
// create an object of this class on the heap.
//
// WARNING: This class CAN THROW AN EXCEPTION if 
// the at() or set() member functions are handed 
// parameters such that the function would atempt 
// to access out-of-bounds memory.
class Float_Matrix
{
	float** _matrix = nullptr;
	unsigned long long* _row = nullptr;
	unsigned long long* _col = nullptr;

	void alloc();
	void dealloc();

	Float_Matrix(unsigned long long row, unsigned long long col);
	Float_Matrix(unsigned long long row, unsigned long long col, float init_val);
	Float_Matrix(const Float_Matrix& mat);
	Float_Matrix(unsigned long long row, unsigned long long col, const Float_Matrix& mat);
	Float_Matrix& operator = (const Float_Matrix& mat);

	~Float_Matrix();

	float at(unsigned long long row, unsigned long long col) const;

	void set(unsigned long long row, unsigned long long col, float uc);

	unsigned long long row() const;
	unsigned long long col() const;

	std::string toString() const;
};

#endif // FLOAT_MATRIX_H