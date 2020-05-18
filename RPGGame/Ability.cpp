// RPGGame
// Ability.cpp
// Justyn Durnford
// Created on 5/15/2020
// Last updated on 5/17/2020

#include "Ability.hpp"

// #include "Pokemon.hpp"
class Pokemon;
class Player_Pokemon;

// #include "Type.hpp"
struct Type;

// #include "Enviornment.hpp"
class Enviornment;

// #include <string>
using std::string;

// #include <array>

// #include <memory>
using std::shared_ptr;
using std::make_shared;

Ability::Ability()
{
	// See Ability.hpp for default values
}

Ability::Ability(const string& name, const string& desc, unsigned short int id)
{
	_name = name;
	_desc = desc;
	_id = id;
}

Ability::~Ability() { /* Destructor */ }

string Ability::name() const
{
	return _name;
}

string Ability::desc() const
{
	return _desc;
}

unsigned short int Ability::id() const
{
	return _id;
}

shared_ptr<Ability> Cute_Charm = make_shared<Ability>
(
	"Cute Charm", "", -1
);