// RPGGame
// Initialize.cpp
// Justyn Durnford
// Created on 7/3/2020
// Last updated on 7/19/2020

#include "Initialize.h"

#include <string>
using std::string;
using std::to_string;
using std::getline;

#include <fstream>
using std::ifstream;

#include <vector>
using std::vector;

string reverse_str(const string& str)
{
	string newstr = "";

	for (unsigned long long i = str.size(); i > 0; --i)
		newstr += str[i - 1];

	return newstr;
}

string to_hex(unsigned long long i)
{
	string hexstr = "";
	unsigned char rem = 0;

	if (i == 0)
		return "0";

	while (i != 0)
	{
		rem = i % 16;

		switch (rem)
		{
			case 10:
				hexstr += 'a';
				break;

			case 11:
				hexstr += 'b';
				break;

			case 12:
				hexstr += 'c';
				break;

			case 13:
				hexstr += 'd';
				break;

			case 14:
				hexstr += 'e';
				break;

			case 15:
				hexstr += 'f';
				break;

			default:
				hexstr += rem + 48;
				break;
		}

		i /= 16;
	}

	return reverse_str(hexstr);
}

string to_hex(float f)
{
	int* pf = (int*)&f;

	return to_hex((unsigned long long)*pf);
}

bool load_abilities()
{
	ifstream fin("Data/Abilities.txt");
	string name("");
	string desc("");

	for (unsigned char c = 0; c < 179; ++c)
	{
		getline(fin, name);
		getline(fin, desc);

		ability_list.push_back(Ability(c, name, desc));
	}

	return true;
}

bool load_moves()
{
	return true;
}

bool load_pokemon()
{
	return true;
}

bool load_player_pokemon()
{
	return true;
}