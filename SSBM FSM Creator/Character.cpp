// SSBM FSM Creator
// Character.cpp
// Justyn Durnford
// Created on 7/29/2020
// Last updated on 7/30/2020

#include "Character.h"
#include "Subaction.h"

#include <string>
using std::string;

#include <map>
using std::map;

Character::Character() { /* See Character.h for default values. */ }

Character::Character(const string& name, unsigned char id)
{
	_name = name;
	_id = id;
}

Character::~Character() { /* Destructor */ }

string Character::name() const
{
	return _name;
}

unsigned short Character::id() const
{
	return _id;
}

const Subaction& Character::subList(unsigned short id) const
{
	return _subList.at(id);
}

void Character::addSubaction(const std::string& name, unsigned short id)
{
	_subList[id] = Subaction(name, id);
}

bool operator == (const Character& a, const Character& b)
{
	if (a._id == b._id)
		return true;

	return false;
}

bool operator != (const Character& a, const Character& b)
{
	if (a._id != b._id)
		return true;

	return false;
}