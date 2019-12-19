//SSBM FSM Creator
//FSM.cpp
//Justyn P. Durnford
//Created on 12/18/2019
//Last Updated on 12/18/2019

#include "FSM.hpp"

#include <string>
using std::string;
using std::to_string;
using std::stoi;
using std::stof;

#include <array>
using std::array;

#include <utility>
using std::pair;
using std::make_pair;

#include <stdexcept>
using std::invalid_argument;

void FSM::set_character(const string& param_str)
{
	if (param_str == "Captain Falcon") FSM_character = 0;
	else if (param_str == "Donkey Kong") FSM_character = 1;
	else if (param_str == "Fox") FSM_character = 2;
	else if (param_str == "Game&Watch") FSM_character = 3;
	else if (param_str == "Kirby") FSM_character = 4;
	else if (param_str == "Bowser") FSM_character = 5;
	else if (param_str == "Link") FSM_character = 6;
	else if (param_str == "Luigi") FSM_character = 7;
	else if (param_str == "Mario") FSM_character = 8;
	else if (param_str == "Marth") FSM_character = 9;
	else if (param_str == "Mewtwo") FSM_character = 10;
	else if (param_str == "Ness") FSM_character = 11;
	else if (param_str == "Peach") FSM_character = 12;
	else if (param_str == "Pikachu") FSM_character = 13;
	else if (param_str == "Ice Climbers") FSM_character = 14;
	else if (param_str == "Jigglypuff") FSM_character = 15;
	else if (param_str == "Samus") FSM_character = 16;
	else if (param_str == "Yoshi") FSM_character = 17;
	else if (param_str == "Zelda") FSM_character = 18;
	else if (param_str == "Sheik") FSM_character = 19;
	else if (param_str == "Falco") FSM_character = 20;
	else if (param_str == "Young Link") FSM_character = 21;
	else if (param_str == "Dr. Mario") FSM_character = 22;
	else if (param_str == "Roy") FSM_character = 23;
	else if (param_str == "Pichu") FSM_character = 24;
	else if (param_str == "Ganondorf") FSM_character = 25;
	else if (param_str == "Popo") FSM_character = 26;
	else if (param_str == "All") FSM_character = 255;
}

void FSM::set_frame(const string& param_str)
{
	try
	{
		int frame = stoi(param_str);
		if (frame > 0 && frame < 256)
			FSM_frame = frame;
	}
	catch (invalid_argument& ia)
	{
		FSM_frame = 0;
	}
}

void FSM::set_subaction(const string& param_str)
{
	
}

string FSM::to_str()
{
	return to_string(FSM_subaction);
}