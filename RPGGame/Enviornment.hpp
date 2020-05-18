// RPGGame
// Enviornment.hpp
// Justyn Durnford
// Created on 4/20/2020
// Last updated on 5/17/2020

#ifndef ENVIORNMENT_HPP
#define ENVIORNMENT_HPP

#include "Pokemon.hpp"
class Pokemon;
class Player_Pokemon;

#include "Type.hpp"
struct Type;

#include "Ability.hpp"
class Ability;

#include <string>
#include <memory>
#include <array>
#include <vector>

struct Weather
{
	std::string _name = "";
	std::string _start = "";
	std::string _end = "";
	std::string _turn = "";
	std::string _damage = "";

	unsigned char _id = -1;

	Weather();
	Weather(const std::string& name, const std::string& start,
			const std::string& end, const std::string& turn,
			const std::string& damage, unsigned char id);

	~Weather();

	std::string name() const;

	std::string start() const;

	std::string end() const;

	std::string turn() const;

	std::string damage() const;

	unsigned char id() const;
};

class Enviornment
{
	std::array<std::shared_ptr<Player_Pokemon>, 6> _team1;
	std::array<std::shared_ptr<Player_Pokemon>, 6> _team2;

	std::array<std::shared_ptr<Player_Pokemon>, 3> _team1Active;
	std::array<std::shared_ptr<Player_Pokemon>, 3> _team2Active;

	std::vector<std::shared_ptr<Player_Pokemon>> _order;

	std::shared_ptr<Weather> _weather = nullptr;

	public:

	Enviornment();
	Enviornment(std::array<std::shared_ptr<Player_Pokemon>, 6> team1,
				std::array<std::shared_ptr<Player_Pokemon>, 6> team2,
				std::shared_ptr<Weather> weather);

	~Enviornment();

	std::shared_ptr<Weather> weather() const;

	void setWeather(std::shared_ptr<Weather> weather);
};

extern std::shared_ptr<Weather> Sunny_Weather;
extern std::shared_ptr<Weather> Rain_Weather;
extern std::shared_ptr<Weather> Sandstorm_Weather;
extern std::shared_ptr<Weather> Hail_Weather;

#endif // ENVIORNMENT_HPP