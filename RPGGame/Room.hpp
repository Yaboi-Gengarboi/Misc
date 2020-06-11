// RPGGame
// Room.hpp
// Justyn Durnford
// Created on 6/5/2020
// Last updated on 6/10/2020

#ifndef ROOM_HPP
#define ROOM_HPP

#include "Matrix.hpp"

#include <string>
#include <vector>
#include <memory>

class Room
{
	short _id = -1;
	UChar_Matrix _layout;
	std::vector<unsigned char> _adjRooms;

	public:

	Room();
	Room(short id);

	~Room();

	short ID() const;

	void setID(short id);

	UChar_Matrix& layout();

	Room& getAdjacentRoom(unsigned char index);

	void addAdjacentRoom(const Room& room);
};

extern std::vector<Room> _rooms;

#endif // ROOM_HPP