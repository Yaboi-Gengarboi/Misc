// RPGGame
// Ability.h
// Justyn Durnford
// Created on 4/12/2020
// Last updated on 8/17/2020

#ifndef ABILITY_H
#define ABILITY_H

#include <string>
#include <vector>

//
//
//
class Ability
{
	std::string _name;
	std::string _desc;
	unsigned char _id = 0;

	public:

	// Default constructor.
	Ability();

	// Primary Cconstructor.
	Ability(unsigned char id, const std::string& name, const std::string& desc);

	// Destructor.
	~Ability();

	// Returns _name.
	std::string name() const;

	// Returns _desc.
	std::string desc() const;

	// Returns _id.
	unsigned char id() const;
};

#endif // ABILITY_H