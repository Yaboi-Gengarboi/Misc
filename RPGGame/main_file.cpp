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

#include <string>
using std::to_string;

int main()
{
	if (load_abilities())
		cout << ability_list.size() << endl;

	return 0;
}