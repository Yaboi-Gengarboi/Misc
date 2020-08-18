// RPGGame
// Move.cpp
// Justyn Durnford
// Created on 5/23/2020
// Last updated on 8/16/2020

#include "Move.h"

#include "Type.h"
class Type;

#include <string>
using std::string;

#include <vector>
using std::vector;

Move_Kind::Move_Kind() { /* See Move_Data.h for default values. */ }

Move_Kind::Move_Kind(const string& name, unsigned char id)
{
	_name = name;
	_id = id;
}

Move_Kind::~Move_Kind() { /* Destructor. */ }

Move::Move() { /* See Move.h for default values. */ }

Move::Move(const string& name, const string& desc, unsigned short id,
		   unsigned char type, unsigned char kind, unsigned char power,
		   unsigned char pp, unsigned short accuracy, unsigned short additionalChance,
		   char priority)
{
	_name = name;
	_desc = desc;
	_id = id;
	_type = type;
	_kind = kind;
	_power = power;
	_pp = pp;
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

unsigned short Move::id() const
{
	return _id;
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

unsigned short Move::accuracy() const
{
	return _accuracy;
}

unsigned short Move::additionalChance() const
{
	return _additionalChance;
}

char Move::priority() const
{
	return _priority;
}

bool operator == (const Move_Kind& m1, const Move_Kind& m2)
{
	if (m1._id == m2._id)
		return true;
	return false;
}

bool operator != (const Move_Kind& m1, const Move_Kind& m2)
{
	if (m1._id != m2._id)
		return true;
	return false;
}

bool operator == (const Move& m1, const Move& m2)
{
	if (m1.id() == m2.id())
		return true;
	return false;
}

bool operator != (const Move& m1, const Move& m2)
{
	if (m1.id() != m2.id())
		return true;
	return false;
}

vector<Move_Kind> move_kind_list =
{
	Move_Kind("Physical", 0),
	Move_Kind("Special", 1),
	Move_Kind("Status", 2)
};

vector<Move> move_list;
vector<bool> move_contact_list;