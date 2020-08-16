// RPGGame
// Data.h
// Justyn Durnford
// Created on 8/14/2020
// Last updated on 8/14/2020

#ifndef DATA_H
#define DATA_H

#include "Ability.h"
class Ability;

#include "Pokemon.h"
class Pokemon;

#include "Player_Pokemon.h"
class Player_Pokemon;

#include <string>
#include <vector>

extern std::vector<Ability> ability_list;
extern std::vector<Pokemon> pokemon_list;

std::string to_hex(long i);

std::string to_hex(float f);

bool load_abilities();

bool load_moves();

bool load_pokemon();

bool load_player_pokemon();

#endif // DATA_H