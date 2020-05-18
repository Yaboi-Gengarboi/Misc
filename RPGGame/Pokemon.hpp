// RPGGame
// Pokemon.hpp
// Justyn Durnford
// Created on 4/12/2020
// Last updated on 5/17/2020

#ifndef POKEMON_HPP
#define POKEMON_HPP

#include "Type.hpp"
#include "Ability.hpp"

struct Type;
class Ability;

// #include <string>
// #include <memory>

#include <array>

class Pokemon
{
	protected:

	std::string _name = "";
	unsigned int _index = -1;
	std::shared_ptr<Type> _type1 = nullptr;
	std::shared_ptr<Type> _type2 = nullptr;
	std::array<unsigned char, 6> _baseStats = { 0, 0, 0, 0, 0, 0 };
	float _height = 0;
	float _weight = 0;

	std::shared_ptr<Ability> _ability1 = nullptr;
	std::shared_ptr<Ability> _ability2 = nullptr;

	std::shared_ptr<Pokemon> _evol = nullptr;

	public:

	Pokemon();

	Pokemon(const std::string& name, unsigned int index, const Type& type1,
			const Type& type2, unsigned char baseHP, unsigned char baseAtk, unsigned char baseDef, 
			unsigned char baseSpAtk, unsigned char baseSpDef, unsigned char baseSpd,
			float height, float weight, std::shared_ptr<Ability> ability1, std::shared_ptr<Ability> ability2,
			std::shared_ptr<Pokemon> evol);

	virtual ~Pokemon();

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

	// Returns _evol
	std::shared_ptr<Pokemon> evolution() const;
};

class Player_Pokemon : public Pokemon
{
	std::string _nickname;
	std::shared_ptr<Type> _battleType1;
	std::shared_ptr<Type> _battleType2;
	std::array<unsigned short int, 6> _stats;
};

extern std::shared_ptr<Pokemon> Jigglypuff;
extern std::shared_ptr<Pokemon> Wigglytuff;

extern std::shared_ptr<Pokemon> Azumarill;

#endif // POKEMON_HPP