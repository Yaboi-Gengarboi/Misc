// RPGGame
// Pokemon.cpp
// Justyn Durnford
// Created on 5/15/2020
// Last updated on 6/21/2020

#include "Pokemon.h"

#include "Type.h"
class Type;

#include "Ability.h"
class Ability;

#include <string>
using std::string;

#include <array>
using std::array;

#include <memory>
using std::shared_ptr;

#include <fstream>
using std::ifstream;

void Pokemon::loadPokemon()
{

}

Pokemon::Pokemon() { /* See Pokemon.h for default values. */ }

Pokemon::Pokemon(unsigned short natIndex)
{
	_natIndex = natIndex;
}

Pokemon::~Pokemon() { /* Destructor. */ }

string Pokemon::name() const
{
	return _name;
}

unsigned short Pokemon::natIndex() const
{
	return _natIndex;
}

unsigned short Pokemon::regIndex() const
{
	return _regIndex;
}

Type& Pokemon::type1() const
{
	return type_list[_type1];
}

Type& Pokemon::type2() const
{
	return type_list[_type2];
}

Ability& Pokemon::ability1() const
{
	return ability_list[_ability1];
}

Ability& Pokemon::ability2() const
{
	return ability_list[_ability2];
}

float Pokemon::genderRatio() const
{
	return _genderRatio;
}

// shared_ptr<Egg_Group> eg1() const
// {
//     return _eg1;
// }

// shared_ptr<Egg_Group> eg2() const
// {
//     return _eg2;
// }

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

void load_pokemon()
{

}