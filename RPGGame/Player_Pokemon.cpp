// RPGGame
// Player_Pokemon.cpp
// Justyn Durnford
// Created on 8/14/2020
// Last updated on 8/14/2020

#include "Player_Pokemon.h"

#include "Characteristic.h"
class Characteristic;

#include "Data.h"

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