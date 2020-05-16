// SSBM FSM Creator
// FSM.cpp
// Justyn Durnford
// Created on 12/18/2019
// Last updated on 5/13/2020

#include "FSM.hpp"

// #include <string>
using std::string;
using std::to_string;
using std::stoi;
using std::stof;

// #include <vector>
using std::vector;

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

character::character() {}

character::character(const string& str, unsigned char uc)
{
	_name = str;
	_id = uc;
}

character::~character() {}

subaction::subaction() {}

subaction::subaction(const string& str, const character& ch, unsigned short us)
{
	_name = str;
	_ch = ch;
	_id = us;
}

subaction::~subaction() {}

FSM::FSM() { /* Default Constructor */ }

FSM::FSM(const character& character, unsigned char frame,
	const subaction& subaction, float multiplier)
{
	_character = character;
	_frame = frame;
	_subaction = subaction;
	_multiplier = multiplier;
}

FSM::~FSM() { /* Destructor */ }

character FSM::getCharacter() const
{
	return _character;
}

void FSM::setCharacter(const character& ch)
{
	_character = ch;
}

unsigned char FSM::getFrame() const
{
	return _frame;
}

void FSM::setFrame(unsigned char frame)
{
	_frame = frame;
}

subaction FSM::getSubaction() const
{
	return _subaction;
}

void FSM::setSubaction(const subaction& sub)
{
	if (sub._id <= 0x0fa)
	{
		_subaction = sub;
		return;
	}

	if (sub._id > 0x0fa)
	{
		switch (_character._id)
		{
			case 0x0: // Captain Falcon

				for (unsigned short i = 0; i < Captain_Falcon_subaction_list.size(); ++i)
				{
					if (sub == Captain_Falcon_subaction_list[i])
					{
						_subaction = Captain_Falcon_subaction_list[i];
						return;
					}
				}

			break;

			case 0x1: // Donkey Kong

				for (unsigned short i = 0; i < Donkey_Kong_subaction_list.size(); ++i)
				{
					if (sub == Donkey_Kong_subaction_list[i])
					{
						_subaction = Donkey_Kong_subaction_list[i];
						return;
					}
				}

			break;

			case 0x2: // Fox

				for (unsigned short i = 0; i < Fox_subaction_list.size(); ++i)
				{
					if (sub == Fox_subaction_list[i])
					{
						_subaction = Fox_subaction_list[i];
						return;
					}
				}

			break;

			case 0x3: // Game&Watch

				for (unsigned short i = 0; i < Game_and_Watch_subaction_list.size(); ++i)
				{
					if (sub == Game_and_Watch_subaction_list[i])
					{
						_subaction = Game_and_Watch_subaction_list[i];
						return;
					}
				}

			break;

			case 0x4: // Kirby

				for (unsigned short i = 0; i < Kirby_subaction_list.size(); ++i)
				{
					if (sub == Kirby_subaction_list[i])
					{
						_subaction = Kirby_subaction_list[i];
						return;
					}
				}

			break;

			case 0x5: // Bowser

				for (unsigned short i = 0; i < Bowser_subaction_list.size(); ++i)
				{
					if (sub == Bowser_subaction_list[i])
					{
						_subaction = Bowser_subaction_list[i];
						return;
					}
				}

			break;

			case 0x6: // Link

				for (unsigned short i = 0; i < Link_subaction_list.size(); ++i)
				{
					if (sub == Link_subaction_list[i])
					{
						_subaction = Link_subaction_list[i];
						return;
					}
				}

			break;

			case 0x7: // Luigi

				for (unsigned short i = 0; i < Luigi_subaction_list.size(); ++i)
				{
					if (sub == Luigi_subaction_list[i])
					{
						_subaction = Luigi_subaction_list[i];
						return;
					}
				}

			break;

			case 0x8: // Mario

				for (unsigned short i = 0; i < Mario_subaction_list.size(); ++i)
				{
					if (sub == Mario_subaction_list[i])
					{
						_subaction = Mario_subaction_list[i];
						return;
					}
				}

			break;

			case 0x9: // Marth

				for (unsigned short i = 0; i < Marth_subaction_list.size(); ++i)
				{
					if (sub == Marth_subaction_list[i])
					{
						_subaction = Marth_subaction_list[i];
						return;
					}
				}

			break;

			case 0xA: // Mewtwo

				for (unsigned short i = 0; i < Mewtwo_subaction_list.size(); ++i)
				{
					if (sub == Mewtwo_subaction_list[i])
					{
						_subaction = Mewtwo_subaction_list[i];
						return;
					}
				}

			break;

			case 0xB: // Ness

				for (unsigned short i = 0; i < Ness_subaction_list.size(); ++i)
				{
					if (sub == Ness_subaction_list[i])
					{
						_subaction = Ness_subaction_list[i];
						return;
					}
				}

			break;

			case 0xC: // Peach

				for (unsigned short i = 0; i < Peach_subaction_list.size(); ++i)
				{
					if (sub == Peach_subaction_list[i])
					{
						_subaction = Peach_subaction_list[i];
						return;
					}
				}

			break;

			case 0xD: // Pikachu

				for (unsigned short i = 0; i < Pikachu_subaction_list.size(); ++i)
				{
					if (sub == Pikachu_subaction_list[i])
					{
						_subaction = Pikachu_subaction_list[i];
						return;
					}
				}

			break;

			case 0xE: // Ice Climbers

				for (unsigned short i = 0; i < Ice_Climbers_subaction_list.size(); ++i)
				{
					if (sub == Ice_Climbers_subaction_list[i])
					{
						_subaction = Ice_Climbers_subaction_list[i];
						return;
					}
				}

			break;

			case 0xF: // Jigglypuff

				for (unsigned short i = 0; i < Jigglypuff_subaction_list.size(); ++i)
				{
					if (sub == Jigglypuff_subaction_list[i])
					{
						_subaction = Jigglypuff_subaction_list[i];
						return;
					}
				}

			break;

			case 0x10: // Samus

				for (unsigned short i = 0; i < Samus_subaction_list.size(); ++i)
				{
					if (sub == Samus_subaction_list[i])
					{
						_subaction = Samus_subaction_list[i];
						return;
					}
				}

			break;

			case 0x11: // Yoshi

				for (unsigned short i = 0; i < Yoshi_subaction_list.size(); ++i)
				{
					if (sub == Yoshi_subaction_list[i])
					{
						_subaction = Yoshi_subaction_list[i];
						return;
					}
				}

			break;

			case 0x12: // Zelda

				for (unsigned short i = 0; i < Zelda_subaction_list.size(); ++i)
				{
					if (sub == Zelda_subaction_list[i])
					{
						_subaction = Zelda_subaction_list[i];
						return;
					}
				}

			break;

			case 0x13: // Sheik

				for (unsigned short i = 0; i < Sheik_subaction_list.size(); ++i)
				{
					if (sub == Sheik_subaction_list[i])
					{
						_subaction = Sheik_subaction_list[i];
						return;
					}
				}

			break;

			case 0x14: // Falco

				for (unsigned short i = 0; i < Falco_subaction_list.size(); ++i)
				{
					if (sub == Falco_subaction_list[i])
					{
						_subaction = Falco_subaction_list[i];
						return;
					}
				}

			break;

			case 0x15: // Young Link

				for (unsigned short i = 0; i < Young_Link_subaction_list.size(); ++i)
				{
					if (sub == Young_Link_subaction_list[i])
					{
						_subaction = Young_Link_subaction_list[i];
						return;
					}
				}

			break;

			case 0x16: // Dr. Mario

				for (unsigned short i = 0; i < Dr_Mario_subaction_list.size(); ++i)
				{
					if (sub == Dr_Mario_subaction_list[i])
					{
						_subaction = Dr_Mario_subaction_list[i];
						return;
					}
				}

			break;

			case 0x17: // Roy

				for (unsigned short i = 0; i < Roy_subaction_list.size(); ++i)
				{
					if (sub == Roy_subaction_list[i])
					{
						_subaction = Roy_subaction_list[i];
						return;
					}
				}

			break;

			case 0x18: // Pichu

				for (unsigned short i = 0; i < Pichu_subaction_list.size(); ++i)
				{
					if (sub == Pichu_subaction_list[i])
					{
						_subaction = Pichu_subaction_list[i];
						return;
					}
				}

			break;

			case 0x19: // Ganondorf

				for (unsigned short i = 0; i < Ganondorf_subaction_list.size(); ++i)
				{
					if (sub == Ganondorf_subaction_list[i])
					{
						_subaction = Ganondorf_subaction_list[i];
						return;
					}
				}

			break;

			case 0x1A: // Popo

				for (unsigned short i = 0; i < Ice_Climbers_subaction_list.size(); ++i)
				{
					if (sub == Ice_Climbers_subaction_list[i])
					{
						_subaction = Ice_Climbers_subaction_list[i];
						return;
					}
				}

			break;

			default: // wtf?
			return;
			break;
		}
	}
}

