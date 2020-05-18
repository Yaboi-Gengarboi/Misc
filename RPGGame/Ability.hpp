// RPGGame
// Ability.hpp
// Justyn Durnford
// Created on 4/12/2020
// Last updated on 5/17/2020

#ifndef ABILITY_HPP
#define ABILITY_HPP

#include "Enviornment.hpp"
class Enviornment;

#include "Pokemon.hpp"
class Pokemon;
class Player_Pokemon;

// #include <string>
// #include <array>
// #include <memory>

class Ability
{
	protected:

	std::string _name = "";
	std::string _desc = "";
	unsigned short int _id = -1;

	public:

	Ability();
	Ability(const std::string& name, const std::string& desc, unsigned short int id);

	virtual ~Ability();

	std::string name() const;

	std::string desc() const;

	unsigned short int id() const;
};

extern std::shared_ptr<Ability> Cute_Charm;

#endif // ABILITY_HPP