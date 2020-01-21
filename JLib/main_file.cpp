//main_file.cpp
//Justyn P. Durnford
//Created on 1/18/2020
//Last Updated on 1/21/2020
//

#include "Point.hpp"
#include "Vector.hpp"
#include "Print.hpp"

#include <cmath>
using std::sqrt;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
	Vector A(1, 5, -2);
	Vector B(2, -1, 0);
	Vector C(4, 9, -4);

	Vector D = cross_product(A, B);
	double d = dot_product(C, D);

	printDoub(d);

	return 0;
}