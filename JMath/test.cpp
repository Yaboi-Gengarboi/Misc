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
	Vector3D u(0, 0, -4);
	Vector3D v(0, 4, 0);

	cout << u << endl;
	cout << v << endl;
	cout << endl;

	cout << cross_product(u, v) << endl;

	return 0;
}