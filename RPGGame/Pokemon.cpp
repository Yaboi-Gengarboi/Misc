// RPGGame
// Pokemon.cpp
// Justyn Durnford
// Created on 2020-05-15
// Last updated on 2020-09-28

#include "Pokemon.h"

#include "Ability.h"
class Ability;

#include "Egg_Group.h"
class Egg_Group;

#include "Type.h"
class Type;

#include <memory>
using std::shared_ptr;

#include <string>
using std::string;

Pokemon::Pokemon(unsigned short id)
{
	_id = id;
}

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

shared_ptr<Type> Pokemon::type1() const
{
	return _type1;
}

shared_ptr<Type> Pokemon::type2() const
{
	return _type2;
}

shared_ptr<Ability> Pokemon::ability1() const
{
	return _ability1;
}

shared_ptr<Ability> Pokemon::ability2() const
{
	return _ability2;
}

unsigned short Pokemon::maleRatio() const
{
	return _maleRatio;
}

shared_ptr<Egg_Group> Pokemon::eg1() const
{
     return _eg1;
}

shared_ptr<Egg_Group> Pokemon::eg2() const
{
    return _eg2;
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