//Print.cpp
//Justyn P. Durnford
//Created on 1/14/2020
//Last Updated on 1/21/2020
//https://github.com/Yaboi-Gengarboi/Misc/tree/master/JLib

#include "Print.hpp"

#include <string>
using std::string;
using std::to_string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

void printCstr(const char* cstr)
{
	cout << cstr << endl;
}

void printStr(const string& str)
{
	cout << str << endl;
}

void printInt(const int& num_int)
{
	cout << to_string(num_int) << endl;
}

void printDoub(const double& num_double)
{
	cout << to_string(num_double) << endl;
}

void printChar(const char& ch)
{
	cout << ch << endl;
}

template <typename Type>
void printArr(const Type arr[])
{
	for (const auto& item : arr)
		cout << item << endl;
}

template <typename Type>
void printArr(const vector<Type>& vec)
{
	for (const auto& item : vec)
		cout << item << endl;
}