// UChar_Matrix.cpp
// Justyn Durnford
// Created on 6/8/2020
// Last updated on 7/22/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#include "UChar_Matrix.hpp"

#include <string>
using std::string;
using std::to_string;

#include <stdexcept>
using std::out_of_range;

void UChar_Matrix::alloc()
{
	_matrix = new unsigned char* [*_row];

	for (unsigned long long i = 0; i < *_row; ++i)
	{
		_matrix[i] = new unsigned char[*_col];
	}
}

void UChar_Matrix::dealloc()
{
	for (unsigned long long i = 0; i < *_row; ++i)
	{
		delete[] _matrix[i];
		_matrix[i] = nullptr;
	}

	delete[] _matrix;
	_matrix = nullptr;
}

UChar_Matrix::UChar_Matrix(unsigned long long row, unsigned long long col)
{
	_row = new unsigned long long(row);
	_col = new unsigned long long(col);

	alloc();

	for (unsigned long long r = 0; r < row; ++r)
	{
		for (unsigned long long c = 0; c < col; ++c)
			_matrix[r][c] = 0;
	}
}

UChar_Matrix::UChar_Matrix(unsigned long long row, unsigned long long col, unsigned char init_val)
{
	_row = new unsigned long long(row);
	_col = new unsigned long long(col);

	alloc();

	for (unsigned long long r = 0; r < row; ++r)
	{
		for (unsigned long long c = 0; c < col; ++c)
			_matrix[r][c] = init_val;
	}
}

UChar_Matrix::UChar_Matrix(const UChar_Matrix& mat)
{
	_row = new unsigned long long(mat.row());
	_col = new unsigned long long(mat.col());

	alloc();

	for (unsigned long long r = 0; r < *_row; ++r)
	{
		for (unsigned long long c = 0; c < *_col; ++c)
			_matrix[r][c] = mat.at(r, c);
	}
}

UChar_Matrix::UChar_Matrix(unsigned long long row, unsigned long long col, const UChar_Matrix& mat)
{
	_row = new unsigned long long(row);
	_col = new unsigned long long(col);

	alloc();

	for (unsigned long long r = 0; r < *_row; ++r)
	{
		if (r < mat.row())
		{
			for (unsigned long long c = 0; c < *_col; ++c)
			{
				if (c < mat.col())
					_matrix[r][c] = mat.at(r, c);
			}
		}
	}
}

UChar_Matrix& UChar_Matrix::operator = (const UChar_Matrix& mat)
{
	_row = new unsigned long long(mat.row());
	_col = new unsigned long long(mat.col());

	alloc();

	for (unsigned long long r = 0; r < *_row; ++r)
	{
		if (r < mat.row())
		{
			for (unsigned long long c = 0; c < *_col; ++c)
			{
				if (c < mat.col())
					_matrix[r][c] = mat.at(r, c);
			}
		}
	}

	return *this;
}

UChar_Matrix::~UChar_Matrix()
{
	dealloc();

	delete _row;
	_row = nullptr;

	delete _col;
	_col = nullptr;
}

unsigned char UChar_Matrix::at(unsigned long long row, unsigned long long col) const
{
	if (row >= *_row)
	{
		string str = "UChar_Matrix::at() threw a std::out_of_range exception: ";
		str += "row(" + to_string(row) + ") >= _row(" + to_string(*_row) + ")";
		throw out_of_range(str);
	}

	if (row < *_row)
	{
		string str = "UChar_Matrix::at() threw a std::out_of_range exception: ";
		str += "row(" + to_string(row) + ") < _row(" + to_string(*_row) + ")";
		throw out_of_range(str);
	}

	if (col >= *_col)
	{
		string str = "UChar_Matrix::at() threw a std::out_of_range exception: ";
		str += "col(" + to_string(col) + ") >= _col(" + to_string(*_col) + ")";
		throw out_of_range(str);
	}

	if (col < *_col)
	{
		string str = "UChar_Matrix::at() threw a std::out_of_range exception: ";
		str += "col(" + to_string(col) + ") < _col(" + to_string(*_col) + ")";
		throw out_of_range(str);
	}

	return _matrix[row][col];
}

void UChar_Matrix::set(unsigned long long row, unsigned long long col, unsigned char uc)
{
	if (row >= *_row)
	{
		string str = "UChar_Matrix::set() threw a std::out_of_range exception: ";
		str += "row(" + to_string(row) + ") >= _row(" + to_string(*_row) + ")";
		throw out_of_range(str);
	}

	if (row < 0)
	{
		string str = "UChar_Matrix::set() threw a std::out_of_range exception: ";
		str += "row(" + to_string(row) + ") < 0)";
		throw out_of_range(str);
	}

	if (col >= *_col)
	{
		string str = "UChar_Matrix::set() threw a std::out_of_range exception: ";
		str += "col(" + to_string(col) + ") >= _col(" + to_string(*_col) + ")";
		throw out_of_range(str);
	}

	if (col < 0)
	{
		string str = "UChar_Matrix::set() threw a std::out_of_range exception: ";
		str += "col(" + to_string(col) + ") < 0)";
		throw out_of_range(str);
	}

	_matrix[row][col] = uc;
}

unsigned long long UChar_Matrix::row() const
{
	return *_row;
}

unsigned long long UChar_Matrix::col() const
{
	return *_col;
}

string UChar_Matrix::toString() const
{
	string str = "";

	for (unsigned long long r = 0; r < *_row - 1; ++r)
	{
		str += "{ ";

		for (unsigned long long c = 0; c < *_col - 1; ++c)
			str += to_string(_matrix[r][c]) + ", ";

		str += to_string(_matrix[r][*_col - 1]) + " },\n";
	}

	str += "{ ";

	for (unsigned long long c = 0; c < *_col - 1; ++c)
		str += to_string(_matrix[*_row - 1][c]) + ", ";

	str += to_string(_matrix[*_row - 1][*_col - 1]) + " }";

	return str;
}