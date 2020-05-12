// Ability.hpp
// Justyn Durnford
// Created on 4/12/2020
// Last updated on 4/25/2020

#ifndef ABILITY_HPP
#define ABILITY_HPP

#include "Enviornment.hpp"

#include "Pokemon.hpp"
class Pokemon;
class Player_Pokemon;

class Ability
{
	std::string _name;
	std:::string _desc;

	public:

	Ability(const std::string& name, const std::string& desc);
	~Ability();

	void effect(Enviornment& env);
};

void Drought();

void Levitate(Player_Pokemon& a);

void Magnet_Pull(Player_Pokemon& d);

void Rough_Skin(Player_Pokemon& a, Player_Pokemon& d);

void Sand_Stream();

void Sand_Veil(Player_Pokemon& a);

#endif // ABILITY_HPP