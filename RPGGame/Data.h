// RPGGame
// Data.h
// Justyn Durnford
// Created on 8/14/2020
// Last updated on 9/3/2020

#ifndef DATA_H
#define DATA_H

#include "Ability.h"
class Ability;

#include "Move.h"
class Move;

#include "Pokemon.h"
class Pokemon;

#include "Player_Pokemon.h"
class Player_Pokemon;

#include <cstddef>
#include <string>
#include <vector>

extern std::vector<Ability> ability_list;
extern std::vector<Pokemon> pokemon_list;
extern std::vector<Move> move_list;
extern std::vector<bool> move_contact_list;

std::string long_to_hex(long i);

std::string float_to_hex(float f);

std::string eng_to_hex(const std::string& str);

long hex_to_long(const std::string& str);

std::string hex_to_eng(const std::string& str);

bool load_abilities();

bool load_moves();

bool load_pokemon();

bool load_player_pokemon();

#endif // DATA_H