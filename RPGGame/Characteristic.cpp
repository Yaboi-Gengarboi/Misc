// RPGGame
// Characteristic.cpp
// Justyn Durnford
// Created on 6/26/2020
// Last updated on 6/30/2020

#include "Characteristic.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

Characteristic::Characteristic() { /* See Characteristic.h for default values. */ }

Characteristic::Characteristic(const string& desc, unsigned char index, unsigned char goodStat)
{
	_desc = desc;
	_index = id;
	_goodStat = goodStat;
}

Characteristic::~Characteristic() { /* Destructor. */ }

string Characteristic::desc() const
{
	return _desc;
}

unsigned char Characteristic::index() const
{
	return _index;
}

unsigned char Characteristic::goodStat() const
{
	return _goodStat;
}

bool operator == (const Characteristic& c1, const Characteristic& c2)
{
	if (c1.index() == c2.index())
		return true;
	return false;
}

bool operator != (const Characteristic& c1, const Characteristic& c2)
{
	if (c1.index() != c2.index())
		return true;
	return false;
}

vector<Characteristic> characteristic_list =
{
	Characteristic("Loves to eat.", 0, 0),
	Characteristic("Takes plenty of siestas.", 1, 0),
	Characteristic("Nods off a lot.", 2, 0),
	Characteristic("Scatters things often.", 3, 0),
	Characteristic("Likes to relax.", 4, 0),
	Characteristic("Proud of its power.", 5, 1),
	Characteristic("Likes to thrash about.", 6, 1),
	Characteristic("A little quick tempered.", 7, 1),
	Characteristic("Likes to fight.", 8, 1),
	Characteristic("Quick tempered.", 9, 1),
	Characteristic("Sturdy body.", 10, 2),
	Characteristic("Capable of taking hits.", 11, 2),
	Characteristic("Highly persistent.", 12, 2),
	Characteristic("Good endurance.", 13, 2),
	Characteristic("Good perseverance.", 14, 2),
	Characteristic("Highly curious.", 15, 3),
	Characteristic("Mischievous.", 16, 3),
	Characteristic("Thoroughly cunning.", 17, 3),
	Characteristic("Often lost in thought.", 18, 3),
	Characteristic("Very finicky.", 19, 3),
	Characteristic("Strong willed.", 20, 4),
	Characteristic("Somewhat vain.", 21, 4),
	Characteristic("Strongly defiant.", 22, 4),
	Characteristic("Hates to lose.", 23, 4),
	Characteristic("Somewhat stubborn.", 24, 4),
	Characteristic("Likes to run.", 25, 5),
	Characteristic("Alert to sounds.", 26, 5),
	Characteristic("Impetuous and silly.", 27, 5),
	Characteristic("Somewhat of a clown.", 28, 5),
	Characteristic("Quick to flee.", 29, 5)
};