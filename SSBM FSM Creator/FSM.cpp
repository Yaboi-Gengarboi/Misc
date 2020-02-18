//SSBM FSM Creator
//FSM.cpp
//Justyn P. Durnford
//Created on 12/18/2019
//Last Updated on 2/1/2020

#include "FSM.hpp"

#include <string>
using std::string;
using std::to_string;
using std::stoi;
using std::stof;

#include <sstream>
using std::ostringstream;

#include <algorithm>
using std::find;
using std::distance;
using std::transform;

#include <cctype>
using std::toupper;

#include <stdexcept>
using std::invalid_argument;

#include <iostream>
using std::hex;

#include <vector>
using std::vector;

FSM::FSM() {/* Default values */}

FSM::FSM(const character& character, short frame,
	const subaction& subaction, float multiplier)
{
	_character = character;
	_frame = frame;
	_subaction = subaction;
	_multiplier = multiplier;
}

character FSM::get_character() const
{
	return _character;
}

void FSM::set_character(const character& character)
{
	for (size_t i = 0; i < character_list.size(); ++i)
	{
		if (character_list[i] == character)
		{
			_character = character_list[i];
			break;
		}
	}
	/* Default character is { "", 0 } */
}

short FSM::get_frame() const
{
	return _frame;
}

void FSM::set_frame(short frame)
{
	if (frame >= 0 && frame < 256)
	{
		_frame = frame;
	}
}

subaction FSM::get_subaction() const
{
	return _subaction;
}

