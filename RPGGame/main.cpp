// main.cpp
// Justyn Durnford
// Created on 4/27/2020
// Last updated on 4/27/2020

#include <iostream>
using std::cout;
using std::endl;

class ClassA
{
	unsigned int _a = 0;

	public:

	ClassA() : _a(0) {}

	ClassA(unsigned int a) : _a(a) {}

	~ClassA() {}

	unsigned int getA() const
	{
		return _a;
	}
};

template <typename T>
T copy(T t)
{
	return t;
}

int main()
{
	ClassA a(5);
	ClassA b = copy(a);

	cout << b.getA() << endl;

	return 0;
}