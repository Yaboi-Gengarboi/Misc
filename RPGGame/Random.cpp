// RPGGame
// Random.cpp
// Justyn Durnford
// Created on 8/11/2020
// Last updated on 8/16/2020

#include "Random.h"

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