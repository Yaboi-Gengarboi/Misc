// RPGGame
// main.cpp
// Justyn Durnford
// Created on 4/27/2020
// Last updated on 6/29/2020

#include "Ability.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::to_string;
using std::getline;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <string>
using std::to_string;

int main()
{
	load_Abilities();

	for (unsigned char c = 0; c < ability_list.size(); ++c)
	{
		cout << ability_list[c].name() << endl;
		cout << ability_list[c].desc() << endl;
		cout << endl;
	}

	return 0;
}