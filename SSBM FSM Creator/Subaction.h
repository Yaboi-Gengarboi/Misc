// SSBM FSM Creator
// Subaction.h
// Justyn Durnford
// Created on 7/29/2020
// Last updated on 7/30/2020

#ifndef SUBACTION_H
#define SUBACTION_H

#include <string>

class Subaction
{
	std::string _name = "";
	unsigned short _id = 0;

	public:

	// Default Constructor.
	Subaction();

	// Primary Constructor.
	Subaction(const std::string& name, unsigned short id);

	// Destructor.
	~Subaction();

	// Returns _name.
	std::string name() const;

	// Returns _id.
	unsigned short id() const;

	// Returns true if a._id == b._id.
	bool friend operator == (const Subaction& a, const Subaction& b);

	// Returns true if a._id != b._id.
	bool friend operator != (const Subaction& a, const Subaction& b);
};

#endif // SUBACTION_H