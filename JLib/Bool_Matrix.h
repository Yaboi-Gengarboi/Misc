// Bool_Matrix.h
// Justyn Durnford
// Created on 7/22/2020
// Last updated on 7/22/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#ifndef BOOL_MATRIX_H
#define BOOL_MATRIX_H

#include <vector>
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
class Bool_Matrix
{
	std::vector<std::vector<bool>> _matrix;
	unsigned long long* _row = nullptr;
	unsigned long long* _col = nullptr;

	void alloc();
	void dealloc();

	Bool_Matrix(unsigned long long row, unsigned long long col);
	Bool_Matrix(unsigned long long row, unsigned long long col, bool init_val);
	Bool_Matrix(const Bool_Matrix& mat);
	Bool_Matrix(unsigned long long row, unsigned long long col, const Bool_Matrix& mat);
	Bool_Matrix& operator = (const Bool_Matrix& mat) = default;

	~Bool_Matrix();

	bool at(unsigned long long row, unsigned long long col) const;

	void set(unsigned long long row, unsigned long long col, bool b);

	unsigned long long row() const;
	unsigned long long col() const;

	std::string toString() const;
};

#endif // BOOL_MATRIX_H