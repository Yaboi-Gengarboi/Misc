// RPGGame
// Move.cpp
// Justyn Durnford
// Created on 5/23/2020
// Last updated on 7/1/2020

#include "Move.h"

#include "Move_Kind.h"
class Move_Kind;

#include "Type.h"
class Type;

#include "Fraction.h"
class Fraction;

#include <string>
using std::string;

#include <vector>
using std::vector;

Move::Move() { /* See Move.h for default values. */ }

Move::Move(unsigned short index, const string& name, const string& desc,
		   unsigned char type, unsigned char kind, unsigned short power, unsigned char pp,
		   const Fraction& accuracy, const Fraction& additionalChance, char priority)
{
	_index = index;
	_name = name;
	_desc = desc;
	_type = type;
	_kind = kind;
	_power = power;
	_pp = pp;
	_accuracy = accuracy;
	_additionalChance = additionalChance;
	_priority = priority;
}

Move::~Move() { /* Destructor. */ }

unsigned short Move::index() const
{
	return _index;
}

string Move::name() const
{
	return _name;
}

string Move::desc() const
{
	return _desc;
}

Type& Move::type() const
{
	return type_list[_type];
}

Move_Kind& Move::kind() const
{
	return move_kind_list[_kind];
}

unsigned short Move::power() const
{
	return _power;
}

unsigned char Move::pp() const
{
	return _pp;
}

Fraction Move::accuracy() const
{
	return _accuracy;
}

Fraction Move::additionalChance() const
{
	return _additionalChance;
}

char Move::priority() const
{
	return _priority;
}

bool operator == (const Move& m1, const Move& m2)
{
	if (m1.index() == m2.index())
		return true;
	return false;
}

bool operator != (const Move& m1, const Move& m2)
{
	if (m1.index() != m2.index())
		return true;
	return false;
}

vector<Move> move_list;
vector<bool> move_contact_list;