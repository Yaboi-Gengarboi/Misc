// RPGGame
// Move_Kind.cpp
// Justyn Durnford
// Created on 6/26/2020
// Last updated on 8/11/2020

#include "Move_Data.h"

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

Move_Range::Move_Range() { /* See Move_Data.h for default values. */ }

Move_Range::Move_Range(const string& desc, unsigned char id)
{
	_desc = desc;
	_id = id;
}

Move_Range::~Move_Range() { /* Destructor. */ }

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

bool operator == (const Move_Range& m1, const Move_Range& m2)
{
	if (m1._id == m2._id)
		return true;
	return false;
}

bool operator != (const Move_Range& m1, const Move_Range& m2)
{
	if (m1._id != m2._id)
		return true;
	return false;
}

vector<Move_Kind> move_kind_list =
{
	Move_Kind("Physical", 0),
	Move_Kind("Special", 1),
	Move_Kind("Status", 2)
};

vector<Move_Range> move_range_list =
{
	Move_Range("Hits a single adjacent opponent.", 0),
	Move_Range("Hits all adjacent opponents.", 1),
	Move_Range("Hits a single opponent.", 2),
	Move_Range("Hits all opponents.", 3),
	Move_Range("Hits a single adjacent ally.", 4),
	Move_Range("Hits all adjacent allies.", 5),
	Move_Range("Hits an ally.", 6),
	Move_Range("Hits all allies.", 7),
	Move_Range("Hits all other pokemon.", 8)
};