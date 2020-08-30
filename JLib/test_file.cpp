// test_file.cpp
// Justyn P. Durnford
// Created on 1/18/2020
// Last updated on 8/29/2020
//
// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#include "Fraction.h"
#include "Point3f.hpp"
#include "Vector3D.h"

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char** argv)
{
	Vector3D v(3, 0, 0);
	Vector3D u(4, -6, 0);

	cout << v.toString() << endl;
	cout << u.toString() << endl;
	cout << endl;

	cout << scalar_proj(v, u) << endl;
	cout << vector_proj(v, u) << endl;

	return 0;
}