// RPGGame
// Ability.cpp
// Justyn Durnford
// Created on 5/15/2020
// Last updated on 8/17/2020

#include "Ability.h"

#include <string>
using std::string;

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

string Ability::name() const
{
	return _name;
}

string Ability::desc() const
{
	return _desc;
}

unsigned char Ability::id() const
{
	return _id;
}