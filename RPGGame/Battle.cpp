// RPGGame
// Battle.cpp
// Justyn Durnford
// Created on 2020-08-14
// Last updated on 2020-09-29

#include "Battle.h"

#include "Move.h"
class Move;

#include "Pokemon.h"
class Pokemon;

#include "Player_Pokemon.h"
class Player_Pokemon;

#include "Type.h"
class Type;

#include <memory>
using std::shared_ptr;
using std::make_shared;

shared_ptr<Weather> Battle::weather() const
{
	return _weather;
}

shared_ptr<Terrain> Battle::terrain() const
{
	return _terrain;
}

void Battle::setWeather(const Weather& weather)
{
	_weather = make_shared<Weather>(weather);
}

void Battle::setTerrain(const Terrain& terrain)
{
	_terrain = make_shared<Terrain>(terrain);
}

float type_matchup(const Move& move, const Player_Pokemon& opponent)
{
	float multiplier = type_matchups(move.type()->id(), opponent.pokemon()->type1()->id());

	if (opponent.pokemon()->type2()->id() != -1)
		multiplier *= type_matchups(move.type()->id(), opponent.pokemon()->type2()->id());

	return multiplier;
}