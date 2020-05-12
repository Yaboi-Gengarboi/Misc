// HGame
// main.cpp
// Justyn Durnford
// Created on 3/23/2020
// Last updated on 5/11/2020

#include "Room.hpp"
#include "Monster.hpp"
#include "Misc.hpp"

// #include <memory>
using std::unique_ptr;
using std::make_unique;

// #include <vector>
using std::vector;

// #include <string>
using std::string;

#include <random>
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;

#include <thread>
using std::thread;
using std::this_thread::sleep_for;

#include <chrono> 
using std::chrono::seconds;

#include <iostream>
using std::cout;
using std::endl;

vector<Room> rooms;

void init_rooms()
{
	rooms.push_back({ 0 });
	rooms.push_back({ 1 });
	rooms.push_back({ 2 });
	rooms.push_back({ 3 });
	rooms.push_back({ 4 });
	rooms.push_back({ 5 });
	rooms.push_back({ 6 });
	rooms.push_back({ 7 });
	rooms.push_back({ 8 });
	rooms.push_back({ 9 });
	rooms.push_back({ 10 });

	rooms[0].addNextRoom(rooms[1]);
	rooms[0].addNextRoom(rooms[2]);

	rooms[1].addNextRoom(rooms[2]);
	rooms[1].addNextRoom(rooms[4]);

	rooms[2].addNextRoom(rooms[1]);
	rooms[2].addNextRoom(rooms[4]);

	rooms[3].addNextRoom(rooms[4]);
	rooms[3].addNextRoom(rooms[6]);

	rooms[4].addNextRoom(rooms[3]);
	rooms[4].addNextRoom(rooms[5]);
	rooms[4].addNextRoom(rooms[8]);

	rooms[5].addNextRoom(rooms[4]);
	rooms[5].addNextRoom(rooms[10]);

	rooms[6].addNextRoom(rooms[7]);

	rooms[7].addNextRoom(rooms[8]);

	rooms[9].addNextRoom(rooms[8]);

	rooms[10].addNextRoom(rooms[9]);
}

void try_move_monster(Monster& m)
{
	sleep_for(seconds(m.moveChanceTime()));
	if (m.difficultyLv() >= rand_1_20())
	{
		m.moveToNextRoom();
	}
}

int main()
{
	bool play_game = true;
	unique_ptr<Monster> m1 = make_unique<Monster>();

	while (play_game)
	{
		
		play_game = false;
	}

	return 0;
}