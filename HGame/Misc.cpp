// HGame
// Misc.cpp
// Justyn Durnford
// Created on 5/5/2020
// Last updated on 5/8/2020

#include "Misc.hpp"

#include "Room.hpp"

// #include <memory>
using std::shared_ptr;

// #include <vector>
using std::vector;

#include <random>
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;

random_device rand_device;
default_random_engine rand_engine(rand_device());

uniform_int_distribution<unsigned char> uniform_dist_1_20(1, 20);

unsigned char rand_1_20()
{
	return uniform_dist_1_20(rand_engine);
}

shared_ptr<Room> pick_rand_room(const vector<shared_ptr<Room>>& nextRooms)
{
	uniform_int_distribution<unsigned char> uniform_dist(0, nextRooms.size() - 1);
	return nextRooms[uniform_dist(rand_engine)];
}