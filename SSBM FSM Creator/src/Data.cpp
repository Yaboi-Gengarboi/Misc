// SSBM FSM Creator
// Data.cpp
// Justyn Durnford
// Created on 2020-07-31
// Last updated on 2021-01-04

#include "Data.h"

array<Character, 27> character_list =
{
	Character(0x0, "Captain Falcon"), Character(0x1, "Donkey Kong"), Character(0x2, "Fox"),
	Character(0x3, "Mr. Game & Watch"), Character(0x4, "Kirby"), Character(0x5, "Bowser"),
	Character(0x6, "Link"), Character(0x7, "Luigi"), Character(0x8, "Mario"),
	Character(0x9, "Marth"), Character(0xa, "Mewtwo"), Character(0xb, "Ness"),
	Character(0xc, "Peach"), Character(0xd, "Pikachu"), Character(0xe, "Ice Climbers"),
	Character(0xf, "Jigglypuff"), Character(0x10, "Samus"), Character(0x11, "Yoshi"),
	Character(0x12, "Zelda"), Character(0x13, "Sheik"), Character(0x14, "Falco"),
	Character(0x15, "Young Link"), Character(0x16, "Dr. Mario"), Character(0x17, "Roy"),
	Character(0x18, "Pichu"), Character(0x19, "Ganondorf"), Character(0xff, "All")
};

vector<vector<FSM>> fsm_list(0x1b);

bool init_characters()
{
	string line;
	string subaction_name;
	uint16_t subaction_id(0);

	// Load character data
	for (size_t i = 0; i < 27; ++i)
	{
		ifstream fin("Data/" + character_list[i].name + ".txt");

		if (fin.bad())
			return false;

		while (fin.good())
		{
			getline(fin, line);
			subaction_id = stoi(line.substr(0, line.find(' ')));
			subaction_name = line.substr(4);
			character_list[i].subList.insert_or_assign(subaction_id, Subaction(subaction_id, subaction_name));
		}
	}

	return true;
}

void sort_fsm_list()
{
	for (size_t i = 0; i < 27; ++i)
	{
		if (fsm_list[i].size() < 2)
			continue;

		bool sorted = false;

		while (!sorted)
		{
			sorted = true;

			for (size_t p = 0; p < fsm_list[i].size() - 1; ++p)
			{
				if (compare(fsm_list[i][p], fsm_list[i][p + 1]) == strong_ordering::greater)
				{
					swap(fsm_list[i][p], fsm_list[i][p + 1]);
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

array<vector<string>, 2> fsm_list_strings()
{
	array<vector<string>, 2> str_arr;

	for (size_t i = 0; i < 27; ++i)
	{
		for (size_t p = 0; p < fsm_list[i].size(); ++p)
		{
			str_arr[0].push_back(fsm_list[i][p].toHex());
			str_arr[1].push_back(fsm_list[i][p].toString());
		}
	}

	return str_arr;
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
	uint8_t frame = 0;
	Subaction subaction;
	float multiplier = 0.0f;

	size_t pos_begin = 0;
	size_t pos_end = 0;

	if (fin.bad())
		return false;

	if (fin.eof())
		return true;

	while (line != "--------------------------------------------------")
		getline(fin, line);

	getline(fin, line);

	while (!fin.eof())
	{
		getline(fin, line);

		if (fin.eof())
			break;

		pos_begin = 0;
		pos_end = line.find(',');
		for (size_t i = 0; i < 27; ++i)
		{
			if (range_substr(line, pos_begin, pos_end) == character_list[i].name)
				character = character_list[i];
		}

		pos_begin = pos_end + 2;
		pos_end = line.find(", x", pos_begin);
		auto iter = character.subList.begin();
		bool found = false;
		while (iter != character.subList.end() && !found)
		{
			if (range_substr(line, pos_begin, pos_end) == iter->second.name)
			{
				subaction = iter->second;
				found = true;
			}
			++iter;
		}

		pos_begin = pos_end + 3;
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

		pos_begin = pos_end + 4;
		try
		{
			int i = stoi(line.substr(pos_begin));

			if (i >= 0 && i <= 255)
				frame = uint8_t(i);
		}
		catch (const invalid_argument& ia)
		{
			return false;
		}

		fsm_list[character.id].push_back(FSM(character, frame, subaction, multiplier));
	}

	return true;
}

void write_fsms()
{
	array<vector<string>, 2> str_arr = fsm_list_strings();
	ofstream fout("Data/FSM_file.txt", ofstream::out | ofstream::trunc);

	for (size_t i = 0; i < str_arr[0].size(); ++i)
	{
		if (i % 2 == 0)
			fout << str_arr[0][i] << ' ';
		else
			fout << str_arr[0][i] << endl;
	}

	fout << endl << "--------------------------------------------------" << endl << endl;

	for (size_t i = 0; i < str_arr[1].size(); ++i)
		fout << str_arr[1][i] << endl;
}