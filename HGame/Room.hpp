// HGame
// Room.hpp
// Justyn Durnford
// Created on 3/24/2020
// Last updated on 5/5/2020

#ifndef ROOM_HPP
#define ROOM_HPP

#include <memory>
#include <vector>

class Room
{
	unsigned char _ID = -1;

	std::vector<std::shared_ptr<Room>> _nextRooms;

	public:

	Room();
	Room(unsigned char id);

	~Room();

	void addNextRoom(const Room& rm);

	std::vector<std::shared_ptr<Room>> getNextRooms() const;

	unsigned char ID() const;
};

bool operator == (const Room& rm, unsigned char ID);
bool operator != (const Room& rm, unsigned char ID);

#endif // ROOM_HPP