float FSM::getMultiplier() const
{
	return _multiplier;
}

void FSM::setMultiplier(float multiplier)
{
	_multiplier = multiplier;
}

void FSM::clear()
{
	_character = { "Captain Falcon", 0x0 };
	_frame = 0;
	_subaction = { "Spot Dodge", 0x0 };
	_multiplier = 0.0f;
}

string FSM::toString() const
{
	string str = "";

	str += _character.name + ", ";
	str += _subaction.name + ", ";
	str += "x" + to_string(_multiplier);
	str += " @ frame " + to_string(_frame);

	return str;
}

string FSM::toHex() const
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

FSM FSM::operator = (FSM fsm)
{
	return fsm;
}

bool operator == (const character& ch1, const character& ch2)
{
	return !( ch1 != ch2 );
}

bool operator != (const character& ch1, const character& ch2)
{
	return ch1.id != ch2.id;
}

bool operator == (const subaction& sub1, const subaction& sub2)
{
	return !( sub1 != sub2 );
}

bool operator != (const subaction& sub1, const subaction& sub2)
{
	return sub1.id != sub2.id;
}

bool operator == (const FSM& fsm1, const FSM& fsm2)
{
	return !( fsm1 != fsm2 );
}

bool operator != (const FSM& fsm1, const FSM& fsm2)
{
	return ((fsm1.getCharacter() != fsm2.getCharacter()) ||
		(fsm1.getFrame() != fsm2.getFrame()) ||
		(fsm1.getSubaction() != fsm2.getSubaction()) ||
		(fsm1.getMultiplier() != fsm2.getMultiplier()));
}