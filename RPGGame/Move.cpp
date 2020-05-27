// RPGGame
// Move.cpp
// Justyn Durnford
// Created on 5/23/2020
// Last updated on 5/26/2020

#include "Move.hpp"

#include <string>
using std::string;

#include <memory>
using std::shared_ptr;

#include <bitset>
using std::bitset;

Move::Move() { /* See Move.hpp for default values */ }

Move::Move(const string& name, shared_ptr<Type> type, unsigned short id,
		   unsigned char pp, unsigned char priority, unsigned short index)
{
	_name = name;
	_type = type;
	_id = id;
	_pp = pp;
	_priority = priority;
	_index = index;
}

Move::~Move() { /* Destructor */ }

bitset<100> move_data =
{

};