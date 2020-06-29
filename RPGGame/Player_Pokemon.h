// RPGGame
// Player_Pokemon.h
// Justyn Durnford
// Created on 6/29/2020
// Last updated on 6/29/2020

#ifndef PLAYER_POKEMON_H
#define PLAYER_POKEMON_H

#include "Pokemon.h"

#include "Nature.h"

#include "Characteristic.h"

#include <string>
using std::string;

#include <array>
using std::array;

//
//
//
class Player_Pokemon
{
	std::string _nickname = "";
	unsigned short _index = 0;
	unsigned char _level = 1;
	unsigned long _experience = 0;
	unsigned char _ability = 0;
	unsigned char _gender = 0;
	unsigned char _nature = 0;
	unsigned char _characteristic = 0;
	std::array<unsigned char, 6> _evs = { 0, 0, 0, 0, 0, 0 };
	std::array<unsigned char, 6> _stats = { 0, 0, 0, 0, 0, 0 };

	public:

	Player_Pokemon();

	~Player_Pokemon();
};

#endif // PLAYER_POKEMON_H