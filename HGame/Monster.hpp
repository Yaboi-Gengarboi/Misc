// HGame
// Monster.hpp
// Justyn Durnford
// Created on 5/5/2020
// Last updated on 5/6/2020

#ifndef MONSTER_HPP
#define MONSTER_HPP

#include "Room.hpp"

// #include <memory>
// #include <vector>

#include <string>

class Monster
{
	std::string _name = "";
	std::shared_ptr<Room> _currentRoom = nullptr;
	unsigned short int _moveChanceTime = 0;
	unsigned char _difficultyLv = 0;

	public:

	Monster();
	Monster(const std::string& name, const Room& room, unsigned short int moveChanceTime, unsigned char difficultyLv);

	~Monster();

	std::string name() const;

	std::shared_ptr<Room> currentRoom() const;

	void moveToNextRoom();
};

#endif // MONSTER_HPP