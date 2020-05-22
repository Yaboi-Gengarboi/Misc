// RPGGame
// Misc.cpp
// Justyn Durnford
// Created on 4/27/2020
// Last updated on 5/22/2020

#include "Misc.hpp"

#include <random>
using std::random_device;
using std::default_random_engine;
using std::uniform_real_distribution;

random_device rand_device;
default_random_engine rand_engine(rand_device());
uniform_real_distribution<float> uniform_dist(1, 100);

float rand_float()
{
	return uniform_dist(rand_engine);
}