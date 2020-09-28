// RPGGame
// Characteristic.cpp
// Justyn Durnford
// Created on 2020-06-26
// Last updated on 2020-09-28

#include "Characteristic.h"

#include <string>
using std::string;

Characteristic::Characteristic(unsigned char id, const char* desc, unsigned char goodStat)
{
	_id = id;
	_desc = desc;
	_goodStat = goodStat;
}

string Characteristic::desc() const
{
	return _desc;
}

unsigned char Characteristic::id() const
{
	return _id;
}

unsigned char Characteristic::goodStat() const
{
	return _goodStat;
}

bool operator == (const Characteristic& c1, const Characteristic& c2)
{
	if (c1.id() == c2.id())
		return true;
	return false;
}

bool operator != (const Characteristic& c1, const Characteristic& c2)
{
	if (c1.id() != c2.id())
		return true;
	return false;
}