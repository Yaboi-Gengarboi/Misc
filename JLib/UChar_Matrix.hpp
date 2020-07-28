// UChar_Matrix.hpp
// Justyn Durnford
// Created on 6/8/2020
// Last updated on 7/22/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#ifndef UCHAR_MATRIX_HPP
#define UCHAR_MATRIX_HPP

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
class UChar_Matrix
{
	unsigned char** _matrix = nullptr;
	unsigned long long* _row = nullptr;
	unsigned long long* _col = nullptr;

	void alloc();
	void dealloc();

	public:

	UChar_Matrix(unsigned long long row, unsigned long long col);
	UChar_Matrix(unsigned long long row, unsigned long long col, unsigned char init_val);
	UChar_Matrix(const UChar_Matrix& mat);
	UChar_Matrix(unsigned long long row, unsigned long long col, const UChar_Matrix& mat);
	UChar_Matrix& operator = (const UChar_Matrix& mat);

	~UChar_Matrix();

	unsigned char at(unsigned long long row, unsigned long long col) const;

	void set(unsigned long long row, unsigned long long col, unsigned char uc);

	unsigned long long row() const;
	unsigned long long col() const;

	std::string toString() const;
};

#endif // UCHAR_MATRIX_HPP