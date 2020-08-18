// RPGGame
// Data.cpp
// Justyn Durnford
// Created on 8/14/2020
// Last updated on 8/17/2020

#include "Data.h"

#include "Pokemon.h"
class Pokemon;

#include "Player_Pokemon.h"
class Player_Pokemon;

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include <vector>
using std::vector;

vector<Ability> ability_list;
vector<Pokemon> pokemon_list;

string to_hex(long i)
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
				hexstr.insert(0, 1, rem + 48);
				break;
		}

		i /= 16;
	}

	return hexstr;
}

string to_hex(float f)
{
	long* pf = (long*)&f;
	return to_hex(*pf);
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