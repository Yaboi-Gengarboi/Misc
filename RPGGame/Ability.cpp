// RPGGame
// Ability.cpp
// Justyn Durnford
// Created on 2020-05-15
// Last updated on 2020-09-29

#include "Ability.h"

#include "Battle.h"
class Battle;

#include "Terrain.h"
class Terrain;

#include "Weather.h"
class Weather;

#include <string>
using std::string;

Ability::Ability(unsigned char id, const char* name, const char* desc)
{
	_id = id;
	_name = name;
	_desc = desc;
}

unsigned char Ability::id() const
{
	return _id;
}

string Ability::name() const
{
	return _name;
}

string Ability::desc() const
{
	return _desc;
}

void Ability::operator() (Battle& battle)
{
	switch (_id)
	{
		case 3:
			battle.setWeather(weather_arr[0]);
			break;

		case 28:
			battle.setWeather(weather_arr[2]);
			break;

		case 29:
			battle.setWeather(weather_arr[1]);
			break;

		case 33:
			battle.setTerrain(terrain_arr[1]);
			break;

		case 50:
			battle.setTerrain(terrain_arr[2]);
			break;

		case 85:
			battle.setTerrain(terrain_arr[3]);
			break;

		case 109:
			battle.setTerrain(terrain_arr[4]);
			break;

		case 121:
			battle.setWeather(weather_arr[3]);
			break;

		case 134:
			battle.setWeather(weather_arr[4]);
			break;

		default:
			break;
	}
}