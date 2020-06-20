// RPGGame
// Pokemon.h
// Justyn Durnford
// Created on 4/12/2020
// Last updated on 6/20/2020

#ifndef POKEMON_HPP
#define POKEMON_HPP

#include "Type.h"
class Type;

#include "Ability.h"
class Ability;

#include <string>
#include <memory>
#include <array>

//
//
//
class Pokemon
{
	std::string _name = "";
	unsigned short _natIndex = -1;
	unsigned short _regIndex = -1;
	std::shared_ptr<Type> _type1 = nullptr;
	std::shared_ptr<Type> _type2 = nullptr;
	std::shared_ptr<Ability> _ability1 = nullptr;
	std::shared_ptr<Ability> _ability2 = nullptr;
	float _genderRatio = 0;
	// std::shared_ptr<Egg_Group> _eg1 = nullptr;
	// std::shared_ptr<Egg_Group> _eg2 = nullptr;
	float _height = 0;
	float _weight = 0;
	std::array<unsigned char, 6> _evYield = { 0, 0, 0, 0, 0, 0 };
	std::array<unsigned char, 6> _baseStats = { 0, 0, 0, 0, 0, 0 };

	void loadPokemon();

	public:

	// Default constructor.
	Pokemon();

	// Primary constructor.
	Pokemon(unsigned short natIndex);

	// Destructor.
	~Pokemon();

	// Returns _name.
	std::string name() const;

	// Returns _natIndex.
	unsigned short natIndex() const;

	// Returns _regIndex.
	unsigned short regIndex() const;

	// Returns _type1.
	std::shared_ptr<Type> type1() const;

	// Returns _type2.
	std::shared_ptr<Type> type2() const;

	// Returns _ability1.
	std::shared_ptr<Ability> ability1() const;

	// Returns _ability2.
	std::shared_ptr<Ability> ability2() const;

	// Returns _genderRatio.
	float genderRatio() const;

	// Returns _eg1.
	// std::shared_ptr<Egg_Group> eg1() const;

	// Returns _eg2.
	// std::shared_ptr<Egg_Group> eg2() const;

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