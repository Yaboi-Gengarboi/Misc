// RPGGame
// Ability.h
// Justyn Durnford
// Created on 2020-04-12
// Last updated on 2020-09-17

#ifndef ABILITY_H
#define ABILITY_H

#include <string>

//
//
//
class Ability
{
	std::string _name;
	std::string _desc;
	unsigned char _id = 0;

	public:

	// Default constructor
	Ability() = default;
	Ability(const Ability& po) = default;
	Ability& operator = (const Ability& po) = default;
	Ability(Ability&& po) = default;
	Ability& operator = (Ability&& po) = default;

	// Primary Cconstructor
	Ability(unsigned char id, const std::string& name, const std::string& desc);

	// Destructor
	~Ability() = default;

	// Returns _name
	std::string name() const;

	// Returns _desc
	std::string desc() const;

	// Returns _id
	unsigned char id() const;
};

#endif // ABILITY_H