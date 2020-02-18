//main_file.cpp
//Justyn P. Durnford
//Created on 1/18/2020
//Last Updated on 1/21/2020
//

#include "Vector.hpp"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include <bitset>
using std::bitset;

int main()
{
	Vector u(1, -2, 3);
	Vector v(-1, -1, 2);

	Vector w = cross_product(u, v);
	cout << w.to_str() << endl;

	return 0;
}