void FSM::set_subaction(const subaction& sub)
{
	vector<subaction> common_subaction_list =
	{
		{ "Spot Dodge", 0x029 },
		{ "Forward Roll", 0x02a },
		{ "Back Roll", 0x02b },
		{ "Air Dodge", 0x02c },
		{ "Jab 1", 0x02e },
		{ "Jab 2", 0x02f },
		{ "Jab 3", 0x030 },
		{ "Rapid Jab Start", 0x031 },
		{ "Rapid Jab Loop", 0x032 },
		{ "Rapid Jab End", 0x033 },
		{ "Dash Attack", 0x034 },
		{ "Side Tilt High", 0x035 },
		{ "Side Tilt Midhigh", 0x036 },
		{ "Side Tilt Middle", 0x037 },
		{ "Side Tilt Midlow", 0x038 },
		{ "Side Tilt Low", 0x039 },
		{ "Up Tilt", 0x03a },
		{ "Down Tilt", 0x03Bb },
		{ "Side Smash High", 0x03c },
		{ "Side Smash Midhigh", 0x03d },
		{ "Side Smash Middle", 0x03e },
		{ "Side Smash Midlow", 0x03f },
		{ "Side Smash Low", 0x040 },
		{ "Up Smash", 0x042 },
		{ "Down Smash", 0x043 },
		{ "Neutral Aerial", 0x044 },
		{ "Foward Aerial", 0x045 },
		{ "Back Aerial", 0x046 },
		{ "Up Aerial", 0x047 },
		{ "Down Aerial", 0x049 },
		{ "Neutral Tech", 0x0c7 },
		{ "Forward Tech", 0x0c8 },
		{ "Back Tech", 0x0c9 },
		{ "Wall Tech", 0x0ca },
		{ "Wall Jump Tech", 0x0cb },
		{ "Ceiling Tech", 0x0cc },
		{ "Ledge Getup Slow", 0x0db },
		{ "Ledge Getup Fast", 0x0dc },
		{ "Ledge Attack Slow", 0x0dd },
		{ "Ledge Attack Fast", 0x0de },
		{ "Ledge Roll Slow", 0x0df },
		{ "Ledge Roll Fast", 0x0e0 },
		{ "Ledge Jump 1 Slow", 0x0e1 },
		{ "Ledge Jump 2 Slow", 0x0e2 },
		{ "Ledge Jump 1 Fast", 0x0e3 },
		{ "Ledge Jump 2 Fast", 0x0e4 },
		{ "Left Taunt", 0x0eF },
		{ "Right Taunt", 0x0f0 },
		{ "Grab", 0x0f2 },
		{ "Dash Grab", 0x0f3 },
		{ "Forward Throw", 0x0f7 },
		{ "Back Throw", 0x0f8 },
		{ "Up Throw", 0x0f9 },
		{ "Down Throw", 0x0fa }
	};

	bool found = false;

	for (size_t i = 0; i < common_subaction_list.size(); ++i)
	{
		if (common_subaction_list[i] == sub)
		{
			_subaction = common_subaction_list[i];
			found = true;
			break;
		}
	}

	if (!found)
	{
		switch (_character.id)
		{
			case 0x0: //Captain Falcon



				for (size_t i = 0; i < Captain_Falcon_subaction_list.size(); ++i)
				{
					if (Captain_Falcon_subaction_list[i] == sub)
					{
						_subaction = Captain_Falcon_subaction_list[i];
						break;
					}
				}

			break;
		case 0x1: //Donkey Kong

			for (size_t i = 0; i < Donkey_Kong_subaction_list.size(); ++i)
			{
				if (Donkey_Kong_subaction_list[i] == sub)
				{
					_subaction = Donkey_Kong_subaction_list[i];
					break;
				}
			}

			break;
		case 0x2: //Fox

			for (size_t i = 0; i < Fox_subaction_list.size(); ++i)
			{
				if (Fox_subaction_list[i] == sub)
				{
					_subaction = Fox_subaction_list[i];
					break;
				}
			}

			break;
		case 0x3: //Game&Watch

			for (size_t i = 0; i < Game_and_Watch_subaction_list.size(); ++i)
			{
				if (Game_and_Watch_subaction_list[i] == sub)
				{
					_subaction = Game_and_Watch_subaction_list[i];
					break;
				}
			}

			break;
		case 0x4: //Kirby

			for (size_t i = 0; i < Kirby_subaction_list.size(); ++i)
			{
				if (Kirby_subaction_list[i] == sub)
				{
					_subaction = Kirby_subaction_list[i];
					break;
				}
			}

			break;
		case 0x5: //Bowser

			for (size_t i = 0; i < Bowser_subaction_list.size(); ++i)
			{
				if (Bowser_subaction_list[i] == sub)
				{
					_subaction = Bowser_subaction_list[i];
					break;
				}
			}

			break;
		case 0x6: //Link

			for (size_t i = 0; i < Link_subaction_list.size(); ++i)
			{
				if (Link_subaction_list[i] == sub)
				{
					_subaction = Link_subaction_list[i];
					break;
				}
			}

			break;
		case 0x7: //Luigi

			for (size_t i = 0; i < Luigi_subaction_list.size(); ++i)
			{
				if (Luigi_subaction_list[i] == sub)
				{
					_subaction = Luigi_subaction_list[i];
					break;
				}
			}

			break;
		case 0x8: //Mario

			for (size_t i = 0; i < Mario_subaction_list.size(); ++i)
			{
				if (Mario_subaction_list[i] == sub)
				{
					_subaction = Mario_subaction_list[i];
					break;
				}
			}

			break;
		case 0x9: //Marth

			for (size_t i = 0; i < Marth_subaction_list.size(); ++i)
			{
				if (Marth_subaction_list[i] == sub)
				{
					_subaction = Marth_subaction_list[i];
					break;
				}
			}

			break;
		case 0xA: //Mewtwo

			for (size_t i = 0; i < Mewtwo_subaction_list.size(); ++i)
			{
				if (Mewtwo_subaction_list[i] == subaction)
				{
					_subaction = Mewtwo_subaction_list[i];
					break;
				}
			}

			break;
		case 0xB: //Ness

			for (size_t i = 0; i < Ness_subaction_list.size(); ++i)
			{
				if (Ness_subaction_list[i] == subaction)
				{
					_subaction = Ness_subaction_list[i];
					break;
				}
			}

			break;
		case 0xC: //Peach

			for (size_t i = 0; i < Peach_subaction_list.size(); ++i)
			{
				if (Peach_subaction_list[i] == subaction)
				{
					_subaction = Peach_subaction_list[i];
					break;
				}
			}

			break;
		case 0xD: //Pikachu

			for (size_t i = 0; i < Pikachu_subaction_list.size(); ++i)
			{
				if (Pikachu_subaction_list[i] == subaction)
				{
					_subaction = Pikachu_subaction_list[i];
					break;
				}
			}

			break;
		case 0xE: //Ice Climbers

			for (size_t i = 0; i < Ice_Climbers_subaction_list.size(); ++i)
			{
				if (Ice_Climbers_subaction_list[i] == subaction)
				{
					_subaction = Ice_Climbers_subaction_list[i];
					break;
				}
			}

			break;
		case 0xF: //Jigglypuff

			for (size_t i = 0; i < Jigglypuff_subaction_list.size(); ++i)
			{
				if (Jigglypuff_subaction_list[i] == subaction)
				{
					_subaction = Jigglypuff_subaction_list[i];
					break;
				}
			}

			break;
		case 0x10: //Samus

			for (size_t i = 0; i < Samus_subaction_list.size(); ++i)
			{
				if (Samus_subaction_list[i] == subaction)
				{
					_subaction = Samus_subaction_list[i];
					break;
				}
			}

			break;
		case 0x11: //Yoshi

			for (size_t i = 0; i < Yoshi_subaction_list.size(); ++i)
			{
				if (Yoshi_subaction_list[i] == subaction)
				{
					_subaction = Yoshi_subaction_list[i];
					break;
				}
			}

			break;
		case 0x12: //Zelda

			for (size_t i = 0; i < Zelda_subaction_list.size(); ++i)
			{
				if (Zelda_subaction_list[i] == subaction)
				{
					_subaction = Zelda_subaction_list[i];
					break;
				}
			}

			break;
		case 0x13: //Sheik

			for (size_t i = 0; i < Sheik_subaction_list.size(); ++i)
			{
				if (Sheik_subaction_list[i] == subaction)
				{
					_subaction = Sheik_subaction_list[i];
					break;
				}
			}

			break;
		case 0x14: //Falco

			for (size_t i = 0; i < Falco_subaction_list.size(); ++i)
			{
				if (Falco_subaction_list[i] == subaction)
				{
					_subaction = Falco_subaction_list[i];
					break;
				}
			}

			break;
		case 0x15: //Young Link

			for (size_t i = 0; i < Young_Link_subaction_list.size(); ++i)
			{
				if (Young_Link_subaction_list[i] == subaction)
				{
					_subaction = Young_Link_subaction_list[i];
					break;
				}
			}

			break;
		case 0x16: //Dr. Mario

			for (size_t i = 0; i < Dr_Mario_subaction_list.size(); ++i)
			{
				if (Dr_Mario_subaction_list[i] == subaction)
				{
					_subaction = Dr_Mario_subaction_list[i];
					break;
				}
			}

			break;
		case 0x17: //Roy

			for (size_t i = 0; i < Roy_subaction_list.size(); ++i)
			{
				if (Roy_subaction_list[i] == subaction)
				{
					_subaction = Roy_subaction_list[i];
					break;
				}
			}

			break;
		case 0x18: //Pichu

			for (size_t i = 0; i < Pichu_subaction_list.size(); ++i)
			{
				if (Pichu_subaction_list[i] == subaction)
				{
					_subaction = Pichu_subaction_list[i];
					break;
				}
			}

			break;
		case 0x19: //Ganondorf

			for (size_t i = 0; i < Ganondorf_subaction_list.size(); ++i)
			{
				if (Ganondorf_subaction_list[i] == subaction)
				{
					_subaction = Ganondorf_subaction_list[i];
					break;
				}
			}

			break;
		case 0x1A: //Popo

			for (size_t i = 0; i < Ice_Climbers_subaction_list.size(); ++i)
			{
				if (Ice_Climbers_subaction_list[i] == subaction)
				{
					_subaction = Ice_Climbers_subaction_list[i];
					break;
				}
			}

			break;
		default: //wtf?
			break;
		}
	}

		/* Default subaction is { "Spot Dodge", 0x0 } */

	/*
	bool found = false;

	for (size_t i = 0; i < common_subaction_list.size(); ++i)
	{
		if (common_subaction_list[i] == subaction)
		{
			_subaction = common_subaction_list[i];
			found = true;
			break;
		}
	}

	if (!found)
	{
		switch (_character.id)
		{
			case 0x0: //Captain Falcon

				for (size_t i = 0; i < Captain_Falcon_subaction_list.size(); ++i)
				{
					if (Captain_Falcon_subaction_list[i] == subaction)
					{
						_subaction = Captain_Falcon_subaction_list[i];
						break;
					}
				}

				break;
			case 0x1: //Donkey Kong

				for (size_t i = 0; i < Donkey_Kong_subaction_list.size(); ++i)
				{
					if (Donkey_Kong_subaction_list[i] == subaction)
					{
						_subaction = Donkey_Kong_subaction_list[i];
						break;
					}
				}

				break;
			case 0x2: //Fox

				for (size_t i = 0; i < Fox_subaction_list.size(); ++i)
				{
					if (Fox_subaction_list[i] == subaction)
					{
						_subaction = Fox_subaction_list[i];
						break;
					}
				}

				break;
			case 0x3: //Game&Watch

				for (size_t i = 0; i < Game_and_Watch_subaction_list.size(); ++i)
				{
					if (Game_and_Watch_subaction_list[i] == subaction)
					{
						_subaction = Game_and_Watch_subaction_list[i];
						break;
					}
				}

				break;
			case 0x4: //Kirby

				for (size_t i = 0; i < Kirby_subaction_list.size(); ++i)
				{
					if (Kirby_subaction_list[i] == subaction)
					{
						_subaction = Kirby_subaction_list[i];
						break;
					}
				}

				break;
			case 0x5: //Bowser

				for (size_t i = 0; i < Bowser_subaction_list.size(); ++i)
				{
					if (Bowser_subaction_list[i] == subaction)
					{
						_subaction = Bowser_subaction_list[i];
						break;
					}
				}

				break;
			case 0x6: //Link

				for (size_t i = 0; i < Link_subaction_list.size(); ++i)
				{
					if (Link_subaction_list[i] == subaction)
					{
						_subaction = Link_subaction_list[i];
						break;
					}
				}

				break;
			case 0x7: //Luigi

				for (size_t i = 0; i < Luigi_subaction_list.size(); ++i)
				{
					if (Luigi_subaction_list[i] == subaction)
					{
						_subaction = Luigi_subaction_list[i];
						break;
					}
				}

				break;
			case 0x8: //Mario

				for (size_t i = 0; i < Mario_subaction_list.size(); ++i)
				{
					if (Mario_subaction_list[i] == subaction)
					{
						_subaction = Mario_subaction_list[i];
						break;
					}
				}

				break;
			case 0x9: //Marth

				for (size_t i = 0; i < Marth_subaction_list.size(); ++i)
				{
					if (Marth_subaction_list[i] == subaction)
					{
						_subaction = Marth_subaction_list[i];
						break;
					}
				}

				break;
			case 0xA: //Mewtwo

				for (size_t i = 0; i < Mewtwo_subaction_list.size(); ++i)
				{
					if (Mewtwo_subaction_list[i] == subaction)
					{
						_subaction = Mewtwo_subaction_list[i];
						break;
					}
				}

				break;
			case 0xB: //Ness

				for (size_t i = 0; i < Ness_subaction_list.size(); ++i)
				{
					if (Ness_subaction_list[i] == subaction)
					{
						_subaction = Ness_subaction_list[i];
						break;
					}
				}

				break;
			case 0xC: //Peach

				for (size_t i = 0; i < Peach_subaction_list.size(); ++i)
				{
					if (Peach_subaction_list[i] == subaction)
					{
						_subaction = Peach_subaction_list[i];
						break;
					}
				}

				break;
			case 0xD: //Pikachu

				for (size_t i = 0; i < Pikachu_subaction_list.size(); ++i)
				{
					if (Pikachu_subaction_list[i] == subaction)
					{
						_subaction = Pikachu_subaction_list[i];
						break;
					}
				}

				break;
			case 0xE: //Ice Climbers

				for (size_t i = 0; i < Ice_Climbers_subaction_list.size(); ++i)
				{
					if (Ice_Climbers_subaction_list[i] == subaction)
					{
						_subaction = Ice_Climbers_subaction_list[i];
						break;
					}
				}

				break;
			case 0xF: //Jigglypuff

				for (size_t i = 0; i < Jigglypuff_subaction_list.size(); ++i)
				{
					if (Jigglypuff_subaction_list[i] == subaction)
					{
						_subaction = Jigglypuff_subaction_list[i];
						break;
					}
				}

				break;
			case 0x10: //Samus

				for (size_t i = 0; i < Samus_subaction_list.size(); ++i)
				{
					if (Samus_subaction_list[i] == subaction)
					{
						_subaction = Samus_subaction_list[i];
						break;
					}
				}

				break;
			case 0x11: //Yoshi

				for (size_t i = 0; i < Yoshi_subaction_list.size(); ++i)
				{
					if (Yoshi_subaction_list[i] == subaction)
					{
						_subaction = Yoshi_subaction_list[i];
						break;
					}
				}

				break;
			case 0x12: //Zelda

				for (size_t i = 0; i < Zelda_subaction_list.size(); ++i)
				{
					if (Zelda_subaction_list[i] == subaction)
					{
						_subaction = Zelda_subaction_list[i];
						break;
					}
				}

				break;
			case 0x13: //Sheik

				for (size_t i = 0; i < Sheik_subaction_list.size(); ++i)
				{
					if (Sheik_subaction_list[i] == subaction)
					{
						_subaction = Sheik_subaction_list[i];
						break;
					}
				}

				break;
			case 0x14: //Falco

				for (size_t i = 0; i < Falco_subaction_list.size(); ++i)
				{
					if (Falco_subaction_list[i] == subaction)
					{
						_subaction = Falco_subaction_list[i];
						break;
					}
				}

				break;
			case 0x15: //Young Link

				for (size_t i = 0; i < Young_Link_subaction_list.size(); ++i)
				{
					if (Young_Link_subaction_list[i] == subaction)
					{
						_subaction = Young_Link_subaction_list[i];
						break;
					}
				}

				break;
			case 0x16: //Dr. Mario

				for (size_t i = 0; i < Dr_Mario_subaction_list.size(); ++i)
				{
					if (Dr_Mario_subaction_list[i] == subaction)
					{
						_subaction = Dr_Mario_subaction_list[i];
						break;
					}
				}

				break;
			case 0x17: //Roy

				for (size_t i = 0; i < Roy_subaction_list.size(); ++i)
				{
					if (Roy_subaction_list[i] == subaction)
					{
						_subaction = Roy_subaction_list[i];
						break;
					}
				}

				break;
			case 0x18: //Pichu

				for (size_t i = 0; i < Pichu_subaction_list.size(); ++i)
				{
					if (Pichu_subaction_list[i] == subaction)
					{
						_subaction = Pichu_subaction_list[i];
						break;
					}
				}

				break;
			case 0x19: //Ganondorf

				for (size_t i = 0; i < Ganondorf_subaction_list.size(); ++i)
				{
					if (Ganondorf_subaction_list[i] == subaction)
					{
						_subaction = Ganondorf_subaction_list[i];
						break;
					}
				}

				break;
			case 0x1A: //Popo

				for (size_t i = 0; i < Ice_Climbers_subaction_list.size(); ++i)
				{
					if (Ice_Climbers_subaction_list[i] == subaction)
					{
						_subaction = Ice_Climbers_subaction_list[i];
						break;
					}
				}

				break;
			default: //wtf?
				break;
		}
	}
	*/
	
	/* Default subaction is { "Spot Dodge", 0x0 } */
}

