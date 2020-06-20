// RPGGame
// Ability.h
// Justyn Durnford
// Created on 4/12/2020
// Last updated on 6/20/2020

#ifndef ABILITY_H
#define ABILITY_H

#include <string>
#include <memory>

//
//
//
class Ability
{
	unsigned char _id = -1;
	std::string _name = "";
	std::string _desc = "";
	std::string _partyDesc = "";

	void loadAbility();

	public:

	// Default constructor.
	Ability();

	// Primary Cconstructor.
	Ability(unsigned char id);

	// Destructor.
	~Ability();

	// Returns _id.
	unsigned char id() const;

	// Returns _name.
	std::string name() const;

	// Returns _desc.
	std::string desc() const;

	// Returns _partyDesc.
	std::string partyDesc() const;
};

void load_Abilities();

#endif // ABILITY_H