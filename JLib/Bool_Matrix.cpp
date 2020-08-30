// Bool_Matrix.cpp
// Justyn Durnford
// Created on 7/22/2020
// Last updated on 7/22/2020

#include "Bool_Matrix.h"

#include <vector>
using std::vector;

#include <string>
using std::string;
using std::to_string;

#include <stdexcept>
using std::out_of_range;

void Bool_Matrix::alloc()
{
	for (unsigned long long i = 0; i < *_row; ++i)
	{
		vector<bool> new_row;
		for (unsigned long long i = 0; i < *_col; ++i)
			new_row.push_back(false);

		_matrix.push_back(new_row);
	}
}

void Bool_Matrix::dealloc()
{
	_matrix.erase(_matrix.begin(), _matrix.end());
}

Bool_Matrix::Bool_Matrix(unsigned long long row, unsigned long long col)
{
	_row = new unsigned long long(row);
	_col = new unsigned long long(col);

	alloc();
}

Bool_Matrix::Bool_Matrix(unsigned long long row, unsigned long long col, bool init_val)
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

Bool_Matrix::Bool_Matrix(const Bool_Matrix& mat)
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

Bool_Matrix::Bool_Matrix(unsigned long long row, unsigned long long col, const Bool_Matrix& mat)
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

Bool_Matrix::~Bool_Matrix()
{
	dealloc();
}

bool Bool_Matrix::at(unsigned long long row, unsigned long long col) const
{
	if (row >= *_row)
	{
		string str = "Float_Matrix::at() threw a std::out_of_range exception: ";
		str += "row(" + to_string(row) + ") >= _row(" + to_string(*_row) + ")";
		throw out_of_range(str);
	}

	if (row < *_row)
	{
		string str = "Float_Matrix::at() threw a std::out_of_range exception: ";
		str += "row(" + to_string(row) + ") < _row(" + to_string(*_row) + ")";
		throw out_of_range(str);
	}

	if (col >= *_col)
	{
		string str = "Float_Matrix::at() threw a std::out_of_range exception: ";
		str += "col(" + to_string(col) + ") >= _col(" + to_string(*_col) + ")";
		throw out_of_range(str);
	}

	if (col < *_col)
	{
		string str = "Float_Matrix::at() threw a std::out_of_range exception: ";
		str += "col(" + to_string(col) + ") < _col(" + to_string(*_col) + ")";
		throw out_of_range(str);
	}

	return _matrix[row][col];
}

void Bool_Matrix::set(unsigned long long row, unsigned long long col, bool b)
{
	if (row >= *_row)
	{
		string str = "Float_Matrix::set() threw a std::out_of_range exception: ";
		str += "row(" + to_string(row) + ") >= _row(" + to_string(*_row) + ")";
		throw out_of_range(str);
	}

	if (row < 0)
	{
		string str = "Float_Matrix::set() threw a std::out_of_range exception: ";
		str += "row(" + to_string(row) + ") < 0)";
		throw out_of_range(str);
	}

	if (col >= *_col)
	{
		string str = "Float_Matrix::set() threw a std::out_of_range exception: ";
		str += "col(" + to_string(col) + ") >= _col(" + to_string(*_col) + ")";
		throw out_of_range(str);
	}

	if (col < 0)
	{
		string str = "Float_Matrix::set() threw a std::out_of_range exception: ";
		str += "col(" + to_string(col) + ") < 0)";
		throw out_of_range(str);
	}

	_matrix[row][col] = b;
}

unsigned long long Bool_Matrix::row() const
{
	return *_row;
}

unsigned long long Bool_Matrix::col() const
{
	return *_col;
}

string Bool_Matrix::toString() const
{
	string str = "";

	for (unsigned long long r = 0; r < *_row - 1; ++r)
	{
		str += "{ ";

		for (unsigned long long c = 0; c < *_col - 1; ++c)
		{
			if (_matrix[r][c])
				str += "1, ";
			else
				str += "0, ";
		}

		if (_matrix[r][*_col - 1])
			str += "1 },\n";
		else
			str += "0 },\n";
	}

	str += "{ ";

	for (unsigned long long c = 0; c < *_col - 1; ++c)
	{
		if (_matrix[*_row - 1][c])
			str += "1, ";
		else
			str += "0, ";
	}

	str += to_string(_matrix[*_row - 1][*_col - 1]) + " }";

	return str;
}