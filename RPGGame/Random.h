// RPGGame
// Random.h
// Justyn Durnford
// Created on 8/11/2020
// Last updated on 8/12/2020

#ifndef RANDOM_H
#define RANDOM_H

#include <random>

extern std::random_device rand_dev;
extern std::default_random_engine rand_engine;
extern std::uniform_int_distribution<unsigned short> rand_dist;

unsigned short rand_value();

bool chance(unsigned short value);

#endif // RANDOM_H