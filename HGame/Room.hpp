// Room.hpp
// Justyn Durnford
// Created on 3/24/2020
// Last updated on 3/24/2020

#ifndef ROOM_HPP
#define ROOM_HPP

#include <memory>
#include <array>

class Room
{
	unsigned char _dat = -1;

	std::array<std::shared_ptr<Room>, 4> _adjRooms =
	{ nullptr, nullptr, nullptr, nullptr };

	public:

	Room();
	Room(unsigned char num, unsigned char lv);

	~Room();

	unsigned char getNum() const;
	unsigned char getLv() const;
};


#endif // ROOM_HPP