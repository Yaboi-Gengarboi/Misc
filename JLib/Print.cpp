//Print.cpp
//Justyn P. Durnford
//Created on 1/14/2020
//Last Updated on 1/21/2020
//https://github.com/Yaboi-Gengarboi/Misc/tree/master/JLib

#include "Print.hpp"

#include <cstring>
using std::strcmp;

#include <string>
using std::string;
using std::to_string;
using std::size_t;

#include <vector>
using std::vector;

#include <typeinfo>

#include <iostream>
using std::cout;
using std::endl;

template <typename Type>
void printArr(const Type arr[])
{
	for (const auto& item : arr)
	{
		//If item is an integral number
		if ((strcmp(typeid(item).name(), "int") == 0)) //int
			cout << to_string(item) << endl;

		else if ((strcmp(typeid(item).name(), "unsigned int") == 0)) //unsigned int
			cout << to_string(item) << endl;

		else if ((strcmp(typeid(item).name(), "short") == 0)) //short
			cout << to_string(item) << endl;

		else if ((strcmp(typeid(item).name(), "unsigned short") == 0)) //unsigned short
			cout << to_string(item) << endl;

		else if ((strcmp(typeid(item).name(), "long") == 0)) //long
			cout << to_string(item) << endl;

		else if ((strcmp(typeid(item).name(), "unsigned long") == 0)) //unsigned long
			cout << to_string(item) << endl;

		else if ((strcmp(typeid(item).name(), "__int64") == 0)) //long long
			cout << to_string(item) << endl;

		else if ((strcmp(typeid(item).name(), "unsigned __int64") == 0)) //unsigned long long
			cout << to_string(item) << endl;

		else if ((strcmp(typeid(item).name(), "float") == 0))  //float
			cout << to_string(item) << endl;

		else if ((strcmp(typeid(item).name(), "double") == 0)) //double
			cout << to_string(item) << endl;

		else if ((strcmp(typeid(item).name(), "long double") == 0))  //long double
			cout << to_string(item) << endl;
	}
}

template <typename Type>
void printArr(const vector<Type>& vec)
{
	for (const auto& item : vec)
		cout << item << endl;
}