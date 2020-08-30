// RPGGame
// Battle.cpp
// Justyn Durnford
// Created on 8/14/2020
// Last updated on 8/14/2020

#include "Battle.h"

#include "Move.h"
class Move;

#include "Pokemon.h"
class Pokemon;

#include "Player_Pokemon.h"
class Player_Pokemon;

#include "Type.h"
class Type;

float type_matchup(const Move& move, const Player_Pokemon& opponent)
{
	float multiplier = type_matchups[move.type().id()][opponent.pokemon().type1().id()];

	if (opponent.pokemon().type2().id() != -1)
		multiplier *= type_matchups[move.type().id()][opponent.pokemon().type2().id()];

	return multiplier;
}