// test_file.cpp
// Justyn P. Durnford
// Created on 1/18/2020
// Last updated on 7/3/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#include "Misc.hpp"

#include <string>
using std::string;
using std::to_string;

#include <iostream>
using std::cout;
using std::endl;

void println(const string& str)
{
	cout << str << endl;
}

void println(double d)
{
	cout << d << endl;
}

void println(long long ll)
{
	cout << ll << endl;
}

int main(int argc, char** argv)
{
	return 0;
}