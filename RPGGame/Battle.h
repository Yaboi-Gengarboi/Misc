// RPGGame
// Battle.h
// Justyn Durnford
// Created on 6/20/2020
// Last updated on 8/14/2020

#ifndef BATTLE_H
#define BATTLE_H

#include "Move.h"
class Move;

#include "Pokemon.h"
class Pokemon;

#include "Player_Pokemon.h"
class Player_Pokemon;

#include "Type.h"
class Type;

//
//
//
class Battle
{

};

float type_matchup(const Move& move, const Player_Pokemon& opponent);

#endif // BATTLE_H