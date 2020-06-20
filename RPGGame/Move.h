// RPGGame
// Move.h
// Justyn Durnford
// Created on 4/20/2020
// Last updated on 6/20/2020

#ifndef MOVE_H
#define MOVE_H

#include "Type.h"

#include <string>
#include <memory>

struct Move_Kind
{
	std::string _name = "";
	unsigned char _id = 0;

	Move_Kind();
	Move_Kind(const std::string& name, unsigned char id);

	~Move_Kind();
};

extern std::shared_ptr<Move_Kind> Physical;
extern std::shared_ptr<Move_Kind> Special;
extern std::shared_ptr<Move_Kind> Status;

struct Move
{
	std::string _name = "";
	std::shared_ptr<Type> _type = nullptr;

	unsigned short _id = 0;
	unsigned char _pp = 0;
	unsigned char _priority = 0;
	// RANGE
	
	Move();
	Move(const std::string& name, const std::shared_ptr<Type>& type, unsigned short id,
		 unsigned char pp, unsigned char priority);

	~Move();
};

extern std::shared_ptr<Move> Pound;
void _Pound();

extern std::shared_ptr<Move> Accelerock;
void _Accelerock();

#endif // MOVE_H