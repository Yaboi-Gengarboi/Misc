//Print.cpp
//Justyn P. Durnford
//Created on 1/14/2020
//Last Updated on 1/21/2020
//https://github.com/Yaboi-Gengarboi/Misc/tree/master/JLib

#include "Print.hpp"

#include <string>
using std::string;
using std::to_string;

#include <iostream>
using std::cout;
using std::endl;

void println(const char* cstr)
{
	cout << cstr << endl;
}

void println(const string& str)
{
	cout << str << endl;
}

void println(const int& num_int)
{
	cout << to_string(num_int) << endl;
}

void println(const double& num_double)
{
	cout << to_string(num_double) << endl;
}

void println(const char& ch)
{
	cout << ch << endl;
}