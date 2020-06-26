// RPGGame
// Characteristic.cpp
// Justyn Durnford
// Created on 6/26/2020
// Last updated on 6/26/2020

#include "Characteristic.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

Characteristic::Characteristic() { /* See Characteristic.h for default values. */ }

Characteristic::Characteristic(const string& desc, unsigned char id, unsigned char goodStat)
{
	_desc = desc;
	_id = id;
	_goodStat = goodStat;
}

Characteristic::~Characteristic() { /* Destructor. */ }

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

vector<Characteristic> characteristic_list =
{

};