// SSBM FSM Creator
// Data.cpp
// Justyn Durnford
// Created on 7/31/2020
// Last updated on 8/14/2020

#include "Data.h"
#include "Subaction.h"
#include "Character.h"
#include "Tools.h"

#include <string>
using std::string;
using std::stoi;
using std::stof;

#include <vector>
using std::vector;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <stdexcept>
using std::invalid_argument;

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

bool init_characters()
{
	string line = "";
	string subaction_name = "";
	unsigned short subaction_id = 0;

	// Load character data
	for (unsigned char i = 0; i < character_list.size(); ++i)
	{
		ifstream fin("Data/" + character_list[i].name() + ".txt");

		if (fin.bad())
			return false;

		while (fin.good())
		{
			getline(fin, line);
			subaction_id = hex_to_int(line.substr(0, line.find(' ')));
			subaction_name = line.substr(line.find(' ') + 1);
			character_list[i].addSubaction(subaction_name, subaction_id);
		}
	}

	return true;
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

	if (fsm_list.size() != 0)
	{
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
	}

	return str_vec;
}

bool is_fsm_file_empty()
{
	ifstream fin("Data/FSM_file.txt");

	return fin.eof();
}

bool read_fsms()
{
	ifstream fin("Data/FSM_file.txt");
	string line;

	Character character;
	Subaction subaction;
	float multiplier = -1;
	unsigned short frame = -1;

	unsigned long long pos_begin = 0;
	unsigned long long pos_end = 0;

	if (fin.bad())
		return false;

	if (fin.eof())
		return true;

	while (!line.empty())
		getline(fin, line);

	getline(fin, line);

	while (!fin.eof())
	{
		getline(fin, line);

		pos_end = line.find(',');
		for (unsigned char i = 0; i < character_list.size(); ++i)
		{
			if (range_substr(line, pos_begin, pos_end) == character_list[i].name())
			{
				character = character_list[i];
				break;
			}
		}

		if (character.id() == -1)
			return false;

		pos_begin = pos_end;
		pos_end = line.find(", x", pos_begin);
		auto iter = character.subList().begin();
		while (iter != character.subList().end())
		{
			if (range_substr(line, pos_begin, pos_end) == iter->second.name())
			{
				subaction = iter->second;
				break;
			}
			++iter;
		}

		if (subaction.id() == -1)
			return false;

		pos_begin = pos_end;
		pos_end = line.find(", @ ");
		try
		{
			multiplier = stof(range_substr(line, pos_begin, pos_end));
		}
		catch (const invalid_argument& ia)
		{
			return false;
		}

		if (multiplier <= 0)
			return false;

		pos_begin = pos_end;
		try
		{
			int i = stoi(line.substr(pos_begin));

			if (i >= 0 && i <= 255)
				frame = unsigned char(i);
		}
		catch (const invalid_argument& ia)
		{
			return false;
		}

		add_fsm(character, frame, subaction, multiplier);
	}

	return true;
}

void write_fsms()
{
	vector<string> str_vec = fsm_list_strings();
	ofstream fout("Data/FSM_file.txt", ofstream::out | ofstream::trunc);

	if (fsm_list.size() != 0)
	{
		fout << str_vec[0] << "\n\n";
		fout << str_vec[1];
	}
}