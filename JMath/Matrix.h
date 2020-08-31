// Matrix.h
// Justyn Durnford
// Created on 2020-08-30
// Last updated on 2020-08-30
// Header file for Matrix class
// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <vector>

class Matrix
{
	std::vector<std::vector<double>> _matrix;

	// Automatic Constructors
	Matrix() = default;
	Matrix(const Matrix & m) = default;
	Matrix& operator = (const Matrix & m) = default;
	Matrix(Matrix && m) = default;
	Matrix& operator = (Matrix && m) = default;

	// Manual Constructors
	Matrix(const std::size_t& row, const std::size_t& col);
	Matrix(const std::size_t& row, const std::size_t& col, double init_val);

	// Destructor
	~Matrix() = default;

	// Returns _matrix[_row][_col]
	double at(const std::size_t& row, const std::size_t& col) const;

	// Sets _matrix[_row][_col] to val
	void set(const std::size_t& row, const std::size_t& col, double val);

	// Returns _matrix.size()
	std::size_t rows() const;

	// Returns _matrix[0].size()
	std::size_t cols() const;

	// Returns a std::string representation of the Matrix
	std::string toString() const;
};

#endif // MATRIX_H