float FSM::get_multiplier() const
{
	return _multiplier;
}

void FSM::set_multiplier(float multiplier)
{
	if (multiplier > 0)
		_multiplier = multiplier;
}

void FSM::clear()
{
	_character = { "Captain Falcon", 0x0 };
	_frame = 0;
	_subaction = { "Spot Dodge", 0x0 };
	_multiplier = 0.0f;
}

string FSM::to_str() const
{
	string str = "";

	str += _character.name + ", ";
	str += _subaction.name + ", ";
	str += "x" + to_string(_multiplier);
	str += " @ frame " + to_string(_frame);

	return str;
}

string FSM::to_hex() const
{
	string hex_str = "";
	ostringstream hex_str_stream;

	if (_character.id < 16)
		hex_str_stream << "0";
	hex_str_stream << hex << _character.id;

	if (_frame < 16)
		hex_str_stream << "0";
	hex_str_stream << hex << _frame;

	hex_str_stream << 8;
	if (_subaction.id < 256)
		hex_str_stream << "0";
	if (_subaction.id < 16)
		hex_str_stream << "0";
	hex_str_stream << hex << _subaction.id;

	hex_str_stream << " ";

	int* pMult = (int*)&_multiplier;
	hex_str_stream << hex << *pMult;

	hex_str = hex_str_stream.str();
	transform(hex_str.begin(), hex_str.end(), hex_str.begin(), ::toupper);

	return hex_str;
}

