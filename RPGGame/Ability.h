// RPGGame
// Ability.h
// Justyn Durnford
// Created on 4/12/2020
// Last updated on 6/22/2020

#ifndef ABILITY_H
#define ABILITY_H

#include <string>
#include <vector>

//
//
//
class Ability
{
	unsigned char _id = -1;
	std::string _name = "";
	std::string _desc = "";
	std::string _partyDesc = "";

	public:

	// Default constructor.
	Ability();

	// Primary Cconstructor.
	Ability(unsigned char id, const std::string& name,
			const std::string& desc, const std::string& partyDesc);

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

extern std::vector<Ability> ability_list;

#endif // ABILITY_H