// RPGGame
// Player_Pokemon.cpp
// Justyn Durnford
// Created on 2020-08-14
// Last updated on 2020-09-30

#include "Player_Pokemon.h"

#include "Characteristic.h"
class Characteristic;

#include "Nature.h"
class Nature;

#include "Pokemon.h"
class Pokemon;

#include <array>
using std::array;

#include <memory>
using std::shared_ptr;

#include <string>
using std::string;

shared_ptr<Pokemon> Player_Pokemon::pokemon() const
{
	return _pokemon;
}