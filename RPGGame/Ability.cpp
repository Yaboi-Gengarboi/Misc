// RPGGame
// Ability.cpp
// Justyn Durnford
// Created on 5/15/2020
// Last updated on 7/19/2020

#include "Ability.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

Ability::Ability() { /* See Ability.h for default values. */ }

Ability::Ability(unsigned char index, const string& name, const string& desc)
{
	_index = index;
	_name = name;
	_desc = desc;
}

Ability::~Ability() { /* Destructor. */ }

unsigned char Ability::index() const
{
	return _index;
}

string Ability::name() const
{
	return _name;
}

string Ability::desc() const
{
	return _desc;
}

vector<Ability> ability_list;