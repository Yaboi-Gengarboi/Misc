// RPGGame
// Move.h
// Justyn Durnford
// Created on 6/26/2020
// Last updated on 6/26/2020

#ifndef MOVE_KIND_H
#define MOVE_KIND_H

#include <string>
#include <vector>

// There are 3 kinds of moves: Physical, Special and Status. The
// Physical moves use the Attack and Defense stats of pokemon,
// Special moves use the Special Attack and Special Defense 
// stats, and Status moves use neither and instead focus on non-
// damaging effects.
class Move_Kind
{
	std::string _name = "";
	unsigned char _id = 0;

	public:

	// Default constructor.
	Move_Kind();

	// Primary constructor.
	Move_Kind(const std::string& name, unsigned char id);

	// Destructor.
	~Move_Kind();

	// Returns _name.
	std::string name() const;
	
	// Returns _id.
	unsigned char id() const;
};

// Returns true ONLY IF m1.id() == m2.id()
bool operator == (const Move_Kind& m1, const Move_Kind& m2);

// Returns true ONLY IF m1.id() != m2.id()
bool operator != (const Move_Kind& m1, const Move_Kind& m2);

extern std::vector<Move_Kind> move_kind_list;

#endif // MOVE_KIND_H