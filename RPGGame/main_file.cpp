// RPGGame
// main.cpp
// Justyn Durnford
// Created on 4/27/2020
// Last updated on 8/18/2020

#include "Ability.h"
#include "Data.h"
#include "Random.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::to_string;
using std::getline;

int main()
{
	string hexstr = long_to_hex(217);
	cout << hexstr << endl;

	long i = hex_to_long(hexstr);
	cout << i << endl;

	string hexstr2 = eng_to_hex("Fuck you Thomas");
	cout << hexstr2 << endl;

	string engstr = hex_to_eng(hexstr2);
	cout << engstr << endl;

	return 0;
}