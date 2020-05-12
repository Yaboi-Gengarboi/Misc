// HGame
// Monster.cpp
// Justyn Durnford
// Created on 5/5/2020
// Last updated on 5/8/2020

#include "Monster.hpp"
#include "Misc.hpp"

// #include <memory>
using std::shared_ptr;
using std::make_shared;

// #include <vector>
using std::vector;

// #include <string>
using std::string;

Monster::Monster() {}

Monster::Monster(const string& name, const Room& room, unsigned short int moveChanceTime, unsigned char difficultyLv)
{
	_name = name;
	_currentRoom = make_shared<Room>(room);
	_moveChanceTime = moveChanceTime;
	_difficultyLv = difficultyLv;
}

Monster::~Monster() {}

string Monster::name() const
{
	return _name;
}

shared_ptr<Room> Monster::currentRoom() const
{
	return _currentRoom;
}

void Monster::moveToNextRoom()
{
	_currentRoom = pick_rand_room(_currentRoom->getNextRooms());
}