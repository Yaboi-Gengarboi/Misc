// RPGGame
// Player_Pokemon.h
// Justyn Durnford
// Created on 2020-06-29
// Last updated on 2020-09-28

#ifndef PLAYER_POKEMON_H_INCLUDED
#define PLAYER_POKEMON_H_INCLUDED

#include "Ability.h"
class Ability;

#include "Characteristic.h"
class Characteristic;

#include "Nature.h"
class Nature;

#include "Pokemon.h"
class Pokemon;

#include <array>
#include <memory>
#include <string>

//
//
//
class Player_Pokemon
{
	std::shared_ptr<Pokemon> _pokemon;
	std::string _nickname;
	unsigned char _level = 1;
	unsigned long _experience = 0;
	std::shared_ptr<Ability> _ability;
	bool _isMale = true;
	std::shared_ptr<Nature> _nature;
	std::shared_ptr<Characteristic> _characteristic;
	std::array<unsigned char, 6> _evs = { 0, 0, 0, 0, 0, 0 };
	std::array<float, 6> _stats = { 0, 0, 0, 0, 0, 0 };

	public:

	Player_Pokemon() = default;

	~Player_Pokemon() = default;

	std::shared_ptr<Pokemon> pokemon() const;
};

#endif // PLAYER_POKEMON_H_INCLUDED