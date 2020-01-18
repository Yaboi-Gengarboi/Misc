//main_file.cpp
//Justyn P. Durnford
//Created on 1/18/2020
//Last Updated on 1/18/2020
//

#include "Point.hpp"

#include <array>
using std::array;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
	Point p1;
	Point p2(10.00, 7.81, -4.29);
	double arr1[3] = {3.57, -9.02, 0.61};
	Point p3(arr1);
	array<double, 3> arr2 = {2.70, 4.00, 8.33};
	Point p4(arr2);

	cout << "P1: " << p1.to_str() << endl;
	cout << "P2: " << p2.to_str() << endl;
	cout << "P3: " << p3.to_str() << endl;
	cout << "P4: " << p4.to_str() << endl;

	return 0;
}