// RPGGame
// Characteristic.h
// Justyn Durnford
// Created on 2020-06-26
// Last updated on 2020-09-28

#ifndef CHARACTERISTIC_H_INCLUDED
#define CHARACTERISTIC_H_INCLUDED

#include <array>
#include <string>

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
	unsigned char _id = 0;
	std::string _desc;
	unsigned char _goodStat = 0;

	public:

	// Default constructor. 
	Characteristic() = default;

	// Copy constructor.
	Characteristic(const Characteristic& characteristic) = default;

	// Move constructor.
	Characteristic(Characteristic&& characteristic) = default;

	// Primary constructor.
	Characteristic(unsigned char id, const char* desc, unsigned char goodStat);

	// Copy assignment.
	Characteristic& operator = (const Characteristic& characteristic) = default;

	// Move assignment.
	Characteristic& operator = (Characteristic&& characteristic) = default;

	// Destructor.
	~Characteristic() = default;

	// Returns _id.
	unsigned char id() const;

	// Returns _desc.
	std::string desc() const;

	// Returns _goodStat.
	unsigned char goodStat() const;
};

// Returns true ONLY IF c1.id() == c2.id()
bool operator == (const Characteristic& c1, const Characteristic& c2);

// Returns true ONLY IF c1.id() != c2.id()
bool operator != (const Characteristic& c1, const Characteristic& c2);

extern std::array<Characteristic, 30> characteristic_arr;

#endif // CHARACTERISTIC_H