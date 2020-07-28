// RPGGame
// Move.h
// Justyn Durnford
// Created on 4/20/2020
// Last updated on 7/8/2020

#ifndef MOVE_H
#define MOVE_H

#include "Move_Data.h"
struct Move_Kind;
struct Move_Range;

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
	std::string _name = "";
	std::string _desc = "";
	unsigned short _index = 0;
	unsigned char _type = 0;
	unsigned char _kind = 0;
	unsigned char _power = 0;
	unsigned char _pp = 0;
	unsigned char _range = 0;
	Fraction _accuracy;
	Fraction _additionalChance;
	char _priority = 0;

	public:
	
	// Default constructor.
	Move();

	// Primary constructor.
	Move(const std::string& name, const std::string& desc, unsigned short index,
		 unsigned char type, unsigned char kind, unsigned char power,
		 unsigned char pp, unsigned char range, const Fraction& accuracy,
		 const Fraction& additionalChance, char priority);

	// Destructor.
	~Move();

	// Returns _name.
	std::string name() const;

	// Returns _desc.
	std::string desc() const;

	// Returns _id.
	unsigned short index() const;

	// Returns type_list[_type].
	Type& type() const;

	// Returns move_kind_list[_kind].
	Move_Kind& kind() const;

	// Returns _power.
	unsigned char power() const;

	// Returns _pp.
	unsigned char pp() const;

	// Returns move_range_list[_range].
	Move_Range& range() const;

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