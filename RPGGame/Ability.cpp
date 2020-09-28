// RPGGame
// Ability.cpp
// Justyn Durnford
// Created on 2020-05-15
// Last updated on 2020-09-28

#include "Ability.h"

#include <string>
using std::string;

Ability::Ability(unsigned char id, const char* name, const char* desc)
{
	_id = id;
	_name = name;
	_desc = desc;
}

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