// RPGGame
// Matrix.cpp
// Justyn Durnford
// Created on 6/8/2020
// Last updated on 6/10/2020

#include "Matrix.hpp"

#include <string>
using std::string;
using std::to_string;

#include <stdexcept>
using std::out_of_range;

void UChar_Matrix::alloc()
{
	_matrix = new unsigned char* [*_row];

	for (unsigned int i = 0; i < *_row; ++i)
	{
		_matrix[i] = new unsigned char[*_col];
	}
}

void UChar_Matrix::dealloc()
{
	for (unsigned int i = 0; i < *_row; ++i)
	{
		delete[] _matrix[i];
		_matrix[i] = nullptr;
	}

	delete[] _matrix;
	_matrix = nullptr;
}

void UChar_Matrix::realloc(unsigned int row, unsigned int col)
{
	UChar_Matrix copy(*this);
	dealloc();

	*_row = row;
	*_col = col;
	alloc();

	for (unsigned int r = 0; r < row; ++r)
	{
		if (r < copy.row())
		{
			for (unsigned int c = 0; c < col; ++c)
			{
				if (c < copy.col())
					_matrix[r][c] = copy.at(r, c);
			}
		}
	}
}

UChar_Matrix::UChar_Matrix()
{
	_row = new unsigned int(1);
	_col = new unsigned int(1);

	alloc();

	_matrix[0][0] = 0;
}

UChar_Matrix::UChar_Matrix(unsigned int row, unsigned int col)
{
	_row = new unsigned int(row);
	_col = new unsigned int(col);

	alloc();

	for (unsigned int r = 0; r < row; ++r)
	{
		for (unsigned int c = 0; c < col; ++c)
			_matrix[r][c] = 0;
	}
}

UChar_Matrix::UChar_Matrix(unsigned int row, unsigned int col, unsigned char init_val)
{
	_row = new unsigned int(row);
	_col = new unsigned int(col);

	alloc();

	for (unsigned int r = 0; r < row; ++r)
	{
		for (unsigned int c = 0; c < col; ++c)
			_matrix[r][c] = init_val;
	}
}

UChar_Matrix::UChar_Matrix(const UChar_Matrix& mat)
{
	_row = new unsigned int(mat.row());
	_col = new unsigned int(mat.col());

	alloc();

	for (unsigned int r = 0; r < *_row; ++r)
	{
		for (unsigned int c = 0; c < *_col; ++c)
			_matrix[r][c] = mat.at(r, c);
	}
}

UChar_Matrix::UChar_Matrix(unsigned int row, unsigned int col, const UChar_Matrix& mat)
{
	_row = new unsigned int(row);
	_col = new unsigned int(col);

	alloc();

	for (unsigned int r = 0; r < *_row; ++r)
	{
		if (r < mat.row())
		{
			for (unsigned int c = 0; c < *_col; ++c)
			{
				if (c < mat.col())
					_matrix[r][c] = mat.at(r, c);
			}
		}
	}
}

UChar_Matrix::~UChar_Matrix()
{
	dealloc();

	delete _row;
	_row = nullptr;

	delete _col;
	_col = nullptr;
}

unsigned char UChar_Matrix::at(unsigned int row, unsigned int col) const
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

void UChar_Matrix::set(unsigned int row, unsigned int col, unsigned char uc)
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

unsigned int UChar_Matrix::row() const
{
	return *_row;
}

unsigned int UChar_Matrix::col() const
{
	return *_col;
}

void UChar_Matrix::setRow(unsigned int row)
{
	*_row = row;
	realloc(*_row, *_col);
}

void UChar_Matrix::setCol(unsigned int col)
{
	*_col = col;
	realloc(*_row, *_col);
}

string UChar_Matrix::toString() const
{
	string str = "";

	for (unsigned int r = 0; r < *_row - 1; ++r)
	{
		str += "{ ";

		for (unsigned int c = 0; c < *_col - 1; ++c)
			str += to_string(_matrix[r][c]) + ", ";

		str += to_string(_matrix[r][*_col - 1]) + " },\n";
	}

	str += "{ ";

	for (unsigned int c = 0; c < *_col - 1; ++c)
		str += to_string(_matrix[*_row - 1][c]) + ", ";

	str += to_string(_matrix[*_row - 1][*_col - 1]) + " }";

	return str;
}