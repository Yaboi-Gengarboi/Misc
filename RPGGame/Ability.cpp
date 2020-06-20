// RPGGame
// Ability.cpp
// Justyn Durnford
// Created on 5/15/2020
// Last updated on 6/20/2020

#include "Ability.h"

#include "Pokemon.h"
class Pokemon;

#include "Type.h"
class Type;

#include <string>
using std::string;

#include <memory>
using std::shared_ptr;
using std::make_shared;

void Ability::loadAbility()
{

}

Ability::Ability() { /* See Ability.h for default values. */ }

Ability::Ability(unsigned char id)
{
	_id = id;
}

Ability::~Ability() { /* Destructor. */ }

unsigned char Ability::id() const
{
	return _id;
}

string Ability::name() const
{
	return _name;
}

string Ability::desc() const
{
	return _desc;
}

string Ability::partyDesc() const
{
	return _partyDesc;
}

void load_Abilities()
{

}