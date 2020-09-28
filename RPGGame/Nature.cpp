// RPGGame
// Nature.cpp
// Justyn Durnford
// Created on 2020-06-25
// Last updated on 2020-09-27

#include "Nature.h"

#include <string>
using std::string;

Nature::Nature(unsigned char id, const char* name,
			   unsigned char goodStat, unsigned char badStat)
{
	_id = id;
	_name = name;
	_goodStat = goodStat;
	_badStat = badStat;
}

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