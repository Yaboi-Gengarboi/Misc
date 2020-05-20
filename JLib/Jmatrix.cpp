// Jmatrix.cpp
// Justyn Durnford
// Created on 4/13/2020
// Last updated on 5/11/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#include "Jmatrix.hpp"

// #include <string>

Jmatrix::Jmatrix()
{
	_rows = new unsigned int(1);
	_cols = new unsigned int(1);

	alloc();

	_matrix[0][0] = 0;
}

Jmatrix::Jmatrix(unsigned int rows, unsigned int cols)
{
	_rows = new unsigned int(rows);
	_cols = new unsigned int(cols);

	alloc();
}

Jmatrix::~Jmatrix()
{
	for (unsigned int i = 0; i < *_rows; ++i)
	{
		delete[] _matrix[i];
		_matrix[i] = nullptr;
	}

	delete[] _matrix;
	_matrix = nullptr;

	delete _rows;
	_rows = nullptr;

	delete _cols;
	_cols = nullptr;
}

void Jmatrix::alloc()
{
	_matrix = new double* [*_rows];
	
	for (unsigned int i = 0; i < *_rows; ++i)
	{
		_matrix[i] = new double[*_cols];
	}
}