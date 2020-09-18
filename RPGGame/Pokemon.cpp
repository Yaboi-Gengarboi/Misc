// RPGGame
// Pokemon.cpp
// Justyn Durnford
// Created on 5/15/2020
// Last updated on 8/17/2020

#include "Pokemon.h"

#include "Ability.h"
class Ability;

#include "Data.h"

#include "Egg_Group.h"
class Egg_Group;

#include "Type.h"
class Type;

#include <string>
using std::string;

#include <vector>
using std::vector;

Pokemon::Pokemon() { /* See Pokemon.h for default values. */ }

Pokemon::Pokemon(unsigned short id)
{
	_id = id;
}

Pokemon::~Pokemon() { /* Destructor. */ }

string Pokemon::name() const
{
	return _name;
}

string Pokemon::desc() const
{
	return _desc;
}

unsigned short Pokemon::id() const
{
	return _id;
}

Type& Pokemon::type1() const
{
	return type_arr[_type1];
}

Type& Pokemon::type2() const
{
	return type_arr[_type2];
}

Ability& Pokemon::ability1() const
{
	return ability_list[_ability1];
}

Ability& Pokemon::ability2() const
{
	return ability_list[_ability2];
}

unsigned short Pokemon::maleRatio() const
{
	return _maleRatio;
}

Egg_Group& Pokemon::eg1() const
{
     return egg_group_list[_eg1];
}

Egg_Group& Pokemon::eg2() const
{
    return egg_group_list[_eg2];
}

float Pokemon::height() const
{
	return _height;
}

float Pokemon::weight() const
{
	return _weight;
}

unsigned char Pokemon::evHP() const
{
	return _evYield[0];
}

unsigned char Pokemon::evAtk() const
{
	return _evYield[1];
}

unsigned char Pokemon::evDef() const
{
	return _evYield[2];
}

unsigned char Pokemon::evSpAtk() const
{
	return _evYield[3];
}

unsigned char Pokemon::evSpDef() const
{
	return _evYield[4];
}

unsigned char Pokemon::evSpe() const
{
	return _evYield[5];
}

unsigned char Pokemon::baseHP() const
{
	return _baseStats[0];
}

unsigned char Pokemon::baseAtk() const
{
	return _baseStats[1];
}

unsigned char Pokemon::baseDef() const
{
	return _baseStats[2];
}

unsigned char Pokemon::baseSpAtk() const
{
	return _baseStats[3];
}

unsigned char Pokemon::baseSpDef() const
{
	return _baseStats[4];
}

unsigned char Pokemon::baseSpe() const
{
	return _baseStats[5];
}