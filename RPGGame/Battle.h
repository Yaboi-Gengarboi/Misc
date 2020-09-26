// RPGGame
// Battle.h
// Justyn Durnford
// Created on 2020-06-20
// Last updated on 2020-09-26

#ifndef BATTLE_H_INCLUDED
#define BATTLE_H_INCLUDED

#include "Matrix.h"

#include "Move.h"
class Move;

#include "Pokemon.h"
class Pokemon;

#include "Player_Pokemon.h"
class Player_Pokemon;

#include "Terrain.h"
class Terrain;

#include "Weather.h"
class Weather;

#include <memory>
#include <vector>

//
//
//
class Battle
{
	Matrix<Player_Pokemon> _teams;
	std::shared_ptr<Weather> _weather;
	std::shared_ptr<Terrain> _terrain;

	public:

	Battle() = default;
	Battle(const Battle& battle) = delete;
	Battle(Battle&& battle) = delete;

	Battle(const std::vector<std::vector<Player_Pokemon>>& teams, const Weather& weather, const Terrain& terrain);

	Battle& operator = (const Battle& battle) = delete;
	Battle& operator = (Battle&& battle) = delete;

	~Battle() = default;

	Weather& weather() const;

	Terrain& terrain() const;

	void setWeather(const Weather& weather);

	void setTerrain(const Terrain& terrain);
};

#endif // BATTLE_H_INCLUDED