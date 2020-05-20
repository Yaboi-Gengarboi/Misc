// RPGGame
// Ability.hpp
// Justyn Durnford
// Created on 4/12/2020
// Last updated on 5/20/2020

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
	unsigned char _type = -1;

	public:

	Ability();
	Ability(const std::string& name, const std::string& desc, unsigned short int id, unsigned char type);

	virtual ~Ability();

	std::string name() const;

	std::string desc() const;

	unsigned short int id() const;

	unsigned char type() const;
};

extern std::shared_ptr<Ability> Air_Lock;
void _Air_Lock(Enviornment& env);

extern std::shared_ptr<Ability> Cute_Charm;
void _Cute_Charm(Player_Pokemon& pokemon);

extern std::shared_ptr<Ability> Drizzle;
void _Drizzle(Enviornment& env);

extern std::shared_ptr<Ability> Drought;
void _Drought(Enviornment& env);

extern std::shared_ptr<Ability> Huge_Power;
void _Huge_Power(Player_Pokemon& pokemon);

extern std::shared_ptr<Ability> Intimidate;
void _Intimidate(Player_Pokemon& pokemon);

extern std::shared_ptr<Ability> Magic_Guard;
void _Magic_Guard(Player_Pokemon& pokemon);

#endif // ABILITY_HPP