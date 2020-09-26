// Matrix.h
// Justyn Durnford
// Created on 2020-06-08
// Last updated on 2020-09-26
// Header file for the Matrix template class
// This is free and unencumbered software released into the public domain.
// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software, either in source code form or as a compiled
// binary, for any purpose, commercial or non-commercial, and by any
// means.
// In jurisdictions that recognize copyright laws, the author or authors
// of this software dedicate any and all copyright interest in the
// software to the public domain. We make this dedication for the benefit
// of the public at large and to the detriment of our heirs and
// successors. We intend this dedication to be an overt act of
// relinquishment in perpetuity of all presentand future rights to this
// software under copyright law.
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
// OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
// For more information, please refer to http://unlicense.org/

#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <cstddef>
#include <vector>

// This class is able to function as a 
//
//
// This class manages its own memory. Do not
// create an object of this class on the heap.
template <typename T>
class Matrix
{
	public:

	using value_type = T;
	using size_type = std::size_t;

	private:

	std::vector<std::vector<value_type>> _matrix;
	size_type* _row = new size_type(0);
	size_type* _col = new size_type(0);

	public:

	Matrix() = default;

	Matrix(const size_type& row, const size_type& col)
	{
		*_row = row;
		*_col = col;

		for (size_type r = 0; r < _row; ++r)
		{
			for (size_type c = 0; c < _col; ++c)
			{
				_matrix[r].push_back(value_type);
			}
		}
	}

	Matrix(const size_type& row, const size_type& col, const value_type& val)
	{
		*_row = row;
		*_col = col;

		for (size_type r = 0; r < _row; ++r)
		{
			for (size_type c = 0; c < _col; ++c)
			{
				_matrix[r].push_back(val);
			}
		}
	}

	Matrix(const Matrix& matrix)
	{
		*_row = *( matrix._row );
		*_col = *( matrix._col );
		_matrix = matrix;
	}

	Matrix& operator = (const Matrix& matrix)
	{
		delete _row;
		delete _col;
		*_row = *( matrix._row );
		*_col = *( matrix._col );
		_matrix = matrix;
	}

	Matrix(Matrix&& matrix) = delete;
	Matrix& operator = (Matrix&& matrix) = delete;

	~Matrix()
	{
		delete _row;
		delete _col;
	}

	value_type& at(const size_type& row, const size_type& col)
	{
		return _matrix[row][col];
	}

	const value_type& at(const size_type& row, const size_type& col) const
	{
		return _matrix[row][col];
	}

	void set(const size_type& row, const size_type& col, const value_type& val)
	{
		_matrix[row][col] = val;
	}

	size_type rowSize() const
	{
		return *_row;
	}

	size_type colSize() const
	{
		return *_col;
	}

	bool empty() const
	{
		return _matrix.empty();
	}

	value_type operator () (const size_type& row, const size_type& col)
	{
		return _matrix[row][col];
	}
};

#endif // MATRIX_H_INCLUDED