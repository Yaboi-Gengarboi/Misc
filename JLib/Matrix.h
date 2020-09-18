// Matrix.h
// Justyn Durnford
// Created on 2020-06-08
// Last updated on 2020-07-22
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
	using size_type = unsigned char;

	private:

	value_type** _matrix = nullptr;
	size_type _row = 0;
	size_type _col = 0;

	void alloc(const size_type& row, const size_type& col)
	{
		_row = row;
		_col = col;
		_matrix = new value_type* [_row];

		for (size_type r = 0; r < _row; ++r)
		{
			_matrix[r] = new value_type[_col];
		}
	}

	void alloc(const size_type& row, const size_type& col, const value_type& val)
	{
		_row = row;
		_col = col;
		_matrix = new value_type * [_row];

		for (size_type r = 0; r < _row; ++r)
		{
			_matrix[r] = new value_type[_col];
			
			for (size_type c = 0; c < _col; ++c)
				_matrix[r][c] = val;
		}
	}

	void dealloc()
	{
		for (size_type i = 0; i < _row; ++i)
		{
			delete[] _matrix[i];
			_matrix[i] = nullptr;
		}

		delete[] _matrix;
		_matrix = nullptr;
	}

	public:

	Matrix() = delete;
	Matrix(const Matrix& m) = delete;
	Matrix(Matrix&& m) = delete;
	Matrix& operator = (const Matrix& m) = delete;
	Matrix& operator = (Matrix&& m) = delete;

	Matrix(const size_type& row, const size_type& col)
	{
		alloc(row, col);
	}

	Matrix(const size_type& row, const size_type& col, const value_type& val)
	{
		alloc(row, col, val);
	}

	~Matrix()
	{
		dealloc();
	}

	value_type& at(const size_type& row const size_type& col)
	{
		return &_matrix[row][col];
	}

	const value_type& at(const size_type& row, const size_type& col) const
	{
		return &_matrix[row][col];
	}

	void set(const size_type& row, const size_type& col, const value_type& val)
	{
		_matrix[row][col] = val;
	}

	size_type rowSize() const
	{
		return _row;
	}

	size_type colSize() const
	{
		return _col;
	}

	bool empty() const
	{
		return _matrix == nullptr;
	}
};

#endif // MATRIX_H_INCLUDED