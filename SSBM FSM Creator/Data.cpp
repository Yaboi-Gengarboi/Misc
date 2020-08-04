// SSBM FSM Creator
// Data.cpp
// Justyn Durnford
// Created on 7/31/2020
// Last updated on 8/2/2020

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

vector<vector<FSM>> fsm_list(0x1a);

void init_characters()
{
	string line = "";
	string subaction_name = "";
	unsigned short subaction_id = 0;

	// Load character data
	for (unsigned char i = 0; i < character_list.size(); ++i)
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

void add_fsm(const Character& character, unsigned char frame, const Subaction& subaction, float multiplier)
{
	fsm_list[character.id()].push_back(FSM(character, frame, subaction, multiplier));
}

void swap_fsms(FSM& a, FSM& b)
{
	FSM c = a;
	a = b;
	b = c;
}

void sort_fsm_list()
{
	for (unsigned char i = 0; i < fsm_list.size(); ++i)
	{
		if (fsm_list[i].size() < 2)
			continue;

		bool sorted = false;

		while (!sorted)
		{
			sorted = true;

			for (unsigned long long p = 0; p < fsm_list[i].size() - 1; ++p)
			{
				if (fsm_list[i][p].subaction().id() > fsm_list[i][p + 1].subaction().id())
				{
					swap_fsms(fsm_list[i][p], fsm_list[i][p + 1]);
					sorted = false;
					break;
				}
				else if (fsm_list[i][p].frame() < fsm_list[i][p + 1].frame())
				{
					swap_fsms(fsm_list[i][p], fsm_list[i][p + 1]);
					sorted = false;
					break;
				}
				else if (fsm_list[i][p] == fsm_list[i][p + 1])
				{
					fsm_list[i].erase(fsm_list[i].begin() + p);
					sorted = false;
					break;
				}
			}
		}
	}
}

vector<string> fsm_list_strings()
{
	vector<string> str_vec = { "", "" };
	unsigned long long count = 0;

	for (unsigned char i = 0; i < fsm_list.size(); ++i)
	{
		for (unsigned long long p = 0; p < fsm_list[i].size(); ++p)
		{

			if (count % 2 == 0 && count != 0)
				str_vec[0] += '\n';
			else if (count != 0)
				str_vec[0] += ' ';

			str_vec[0] += fsm_list[i][p].toHex();

			if (count != 0)
				str_vec[1] += '\n';

			str_vec[1] += fsm_list[i][p].toString();

			++count;
		}
	}

	return str_vec;
}

bool is_fsm_file_empty()
{
	ifstream fin("Data/FSM_file.txt");

	return fin.eof();
}

void read_fsms()
{
	ifstream fin("Data/FSM_file.txt");
	string line;

	while (fin.good())
	{
		getline(fin, line);
	}
}

void write_fsms()
{
	vector<string> str_vec = fsm_list_strings();
	ofstream fout("Data/FSM_file.txt", ofstream::out | ofstream::trunc);
	fout << str_vec[0] << "\n\n";
}