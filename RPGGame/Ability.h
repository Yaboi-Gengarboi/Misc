// RPGGame
// Ability.h
// Justyn Durnford
// Created on 4/12/2020
// Last updated on 8/11/2020

#ifndef ABILITY_H
#define ABILITY_H

#include <string>
#include <vector>

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
	Ability();

	// Primary Cconstructor.
	Ability(unsigned char id, const std::string& name, const std::string& desc);

	// Destructor.
	~Ability();

	// Returns _id.
	unsigned char id() const;

	// Returns _name.
	std::string name() const;

	// Returns _desc.
	std::string desc() const;
};

extern std::vector<Ability> ability_list;

#endif // ABILITY_H