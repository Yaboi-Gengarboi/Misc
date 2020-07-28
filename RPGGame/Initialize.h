// RPGGame
// Initialize.h
// Justyn Durnford
// Created on 7/3/2020
// Last updated on 7/16/2020

#ifndef INITIALIZE_H
#define INITIALIZE_H

#include "Ability.h"
class Ability;

#include "Move.h"
class Move;

#include "Pokemon.h"
class Pokemon;

#include <string>

std::string reverse_str(const std::string& str);

std::string to_hex(unsigned long long i);

std::string to_hex(float f);

bool load_abilities();

bool load_moves();

bool load_pokemon();

bool load_player_pokemon();

#endif // INITIALIZE_H