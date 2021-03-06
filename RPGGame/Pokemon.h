// RPGGame
// Pokemon.h
// Justyn Durnford
// Created on 2020-04-12
// Last updated on 2020-09-28

#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED

#include "Ability.h"
class Ability;

#include "Egg_Group.h"
class Egg_Group;

#include "Type.h"
class Type;

#include <array>
#include <memory>
#include <string>

//
//
//
class Pokemon
{
	unsigned short _id = 0;
	std::string _name;
	std::string _desc;
	std::shared_ptr<Type> _type1;
	std::shared_ptr<Type> _type2;
	std::shared_ptr<Ability> _ability1;
	std::shared_ptr<Ability> _ability2;
	unsigned short _maleRatio = 0;
	std::shared_ptr<Egg_Group> _eg1;
	std::shared_ptr<Egg_Group> _eg2;
	float _height = 0;
	float _weight = 0;
	std::array<unsigned char, 6> _evYield = { 0, 0, 0, 0, 0, 0 };
	std::array<unsigned char, 6> _baseStats = { 0, 0, 0, 0, 0, 0 };

	public:

	// Default constructor.
	Pokemon() = default;

	// Copy constructor.
	Pokemon(const Pokemon& pokemon) = default;

	// Move constructor.
	Pokemon(Pokemon&& pokemon) = default;

	// Primary constructor.
	Pokemon(unsigned short id);

	// Destructor.
	~Pokemon() = default;

	// Returns _id.
	unsigned short id() const;

	// Returns _name.
	std::string name() const;

	// Returns _desc.
	std::string desc() const;

	// Returns _type1.
	std::shared_ptr<Type> type1() const;

	// Returns _type2.
	std::shared_ptr<Type> type2() const;

	// Returns _ability1.
	std::shared_ptr<Ability> ability1() const;

	// Returns _ability2.
	std::shared_ptr<Ability> ability2() const;

	// Returns _maleRatio.
	unsigned short maleRatio() const;

	// Returns _eg1.
	std::shared_ptr<Egg_Group> eg1() const;

	// Returns _eg2.
	std::shared_ptr<Egg_Group> eg2() const;

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

#endif // POKEMON_H_INCLUDED