// RPGGame
// Matrix.hpp
// Justyn Durnford
// Created on 6/8/2020
// Last updated on 6/10/2020

#ifndef MATRIX_HPP
#define MATRIX_HPP

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
	unsigned int* _row = nullptr;
	unsigned int* _col = nullptr;

	void alloc();
	void dealloc();
	void realloc(unsigned int row, unsigned int col);

	public:

	UChar_Matrix();
	UChar_Matrix(unsigned int row, unsigned int col);
	UChar_Matrix(unsigned int row, unsigned int col, unsigned char init_val);
	UChar_Matrix(const UChar_Matrix& mat);
	UChar_Matrix(unsigned int row, unsigned int col, const UChar_Matrix& mat);
	// UChar_Matrix& operator = (const Matrix& mat);

	~UChar_Matrix();

	unsigned char at(unsigned int row, unsigned int col) const;

	void set(unsigned int row, unsigned int col, unsigned char uc);

	unsigned int row() const;
	unsigned int col() const;

	void setRow(unsigned int row);
	void setCol(unsigned int col);

	std::string toString() const;
};

#endif // MATRIX_HPP