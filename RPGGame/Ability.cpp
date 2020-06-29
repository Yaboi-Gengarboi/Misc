// RPGGame
// Ability.cpp
// Justyn Durnford
// Created on 5/15/2020
// Last updated on 6/29/2020

#include "Ability.h"

#include <string>
using std::string;
using std::to_string;
using std::getline;

#include <fstream>
using std::ifstream;

#include <vector>
using std::vector;

Ability::Ability() { /* See Ability.h for default values. */ }

Ability::Ability(unsigned char id, const string& name, const string& desc)
{
	_id = id;
	_name = name;
	_desc = desc;
}

Ability::~Ability() { /* Destructor. */ }

unsigned char Ability::id() const
{
	return _id;
}

string Ability::name() const
{
	return _name;
}

string Ability::desc() const
{
	return _desc;
}

void load_Abilities()
{
	ifstream fin("Data/Abilities.txt");
	string name("");
	string desc("");

	for (unsigned char c = 0; c < 179; ++c)
	{
		getline(fin, name);
		getline(fin, desc);

		ability_list.push_back(Ability(c, name, desc));
	}
}

vector<Ability> ability_list;