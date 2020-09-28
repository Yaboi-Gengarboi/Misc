// RPGGame
// Ability.h
// Justyn Durnford
// Created on 2020-04-12
// Last updated on 2020-09-27

#ifndef ABILITY_H_INCLUDED
#define ABILITY_H_INCLUDED

#include "Battle.h"
class Battle;

#include <array>
#include <string>

//
//
//
class Ability
{
	unsigned char _id = 0;
	std::string _name;
	std::string _desc;

	public:

	// Default constructor.
	Ability() = default;

	// Copy constructor.
	Ability(const Ability& po) = default;

	// Move constructor.
	Ability(Ability&& po) = default;

	// Copy assignment.
	Ability& operator = (const Ability& po) = default;

	// Move assignment.
	Ability& operator = (Ability&& po) = default;

	// Primary Constructor.
	Ability(unsigned char id, const char* name, const char* desc);

	// Destructor.
	~Ability() = default;

	// Returns _id.
	unsigned char id() const;

	// Returns _name.
	std::string name() const;

	// Returns _desc.
	std::string desc() const;

	void operator() (Battle& battle);
};

extern std::array<Ability, 150> ability_arr;

#endif // ABILITY_H_INCLUDED