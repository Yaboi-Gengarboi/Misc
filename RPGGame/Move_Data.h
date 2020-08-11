// RPGGame
// Move_Data.h
// Justyn Durnford
// Created on 6/26/2020
// Last updated on 8/11/2020

#ifndef MOVE_DATA_H
#define MOVE_DATA_H

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
struct Move_Range
{
	std::string _desc = "";
	unsigned char _id = 0;

	public:

	// Default constructor.
	Move_Range();

	// Primary constructor.
	Move_Range(const std::string& name, unsigned char id);

	// Destructor.
	~Move_Range();
};

// Returns true ONLY IF m1._id == m2._id
bool operator == (const Move_Kind& m1, const Move_Kind& m2);

// Returns true ONLY IF m1._id != m2._id
bool operator != (const Move_Kind& m1, const Move_Kind& m2);

// Returns true ONLY IF m1._id == m2._id
bool operator == (const Move_Range& m1, const Move_Range& m2);

// Returns true ONLY IF m1._id != m2._id
bool operator != (const Move_Range& m1, const Move_Range& m2);

extern std::vector<Move_Kind> move_kind_list;
extern std::vector<Move_Range> move_range_list;

#endif // MOVE_DATA_H