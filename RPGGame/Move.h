// RPGGame
// Move.h
// Justyn Durnford
// Created on 2020-04-20
// Last updated on 2020-09-27

#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED

#include "Type.h"
class Type;

#include <array>
#include <memory>
#include <string>

// There are 3 kinds of moves: Physical, Special and Status. The
// Physical moves use the Attack and Defense stats of pokemon,
// Special moves use the Special Attack and Special Defense 
// stats, and Status moves use neither and instead focus on non-
// damaging effects.
struct Move_Kind
{
	unsigned char _id = 0;
	std::string _name;

	// Default constructor.
	Move_Kind() = default;

	// Copy constructor.
	Move_Kind(const Move_Kind& move_kind) = default;

	// Move constructor.
	Move_Kind(Move_Kind&& move_kind) = default;

	// Primary constructor.
	Move_Kind(unsigned char id, const char* name);

	// Copy assignment.
	Move_Kind& operator = (const Move_Kind& move_kind) = default;

	// Move assignment.
	Move_Kind& operator = (Move_Kind&& move_kind) = default;

	// Destructor.
	~Move_Kind() = default;
};

//
//
//
class Move
{
	unsigned short _id = 0;
	std::string _name = "";
	std::string _desc = "";
	std::shared_ptr<Type> _type;
	std::shared_ptr<Move_Kind> _kind = 0;
	unsigned char _power = 0;
	unsigned char _pp = 0;
	unsigned short _accuracy = 0;
	unsigned short _additionalChance = 0;
	char _priority = 0;

	public:
	
	// Default constructor.
	Move() = default;

	// Copy constructor.
	Move(const Move& move) = default;

	// Move constructor.
	Move(Move&& move) = default;

	// Primary constructor.
	Move(unsigned short id, const char* name, const char* desc,
		 const Type& type, const Move_Kind& kind, unsigned char power,
		 unsigned char pp, unsigned short accuracy, unsigned short additionalChance, 
		 char priority);

	// Copy assignment.
	Move& operator = (const Move& move) = default;

	// Move assignment.
	Move& operator = (Move&& move) = default;

	// Destructor.
	~Move() = default;

	// Returns _id.
	unsigned short id() const;

	// Returns _name.
	std::string name() const;

	// Returns _desc.
	std::string desc() const;

	// Returns _type.
	std::shared_ptr<Type> type() const;

	// Returns _kind.
	std::shared_ptr<Move_Kind> kind() const;

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

extern std::array<Move_Kind, 3> move_kind_arr;
extern std::array<Move, 300> move_arr;

#endif // MOVE_H_INCLUDED