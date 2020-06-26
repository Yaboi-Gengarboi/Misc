// RPGGame
// Characteristic.h
// Justyn Durnford
// Created on 6/26/2020
// Last updated on 6/26/2020

#ifndef CHARACTERISTIC_H
#define CHARACTERISTIC_H

#include <string>
#include <vector>

// Each Tame_Pokemon has a Characteristic. Characteristics are
// nameless, and instead simply have a description. Every
// Characteristic will make one stat increase more quickly than
// average, but unlike Natures, they do not slow the growth of
// another stat, so there is no trade-off. Also unlike Natures,
// Characteristics can make the HP stat grow faster. There are
// 5 Characteristics for each stat.
//
// BREEDING DETAILS
//
class Characteristic
{
	std::string _desc = "";
	unsigned char _id = 0;
	unsigned char _stat = 0;

	public:

	// Default constructor. 
	Characteristic();

	// Primary constructor.
	Characteristic(const std::string& desc, unsigned char id, unsigned char stat);

	// Destructor.
	~Characteristic();

	// Returns _desc.
	std::string desc() const;

	// Returns _id.
	unsigned char id() const;

	// Returns _stat.
	unsigned char stat() const;
};

// Equality operators
bool operator == (const Characteristic& c1, const Characteristic& c2);
bool operator != (const Characteristic& c1, const Characteristic& c2);

std::vector<Characteristic> characteristic_list;

#endif // CHARACTERISTIC_H