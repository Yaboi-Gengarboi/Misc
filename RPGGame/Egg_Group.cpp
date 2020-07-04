// RPGGame
// Egg_Group.cpp
// Justyn Durnford
// Created on 7/1/2020
// Last updated on 7/3/2020

#include "Egg_Group.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

Egg_Group::Egg_Group() { /* See Egg_Group.h for default values. */ }

Egg_Group::Egg_Group(const string& name, unsigned char index)
{
	_name = name;
	_index = index;
}

Egg_Group::~Egg_Group() { /* Destructor. */ }

string Egg_Group::name() const
{
	return _name;
}

unsigned char Egg_Group::index() const
{
	return _index;
}

vector<Egg_Group> egg_group_list =
{
	Egg_Group("Monster", 0),
	Egg_Group("Water 1", 1),
	Egg_Group("Bug", 2),
	Egg_Group("Flying", 3),
	Egg_Group("Field", 4),
	Egg_Group("Fairy", 5),
	Egg_Group("Grass", 6),
	Egg_Group("Human-Like", 7),
	Egg_Group("Water 3", 8),
	Egg_Group("Mineral", 9),
	Egg_Group("Amorphous", 10),
	Egg_Group("Water 2", 11),
	Egg_Group("Ditto", 12),
	Egg_Group("Dragon", 13),
	Egg_Group("Undiscovered", 14)
};