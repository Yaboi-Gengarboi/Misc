// Matrix.cpp
// Justyn Durnford
// Created on 2020-08-30
// Last updated on 2020-08-30
// Source file for Matrix class
// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#include "Matrix.h"

#include <stdexcept>
using std::out_of_range;

#include <string>
using std::string;
using std::to_string;

#include <vector>
using std::vector;
using std::size_t;

Matrix::Matrix(const size_t& row, const size_t& col)
{
	for (size_t r = 0; r < row; ++r)
	{
		for (size_t c = 0; c < col; ++c)
			_matrix[r][c] = 0;
	}
}

Matrix::Matrix(const size_t& row, const size_t& col, double init_val)
{
	for (size_t r = 0; r < row; ++r)
	{
		for (size_t c = 0; c < col; ++c)
			_matrix[r][c] = init_val;
	}
}

double Matrix::at(const size_t& row, const size_t& col) const
{
	if (row >= rows())
	{
		string str = "Matrix::at() threw a std::out_of_range exception: ";
		str += "rows(" + to_string(row) + ") >= rows(" + to_string(rows()) + ")";
		throw out_of_range(str);
	}

	if (row < rows())
	{
		string str = "Matrix::at() threw a std::out_of_range exception: ";
		str += "rows(" + to_string(row) + ") < rows(" + to_string(rows()) + ")";
		throw out_of_range(str);
	}

	if (col >= cols())
	{
		string str = "Matrix::at() threw a std::out_of_range exception: ";
		str += "cols(" + to_string(cols()) + ") >= cols(" + to_string(cols()) + ")";
		throw out_of_range(str);
	}

	if (col < cols())
	{
		string str = "Matrix::at() threw a std::out_of_range exception: ";
		str += "cols(" + to_string(col) + ") < cols(" + to_string(cols()) + ")";
		throw out_of_range(str);
	}

	return _matrix[row][col];
}

void Matrix::set(const size_t& row, const size_t& col, double d)
{
	if (row >= rows())
	{
		string str = "Matrix::set() threw a std::out_of_range exception: ";
		str += "rows(" + to_string(row) + ") >= rows(" + to_string(rows()) + ")";
		throw out_of_range(str);
	}

	if (row < rows())
	{
		string str = "Matrix::set() threw a std::out_of_range exception: ";
		str += "rows(" + to_string(row) + ") < rows(" + to_string(rows()) + ")";
		throw out_of_range(str);
	}

	if (col >= cols())
	{
		string str = "Matrix::set() threw a std::out_of_range exception: ";
		str += "cols(" + to_string(cols()) + ") >= cols(" + to_string(cols()) + ")";
		throw out_of_range(str);
	}

	if (col < cols())
	{
		string str = "Matrix::set() threw a std::out_of_range exception: ";
		str += "cols(" + to_string(col) + ") < cols(" + to_string(cols()) + ")";
		throw out_of_range(str);
	}

	_matrix[row][col] = d;
}

size_t Matrix::rows() const
{
	return _matrix.size();
}

size_t Matrix::cols() const
{
	if (rows() != 0)
		return _matrix[0].size();

	return 0;
}

string Matrix::toString() const
{
	string str = "";

	for (size_t r = 0; r < rows() - 1; ++r)
	{
		str += "{ ";

		for (size_t c = 0; c < cols() - 1; ++c)
			str += to_string(_matrix[r][c]) + ", ";

		str += to_string(_matrix[r][cols() - 1]) + " },\n";
	}

	str += "{ ";

	for (size_t c = 0; c < cols() - 1; ++c)
		str += to_string(_matrix[cols() - 1][c]) + ", ";

	str += to_string(_matrix[rows() - 1][cols() - 1]) + " }";

	return str;
}