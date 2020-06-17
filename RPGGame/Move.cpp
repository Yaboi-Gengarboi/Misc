// RPGGame
// Move.cpp
// Justyn Durnford
// Created on 5/23/2020
// Last updated on 6/15/2020

#include "Move.hpp"

#include <string>
using std::string;

#include <memory>
using std::shared_ptr;
using std::make_shared;

////////////////////////////////////////////////////////////
///                      MOVE_KIND                       ///
////////////////////////////////////////////////////////////

Move_Kind::Move_Kind() { /* See Move.hpp for default values */ }

Move_Kind::Move_Kind(const string& name, unsigned char id)
{
	_name = name;
	_id = id;
}

Move_Kind::~Move_Kind() { /* Destructor */ }

shared_ptr<Move_Kind> Physical = make_shared<Move_Kind>("Physical", 0);
shared_ptr<Move_Kind> Special = make_shared<Move_Kind>("Special", 1);
shared_ptr<Move_Kind> Status = make_shared<Move_Kind>("Status", 2);

////////////////////////////////////////////////////////////
///                      MOVE_KIND                       ///
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
///                         MOVE                         ///
////////////////////////////////////////////////////////////

Move::Move() { /* See Move.hpp for default values */ }

Move::Move(const string& name, const shared_ptr<Type>& type, unsigned short id,
		   unsigned char pp, unsigned char priority)
{
	_name = name;
	_type = type;
	_id = id;
	_pp = pp;
	_priority = priority;
}

Move::~Move() { /* Destructor */ }

////////////////////////////////////////////////////////////
///                         MOVE                         ///
////////////////////////////////////////////////////////////