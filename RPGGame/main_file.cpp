// RPGGame
// main.cpp
// Justyn Durnford
// Created on 4/27/2020
// Last updated on 8/13/2020

#include "Ability.h"
#include "Initialize.h"
#include "Random.h"

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
	load_abilities();

	for (unsigned char i = 0; i < ability_list.size(); ++i)
	{
		cout << ability_list[i].name() << endl;
		cout << ability_list[i].desc() << endl;
	}

	for (unsigned char i = 0; i < 50; ++i)
		cout << rand_value() << endl;

	return 0;
}