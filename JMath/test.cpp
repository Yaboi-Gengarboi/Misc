// test.cpp
// Justyn Durnford
// Created on 2020-08-30
// Last updated on 2020-08-30
// Test file for classes
// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#include "JMath.h"

#include <iostream>
using std::cout;
using std::endl;

#include <stdexcept>
using std::out_of_range;

int main()
{
	Vector3D v(6, 0, 0);
	Vector3D u(4, -2, 0);

	cout << v << endl;
	cout << u << endl;
	cout << endl;

	Vector3D w = cross_product(v, u);
	cout << w << endl;
	cout << w.magnitude() << endl;

	return 0;
}