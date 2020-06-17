// RPGGame
// Room.cpp
// Justyn Durnford
// Created on 6/8/2020
// Last updated on 6/15/2020

#include "Room.hpp"

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;
using std::make_shared;

Room::Room() {}

Room::Room(short id)
{
	_id = id;
}

Room::~Room() {}

vector<Room> _rooms;