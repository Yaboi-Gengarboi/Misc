// RPGGame
// Move.cpp
// Justyn Durnford
// Created on 5/23/2020
// Last updated on 7/8/2020

#include "Move.h"

#include "Move_Data.h"
struct Move_Kind;
struct Move_Range;

#include "Type.h"
class Type;

#include "Fraction.h"
class Fraction;

#include <string>
using std::string;

#include <vector>
using std::vector;

Move::Move() { /* See Move.h for default values. */ }

Move::Move(const string& name, const string& desc, unsigned short index,
		   unsigned char type, unsigned char kind, unsigned char power,
		   unsigned char pp, unsigned char range, const Fraction& accuracy,
		   const Fraction& additionalChance, char priority)
{
	_name = name;
	_desc = desc;
	_index = index;
	_type = type;
	_kind = kind;
	_power = power;
	_pp = pp;
	_range = range;
	_accuracy = accuracy;
	_additionalChance = additionalChance;
	_priority = priority;
}

Move::~Move() { /* Destructor. */ }

string Move::name() const
{
	return _name;
}

string Move::desc() const
{
	return _desc;
}

unsigned short Move::index() const
{
	return _index;
}

Type& Move::type() const
{
	return type_list[_type];
}

Move_Kind& Move::kind() const
{
	return move_kind_list[_kind];
}

unsigned char Move::power() const
{
	return _power;
}

unsigned char Move::pp() const
{
	return _pp;
}

Move_Range& Move::range() const
{
	return move_range_list[_range];
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