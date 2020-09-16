// RPGGame
// Data.cpp
// Justyn Durnford
// Created on 2020-08-14
// Last updated on 2020-09-12

#include "Data.h"

#include "Move.h"
class Move;

#include "Pokemon.h"
class Pokemon;

#include "Player_Pokemon.h"
class Player_Pokemon;

#include <cstddef>
using std::size_t;

#include <fstream>
using std::ifstream;

#include <string>
using std::string;
using std::to_string;
using std::stol;

#include <vector>
using std::vector;

vector<Ability> ability_list;
vector<Pokemon> pokemon_list;
vector<Move> move_list;
vector<bool> move_contact_list;

string long_to_hex(long i)
{
	string hexstr;
	unsigned char rem = 0;

	if (i == 0)
		return "0";

	while (i != 0)
	{
		rem = i % 16;

		switch (rem)
		{
			case 10:
				hexstr.insert(0, 1, 'A');
				break;

			case 11:
				hexstr.insert(0, 1, 'B');
				break;

			case 12:
				hexstr.insert(0, 1, 'C');
				break;

			case 13:
				hexstr.insert(0, 1, 'D');
				break;

			case 14:
				hexstr.insert(0, 1, 'E');
				break;

			case 15:
				hexstr.insert(0, 1, 'F');
				break;

			default:
				hexstr.insert(0, to_string(rem));
				break;
		}

		i /= 16;
	}

	return hexstr;
}

string float_to_hex(float f)
{
	long* pf = (long*)&f;
	return long_to_hex(*pf);
}

string eng_to_hex(const string& str)
{
	string hexstr;

	for (size_t i = 0; i < str.size(); ++i)
	{
		hexstr += long_to_hex(str[i]);
	}

	return hexstr + "00";
}

long hex_to_long(const string& str)
{
	return stol(str, nullptr, 16);
}

string hex_to_eng(const string& str)
{
	string engstr;
	string hexsubstr;
	std::size_t i = 0;

	do
	{
		hexsubstr = str.substr(i, 2);
		engstr += hex_to_long(hexsubstr);
		i += 2;
	}
	while (hexsubstr != "00");

	return engstr;
}

bool load_abilities()
{
	ifstream fin("Data/Abilities.txt");
	unsigned char id = 0;
	string name;
	string desc;

	if (!fin)
		return false;

	while (!fin.eof())
	{
		++id;
		getline(fin, name);
		getline(fin, desc);

		ability_list.push_back(Ability(id, name, desc));
	}

	if (id != 175)
		return false;

	return true;
}

bool load_moves()
{
	return false;
}

bool load_pokemon()
{
	return false;
}

bool load_player_pokemon()
{
	return false;
}