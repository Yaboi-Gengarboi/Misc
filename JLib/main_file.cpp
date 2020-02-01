//main_file.cpp
//Justyn P. Durnford
//Created on 1/18/2020
//Last Updated on 1/21/2020
//

#include "Print.hpp"

#include <string>
using std::string;

#include <typeinfo>

#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	printArr(arr);

	return 0;
}