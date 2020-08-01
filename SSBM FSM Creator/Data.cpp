// SSBM FSM Creator
// Data.cpp
// Justyn Durnford
// Created on 7/31/2020
// Last updated on 7/31/2020

#include "Data.h"
#include "Subaction.h"
#include "Character.h"
#include "Tools.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <fstream>
using std::ifstream;
using std::ofstream;

void init_characters()
{
	string line = "";
	string subaction_name = "";
	unsigned short subaction_id = 0;

	// Load character data
	for (unsigned short i = 0; i < character_list.size(); ++i)
	{
		ifstream fin("Data/" + character_list[i].name() + ".txt");

		while (fin.good())
		{
			getline(fin, line);
			subaction_id = hex_to_int(line.substr(0, line.find(' ')));
			subaction_name = line.substr(line.find(' ') + 1);
			character_list[i].addSubaction(subaction_name, subaction_id);
		}
	}
}

vector<Character> character_list =
{
	{ "Captain Falcon", 0x0 }, { "Donkey Kong", 0x1 }, { "Fox", 0x2 },
	{ "Mr. Game & Watch", 0x3 }, { "Kirby", 0x4 }, { "Bowser", 0x5 },
	{ "Link", 0x6 }, { "Luigi", 0x7 }, { "Mario", 0x8 },
	{ "Marth", 0x9 }, { "Mewtwo", 0xa }, { "Ness", 0xb },
	{ "Peach", 0xc }, { "Pikachu", 0xd }, { "Ice Climbers", 0xe },
	{ "Jigglypuff", 0xf }, { "Samus", 0x10 }, { "Yoshi", 0x11 },
	{ "Zelda", 0x12 }, { "Sheik", 0x13 }, { "Falco", 0x14 },
	{ "Young Link", 0x15 }, { "Dr. Mario", 0x16 }, { "Roy", 0x17 },
	{ "Pichu", 0x18 }, { "Ganondorf", 0x19 }
};