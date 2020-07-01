// RPGGame
// Move.h
// Justyn Durnford
// Created on 4/20/2020
// Last updated on 7/1/2020

#ifndef MOVE_H
#define MOVE_H

#include "Move_Kind.h"
class Move_Kind;

#include "Type.h"
class Type;

#include "Fraction.h"
class Fraction;

#include <string>
#include <vector>

//
//
//
class Move
{
	unsigned short _index = 0;
	std::string _name = "";
	std::string _desc = "";
	unsigned char _type = 0;
	unsigned char _kind = 0;
	unsigned short _power = 0;
	unsigned char _pp = 0;
	Fraction _accuracy;
	Fraction _additionalChance;
	char _priority = 0;

	public:
	
	// Default constructor.
	Move();

	// Primary constructor.
	Move(unsigned short index, const std::string& name, const std::string& desc,
		 unsigned char type, unsigned char kind, unsigned short power, unsigned char pp,
		 const Fraction& accuracy, const Fraction& additionalChance, char priority);

	// Destructor.
	~Move();

	// Returns _id.
	unsigned short index() const;

	// Returns _name.
	std::string name() const;

	// Returns _desc.
	std::string desc() const;

	// Returns type_list[_type].
	Type& type() const;

	// Returns move_kind_list[_kind].
	Move_Kind& kind() const;

	// Returns _power.
	unsigned short power() const;

	// Returns _pp.
	unsigned char pp() const;

	// Returns _accuracy.
	Fraction accuracy() const;

	// Returns _additionalChance.
	Fraction additionalChance() const;

	// Returns _priority.
	char priority() const;
};

// Returns true ONLY IF m1.index() == m2.index()
bool operator == (const Move& m1, const Move& m2);

// Returns true ONLY IF m1.index() != m2.index()
bool operator != (const Move& m1, const Move& m2);

extern std::vector<Move> move_list;
extern std::vector<bool> move_contact_list;

#endif // MOVE_H