// RPGGame
// Move.h
// Justyn Durnford
// Created on 4/20/2020
// Last updated on 6/26/2020

#ifndef MOVE_H
#define MOVE_H

#include "Type.h"
class Type;

#include "Move_Kind.h"
class Move_Kind;

#include <string>
#include <vector>

//
//
//
class Move
{
	std::string _name = "";
	unsigned char _kind = 0;
	unsigned char _type = 0;
	unsigned short _id = 0;
	unsigned char _pp = 0;
	char _priority = 0;

	public:
	
	// Default constructor.
	Move();

	// Primary constructor.
	Move(const std::string& name, unsigned char kind, unsigned char type,
		 unsigned short id, unsigned char pp, char priority);

	// Destructor.
	~Move();

	// Returns _name.
	std::string name() const;

	// Returns move_kind_list[_kind].
	Move_Kind& kind() const;

	// Returns type_list[_type].
	Type& type() const;

	// Returns _id.
	unsigned short id() const;

	// Returns _pp.
	unsigned char pp() const;

	// Returns _priority.
	char priority() const;
};

// Returns true ONLY IF m1.id() == m2.id()
bool operator == (const Move& m1, const Move& m2);

// Returns true ONLY IF m1.id() != m2.id()
bool operator != (const Move& m1, const Move& m2);

extern std::vector<Move> move_list;

#endif // MOVE_H