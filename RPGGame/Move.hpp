// RPGGame
// Move.hpp
// Justyn Durnford
// Created on 4/20/2020
// Last updated on 5/26/2020

#ifndef MOVE_HPP
#define MOVE_HPP

#include "Type.hpp"

#include <string>
#include <memory>
#include <bitset>

struct Move
{
	std::string _name = "";

	std::shared_ptr<Type> _type = nullptr;

	unsigned short _id = 0;
	unsigned char _pp = 0;
	unsigned char _priority = 0;

	// Each move has 3 booleans:
	// Is the move special (true) or physical (false)?
	// Is the move a status move (true) or not (false)?
	// Does the move make contact (true) or not (false)?
	//
	// These are stored as 3 bits in the move_data vector.
	// They are found at the indexes:
	// move_data[_index * 3]
	// move_data[_index * 3 + 1]
	// move_data[_index * 3 + 2]

	unsigned short _index = 0;
	
	Move();
	Move(const std::string& name, std::shared_ptr<Type> type, unsigned short id,
		 unsigned char pp, unsigned char priority, unsigned short index);

	~Move();
};

extern std::bitset<100> move_data;

extern std::shared_ptr<Move> Pound;
void _Pound();

extern std::shared_ptr<Move> Accelerock;
void _Accelerock();

#endif // MOVE_HPP