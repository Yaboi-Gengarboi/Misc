// Pokemon.hpp
// Justyn Durnford
// Created on 4/12/2020
// Last updated on 4/30/2020

#ifndef POKEMON_HPP
#define POKEMON_HPP

#include "Type.hpp"
#include "Ability.hpp"

class Ability;

#include <string>
#include <array>
#include <memory>

class Pokemon
{
	std::string _name;
	unsigned int _index;
	std::shared_ptr<Type> _type1;
	std::shared_ptr<Type> _type2;
	std::array<unsigned char, 6> _baseStats;
	float _height;
	float _weight;

	std::shared_ptr<Pokemon> _evol;

	public:

	Pokemon(const std::string& name, unsigned int index, std::shared_ptr<Type> type1,
			std::shared_ptr<Type> type2, const std::array<unsigned char, 6>& baseStats,
			float height, float weight);

	~Pokemon();

	protected:

	// Returns _name
	std::string name() const;

	// Returns _index
	unsigned int index() const;

	// Returns _type1
	std::shared_ptr<Type> type1() const;

	// Returns _type2
	std::shared_ptr<Type> type2() const;

	// Returns _baseStats[0]
	unsigned char baseHP() const;

	// Returns _baseStats[1]
	unsigned char baseAtk() const;

	// Returns _baseStats[2]
	unsigned char baseDef() const;

	// Returns _baseStats[3]
	unsigned char baseSpAtk() const;

	// Returns _baseStats[4]
	unsigned char baseSpDef() const;

	// Returns _baseStats[5]
	unsigned char baseSpe() const;

	// Returns _height
	float height() const;

	// Returns _weight
	float weight() const;
};

class Player_Pokemon : public Pokemon
{
	std::string _nickname;
	std::shared_ptr<Type> _battleType1;
	std::shared_ptr<Type> _battleType2;
	std::array<unsigned char, 6> _battleStats;
	float _battleWeight;
};

#endif // POKEMON_HPP