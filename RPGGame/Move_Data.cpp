// RPGGame
// Move_Kind.cpp
// Justyn Durnford
// Created on 6/26/2020
// Last updated on 7/1/2020

#include "Move_Data.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

Move_Kind::Move_Kind() { /* See Move_Data.h for default values. */ }

Move_Kind::Move_Kind(const string& name, unsigned char index)
{
	_name = name;
	_index = index;
}

Move_Kind::~Move_Kind() { /* Destructor. */ }

Move_Range::Move_Range() { /* See Move_Data.h for default values. */ }

Move_Range::Move_Range(const string& desc, unsigned char index)
{
	_desc = desc;
	_index = index;
}

Move_Range::~Move_Range() { /* Destructor. */ }

bool operator == (const Move_Kind& m1, const Move_Kind& m2)
{
	if (m1._index == m2._index)
		return true;
	return false;
}

bool operator != (const Move_Kind& m1, const Move_Kind& m2)
{
	if (m1._index != m2._index)
		return true;
	return false;
}

bool operator == (const Move_Range& m1, const Move_Range& m2)
{
	if (m1._index == m2._index)
		return true;
	return false;
}

bool operator != (const Move_Range& m1, const Move_Range& m2)
{
	if (m1._index != m2._index)
		return true;
	return false;
}

vector<Move_Kind> move_kind_list =
{
	Move_Kind("Physical", 0),
	Move_Kind("Special", 1),
	Move_Kind("Status", 2)
};