// RPGGame
// Chance.cpp
// Justyn Durnford
// Created on 2020-08-11
// Last updated on 2020-09-30

#include "Chance.h"

#include <array>
using std::array;

#include <random>
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;

random_device rand_dev;
default_random_engine rand_engine(rand_dev());
uniform_int_distribution<unsigned short> rand_dist(1, 1000);

unsigned short rand_value()
{
	return rand_dist(rand_engine);
}

bool chance(unsigned short value)
{
	if (value > rand_value())
		return true;
	return false;
}

array<unsigned short, 10> protection_chance =
{
	1000,
	500,
	250,
	125,
	63,
	32,
	16,
	8,
	4,
	2
};