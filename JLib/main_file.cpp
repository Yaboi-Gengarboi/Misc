#include "JLib.hpp"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

int main()
{
	Point pt1(2, 3, 2);
	Point pt2(3, 4, 1);
	Point pt3(1, 2, 3);

	if (are_collinear(pt1, pt2, pt3))
		cout << "true" << endl;
	else
		cout << "false" << endl;

	return 0;
}