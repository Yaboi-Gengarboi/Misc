// RPGGame
// Move.cpp
// Justyn Durnford
// Created on 5/23/2020
// Last updated on 6/26/2020

#include "Move.h"

#include "Type.h"
class Type;

#include "Move_Kind.h"
class Move_Kind;

#include <string>
using std::string;

#include <vector>
using std::vector;

Move::Move() { /* See Move.h for default values. */ }

Move::Move(const string& name, unsigned char kind, unsigned char type,
		   unsigned short id, unsigned char pp, char priority)
{
	_name = name;
	_kind = kind;
	_type = type;
	_id = id;
	_pp = pp;
	_priority = priority;
}

Move::~Move() { /* Destructor. */ }

string Move::name() const
{
	return _name;
}

Move_Kind& Move::kind() const
{
	return move_kind_list[_kind];
}

Type& Move::type() const
{
	return type_list[_type];
}

unsigned short Move::id() const
{
	return _id;
}

unsigned char Move::pp() const
{
	return _pp;
}

char Move::priority() const
{
	return _priority;
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

vector<Move> move_list;