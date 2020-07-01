// RPGGame
// Move_Kind.cpp
// Justyn Durnford
// Created on 6/26/2020
// Last updated on 6/30/2020

#include "Move_Kind.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

Move_Kind::Move_Kind() { /* See Move_Kind.h for default values. */ }

Move_Kind::Move_Kind(const string& name, unsigned char index)
{
	_name = name;
	_index = index;
}

Move_Kind::~Move_Kind() { /* Destructor. */ }

string Move_Kind::name() const
{
	return _name;
}

unsigned char Move_Kind::index() const
{
	return _index;
}

bool operator == (const Move_Kind& m1, const Move_Kind& m2)
{
	if (m1.index() == m2.index())
		return true;
	return false;
}

bool operator != (const Move_Kind& m1, const Move_Kind& m2)
{
	if (m1.index() != m2.index())
		return true;
	return false;
}

vector<Move_Kind> move_kind_list =
{
	Move_Kind("Physical", 0),
	Move_Kind("Special", 1),
	Move_Kind("Status", 2)
};