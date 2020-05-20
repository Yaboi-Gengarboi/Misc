// RPGGame
// Enviornment.cpp
// Justyn Durnford
// Created on 5/16/2020
// Last updated on 5/20/2020

#include "Enviornment.hpp"
#include "Pokemon.hpp"
#include "Type.hpp"
#include "Ability.hpp"

#include <string>
using std::string;

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <array>
using std::array;

Weather::Weather()
{
	// See Enviornment.hpp for default values
}

Weather::Weather(const string& name, const string& start,
				 const string& end, const string& turn,
				 const string& damage, unsigned char id)
{
	_name = name;
	_start = start;
	_end = end;
	_turn = turn;
	_damage = damage;
	_id = id;
}

Weather::~Weather() { /* Destructor */ }

string Weather::name() const
{
	return _name;
}

string Weather::start() const
{
	return _start;
}

string Weather::end() const
{
	return _end;
}

string Weather::turn() const
{
	return _turn;
}

string Weather::damage() const
{
	return _damage;
}

unsigned char Weather::id() const
{
	return _id;
}

Enviornment::Enviornment()
{
	// See Enviornment.hpp for default values
}

// TODO:
// Set active pokemon
// Check if any active pokemon has a weather-changing ability
// Make order of attackers
Enviornment::Enviornment(array<shared_ptr<Player_Pokemon>, 6> team1,
						 array<shared_ptr<Player_Pokemon>, 6> team2,
						 shared_ptr<Weather> weather)
{
	_team1 = team1;
	_team2 = team2;

	_weather = weather;

}

Enviornment::~Enviornment() { /* Destructor */ }

shared_ptr<Weather> Enviornment::weather() const
{
	return _weather;
}

void Enviornment::setWeather(shared_ptr<Weather> weather)
{
	_weather = weather;
}

shared_ptr<Weather> Sunny_Weather = make_shared<Weather>
(
	"Harsh sunlight", "The sunlight turned harsh!", "The harsh sunlight faded.",
	"The sunlight is strong.", "", 1
);

shared_ptr<Weather> Rain_Weather = make_shared<Weather>
(
	"Heavy rain", "Rain started to fall!", "The rain stopped.",
	"The rain is pouring.", "", 2
);

shared_ptr<Weather> Sandstorm_Weather = make_shared<Weather>
(
	"Sandstorm", "A sandstorm was wipped up!", "The sandstorm stopped.",
	"The sandstorm rages on.", " took damage from the sandstorm.", 3
);

shared_ptr<Weather> Hail_Weather = make_shared<Weather>
(
	"Hail", "Hail began to fall!", "The hail stopped falling.",
	"Hail continues to fall.", " took damage from the hail!", 4
);