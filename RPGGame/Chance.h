// RPGGame
// Chance.h
// Justyn Durnford
// Created on 2020-08-11
// Last updated on 2020-09-30

#ifndef CHANCE_H_INCLUDED
#define CHANCE_H_INCLUDED

#include <array>
#include <random>

extern std::random_device rand_dev;
extern std::default_random_engine rand_engine;
extern std::uniform_int_distribution<unsigned short> rand_dist;

unsigned short rand_value();

bool chance(unsigned short value);

extern std::array<unsigned short, 10> protection_chance;

#endif // CHANCE_H_INCLUDED