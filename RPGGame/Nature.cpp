// RPGGame
// Nature.cpp
// Justyn Durnford
// Created on 6/25/2020
// Last updated on 8/11/2020

#include "Nature.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

Nature::Nature() { /* See Nature.h for default values. */ }

Nature::Nature(const string& name, unsigned char id,
			   unsigned char goodStat, unsigned char badStat)
{
	_name = name;
	_id = id;
	_goodStat = goodStat;
	_badStat = badStat;
}

Nature::~Nature() { /* Destructor. */ }

string Nature::name() const
{
	return _name;
}

unsigned char Nature::id() const
{
	return _id;
}

unsigned char Nature::goodStat() const
{
	return _goodStat;
}

unsigned char Nature::badStat() const
{
	return _badStat;
}

bool operator == (const Nature& n1, const Nature& n2)
{
	if (n1.id() == n2.id())
		return true;
	return false;
}

bool operator != (const Nature& n1, const Nature& n2)
{
	if (n1.id() != n2.id())
		return true;
	return false;
}

vector<Nature> nature_list =
{
	Nature("Adamant", 0, 1, 3),
	Nature("Bashful", 1, -1, -1),
	Nature("Bold", 2, 2, 1),
	Nature("Brave", 3, 1, 5),
	Nature("Calm", 4, 4, 1),
	Nature("Careful", 5, 4, 3),
	Nature("Docile", 6, -1, -1),
	Nature("Gentle", 7, 4, 2),
	Nature("Hardy", 8, -1, -1),
	Nature("Hasty", 9, 5, 2),
	Nature("Impish", 10, 2, 3),
	Nature("Jolly", 11, 5, 3),
	Nature("Lax", 12, 2, 4),
	Nature("Lonely", 13, 1, 2),
	Nature("Mild", 14, 3, 2),
	Nature("Modest", 15, 3, 1),
	Nature("Naive", 16, 5, 4),
	Nature("Naughty", 17, 1, 4),
	Nature("Quiet", 18, 3, 5),
	Nature("Quirky", 19, -1, -1),
	Nature("Rash", 20, 3, 4),
	Nature("Relaxed", 21, 2, 5),
	Nature("Sassy", 22, 4, 5),
	Nature("Serious", 23, -1, -1),
	Nature("Timid", 24, 5, 1)
};