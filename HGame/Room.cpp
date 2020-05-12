// HGame
// Room.cpp
// Justyn Durnford
// Created on 5/4/2020
// Last updated on 5/5/2020

#include "Room.hpp"

// #include <memory>
using std::shared_ptr;
using std::make_shared;

// #include <vector>
using std::vector;

Room::Room() { }

Room::Room(unsigned char ID) : _ID(ID) { }

Room::~Room() { }

void Room::addNextRoom(const Room& rm)
{
	_nextRooms.push_back(make_shared<Room>(rm));
}

vector<shared_ptr<Room>> Room::getNextRooms() const
{
	return _nextRooms;
}

unsigned char Room::ID() const
{
	return _ID;
}

bool operator == (const Room& room, unsigned char ID)
{
	if (room.ID() == ID)
		return true;
	return false;
}

bool operator != (const Room& room, unsigned char ID)
{
	return !( room == ID );
}