// RPGGame
// Egg_Group.cpp
// Justyn Durnford
// Created on 2020-07-01
// Last updated on 2020-09-28

#include "Egg_Group.h"

#include <array>
using std::array;

#include <string>
using std::string;

Egg_Group::Egg_Group(unsigned char id, const char* name)
{
	_name = name;
	_id = id;
}

unsigned char Egg_Group::id() const
{
	return _id;
}

string Egg_Group::name() const
{
	return _name;
}