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
	Point A(-3, 0, 0);
	Point B(-1, 5, 0);
	Point C(7, 4, 0);
	Point D(5, -1, 0);

	Vector U(A, B);
	println(U.to_str());

	Vector V(A, D);
	println(V.to_str());

	Vector W = cross_product(U, V);
	println(W.to_str());
	println(W.length());

	return 0;
}