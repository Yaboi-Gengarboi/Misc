// RPGGame
// Pokemon.cpp
// Justyn Durnford
// Created on 5/15/2020
// Last updated on 5/16/2020

#include "Pokemon.hpp"

#include "Type.hpp"
struct Type;

#include "Ability.hpp"
class Ability;

#include <string>
using std::string;

#include <array>
using std::array;

#include <memory>
using std::shared_ptr;
using std::make_shared;

Pokemon::Pokemon()
{
	// See Pokemon.hpp for default values
}

Pokemon::Pokemon(const std::string& name, unsigned int index, const Type& type1,
				 const Type& type2, unsigned char baseHP, unsigned char baseAtk, unsigned char baseDef,
				 unsigned char baseSpAtk, unsigned char baseSpDef, unsigned char baseSpd,
				 float height, float weight, shared_ptr<Pokemon> evol)
{
	_name = name;
	_index = index;
	_type1 = make_shared<Type>(type1);
	_type2 = make_shared<Type>(type2);
	_baseStats[0] = baseHP;
	_baseStats[1] = baseAtk;
	_baseStats[2] = baseDef;
	_baseStats[3] = baseSpAtk;
	_baseStats[4] = baseSpDef;
	_baseStats[5] = baseSpd;
	_height = height;
	_weight = weight;
	_evol = evol;
}

Pokemon::~Pokemon() { /* Destructor */ }

string Pokemon::name() const
{
	return _name;
}

unsigned int Pokemon::index() const
{
	return _index;
}

std::shared_ptr<Type> Pokemon::type1() const
{
	return _type1;
}

std::shared_ptr<Type> Pokemon::type2() const
{
	return _type2;
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

float Pokemon::height() const
{
	return _height;
}

float Pokemon::weight() const
{
	return _weight;
}

shared_ptr<Pokemon> Pokemon::evolution() const
{
	return _evol;
}

shared_ptr<Pokemon> Jigglypuff = make_shared<Pokemon>
(
	"Jigglypuff", 39, Normal, Fairy, 115, 60, 30, 60, 35, 30, 0.5f, 5.5f, Wigglytuff
);

shared_ptr<Pokemon> Wigglytuff = make_shared<Pokemon>
(
	"Wigglytuff", 40, Normal, Fairy, 140, 100, 55, 100, 60, 45, 1.0f, 12.0f, nullptr
);

shared_ptr<Pokemon> Azumarill = make_shared<Pokemon>
(
	"Azumarill", 184, Water, Fairy, 110, 50, 80, 90, 80, 50, 0.8f, 28.5f, nullptr
);