//
bool compare_character(const character& ch1, const character& ch2)
{
	return ((ch1.name == ch2.name) && (ch1.id == ch2.id));
}
bool operator == (const character& ch1, const character& ch2)
{
	return ((ch1.name == ch2.name) && (ch1.id == ch2.id));
}
bool operator != (const character& ch1, const character& ch2)
{
	return ((ch1.name != ch2.name) || (ch1.id != ch2.id));
}

//
bool compare_subaction(const subaction& sub1, const subaction& sub2)
{
	return ((sub1.name == sub2.name) && (sub1.id == sub2.id));
}
bool operator == (const subaction& sub1, const subaction& sub2)
{
	return ((sub1.name == sub2.name) && (sub1.id == sub2.id));
}
bool operator != (const subaction& sub1, const subaction& sub2)
{
	return ((sub1.name != sub2.name) || (sub1.id != sub2.id));
}

//
bool compare_FSM(const FSM& fsm1, const FSM& fsm2)
{
	return ((fsm1.get_character() == fsm2.get_character()) &&
		(fsm1.get_frame() == fsm2.get_frame()) &&
		(fsm1.get_subaction() == fsm2.get_subaction()) &&
		(fsm1.get_multiplier() == fsm2.get_multiplier()));
}
bool operator == (const FSM& fsm1, const FSM& fsm2)
{
	return ((fsm1.get_character() == fsm2.get_character()) &&
		(fsm1.get_frame() == fsm2.get_frame()) &&
		(fsm1.get_subaction() == fsm2.get_subaction()) &&
		(fsm1.get_multiplier() == fsm2.get_multiplier()));
}
bool operator != (const FSM& fsm1, const FSM& fsm2)
{
	return ((fsm1.get_character() != fsm2.get_character()) ||
		(fsm1.get_frame() != fsm2.get_frame()) ||
		(fsm1.get_subaction() != fsm2.get_subaction()) ||
		(fsm1.get_multiplier() != fsm2.get_multiplier()));
}