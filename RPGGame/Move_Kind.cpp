// RPGGame
// Move.cpp
// Justyn Durnford
// Created on 6/26/2020
// Last updated on 6/26/2020

#include "Move_Kind.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

Move_Kind::Move_Kind() {}

Move_Kind::Move_Kind(const string& name, unsigned char id)
{

}

Move_Kind::~Move_Kind() {}

string Move_Kind::name() const
{
	return _name;
}

unsigned char Move_Kind::id() const
{
	return _id;
}

bool operator == (const Move_Kind& m1, const Move_Kind& m2)
{
	if (m1.id() == m2.id())
		return true;
	return false;
}

bool operator != (const Move_Kind& m1, const Move_Kind& m2)
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