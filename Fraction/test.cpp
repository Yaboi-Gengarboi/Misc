#include "Fraction.hpp"

#include <iostream>
using std::cout;
using std::endl;

int main()
{
	Fraction f1;
	Fraction f2(5, 2);
	cout << f1.to_str() << endl;
	cout << f2.to_str() << endl;

	return 0;
}