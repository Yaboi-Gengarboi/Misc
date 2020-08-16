// RPGGame
// Move.h
// Justyn Durnford
// Created on 4/20/2020
// Last updated on 8/16/2020

#ifndef MOVE_H
#define MOVE_H

#include "Type.h"
class Type;

#include <string>
#include <vector>

// There are 3 kinds of moves: Physical, Special and Status. The
// Physical moves use the Attack and Defense stats of pokemon,
// Special moves use the Special Attack and Special Defense 
// stats, and Status moves use neither and instead focus on non-
// damaging effects.
struct Move_Kind
{
	std::string _name;
	unsigned char _id = 0;

	// Default constructor.
	Move_Kind();

	// Primary constructor.
	Move_Kind(const std::string& name, unsigned char id);

	// Destructor.
	~Move_Kind();
};

//
//
//
class Move
{
	std::string _name = "";
	std::string _desc = "";
	unsigned short _id = 0;
	unsigned char _type = 0;
	unsigned char _kind = 0;
	unsigned char _power = 0;
	unsigned char _pp = 0;
	unsigned short _accuracy = 0;
	unsigned short _additionalChance = 0;
	char _priority = 0;

	public:
	
	// Default constructor.
	Move();

	// Primary constructor.
	Move(const std::string& name, const std::string& desc, unsigned short id,
		 unsigned char type, unsigned char kind, unsigned char power,
		 unsigned char pp, unsigned short accuracy, unsigned short additionalChance, 
		 char priority);

	// Destructor.
	~Move();

	// Returns _name.
	std::string name() const;

	// Returns _desc.
	std::string desc() const;

	// Returns _id.
	unsigned short id() const;

	// Returns type_list[_type].
	Type& type() const;

	// Returns move_kind_list[_kind].
	Move_Kind& kind() const;

	// Returns _power.
	unsigned char power() const;

	// Returns _pp.
	unsigned char pp() const;

	// Returns _accuracy.
	unsigned short accuracy() const;

	// Returns _additionalChance.
	unsigned short additionalChance() const;

	// Returns _priority.
	char priority() const;
};

// Returns true ONLY IF m1._id == m2._id
bool operator == (const Move_Kind& m1, const Move_Kind& m2);

// Returns true ONLY IF m1._id != m2._id
bool operator != (const Move_Kind& m1, const Move_Kind& m2);

// Returns true ONLY IF m1.id() == m2.id()
bool operator == (const Move& m1, const Move& m2);

// Returns true ONLY IF m1.id() != m2.id()
bool operator != (const Move& m1, const Move& m2);

extern std::vector<Move_Kind> move_kind_list;
extern std::vector<Move> move_list;
extern std::vector<bool> move_contact_list;



#endif // MOVE_H