// SSBM FSM Creator
// Character.h
// Justyn Durnford
// Created on 7/29/2020
// Last updated on 8/2/2020

#ifndef CHARACTER_H
#define CHARACTER_H

#include "Subaction.h"

#include <string>
#include <map>

class Character
{
	std::string _name = "";
	unsigned char _id = 0;

	std::map<unsigned short, Subaction> _subList;

	public:

	// Default Constructor.
	Character();

	// Primary Constructor.
	Character(const std::string& name, unsigned char id);

	// Destructor.
	~Character();

	// Returns _name.
	std::string name() const;

	// Returns _id.
	unsigned short id() const;

	// Returns _subList.
	const std::map<unsigned short, Subaction>& subList() const;

	// Adds a subaction to add to _subList with the given parameters.
	// Sets _size to id.
	void addSubaction(const std::string& name, unsigned short id);

	// Returns true if a._id == b._id.
	bool friend operator == (const Character& a, const Character& b);

	// Returns true if a._id != b._id.
	bool friend operator != (const Character& a, const Character& b);
};

#endif // CHARACTER_H