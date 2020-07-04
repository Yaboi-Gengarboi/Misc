// RPGGame
// Pokemon.h
// Justyn Durnford
// Created on 4/12/2020
// Last updated on 7/3/2020

#ifndef POKEMON_HPP
#define POKEMON_HPP

#include "Type.h"
class Type;

#include "Ability.h"
class Ability;

#include "Egg_Group.h"
class Egg_Group;

#include <string>
#include <memory>
#include <array>

//
//
//
class Pokemon
{
	std::string _name = "";
	std::string _desc = "";
	unsigned short _index = 0;
	unsigned char _type1 = 0;
	unsigned char _type2 = 0;
	unsigned char _ability1 = 0;
	unsigned char _ability2 = 0;
	float _genderRatio = 0;
	unsigned char _eg1 = 0;
	unsigned char _eg2 = 0;
	float _height = 0;
	float _weight = 0;
	std::array<unsigned char, 6> _evYield = { 0, 0, 0, 0, 0, 0 };
	std::array<unsigned char, 6> _baseStats = { 0, 0, 0, 0, 0, 0 };

	void loadPokemon();

	public:

	// Default constructor.
	Pokemon();

	// Primary constructor.
	Pokemon(unsigned short index);

	// Destructor.
	~Pokemon();

	// Returns _name.
	std::string name() const;

	// Returns _desc.
	std::string desc() const;

	// Returns _index.
	unsigned short index() const;

	// Returns type_list[_type1].
	Type& type1() const;

	// Returns type_list[_type2].
	Type& type2() const;

	// Returns ability_list[_ability1].
	Ability& ability1() const;

	// Returns ability_list[_ability2].
	Ability& ability2() const;

	// Returns _genderRatio.
	float genderRatio() const;

	// Returns egg_group_list[_eg1].
	Egg_Group& eg1() const;

	// Returns egg_group_list[_eg2].
	Egg_Group& eg2() const;

	// Returns _height.
	float height() const;

	// Returns _weight.
	float weight() const;

	// Returns _evYield[0].
	unsigned char evHP() const;

	// Returns _evYield[1].
	unsigned char evAtk() const;

	// Returns _evYield[2].
	unsigned char evDef() const;

	// Returns _evYield[3].
	unsigned char evSpAtk() const;

	// Returns _evYield[4].
	unsigned char evSpDef() const;

	// Returns _evYield[5].
	unsigned char evSpe() const;

	// Returns _baseStats[0].
	unsigned char baseHP() const;

	// Returns _baseStats[1].
	unsigned char baseAtk() const;

	// Returns _baseStats[2].
	unsigned char baseDef() const;

	// Returns _baseStats[3].
	unsigned char baseSpAtk() const;

	// Returns _baseStats[4].
	unsigned char baseSpDef() const;

	// Returns _baseStats[5].
	unsigned char baseSpe() const;
};

void load_Pokemon();

#endif // POKEMON_HPP