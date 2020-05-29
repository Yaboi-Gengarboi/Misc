// SSBM FSM Creator
// FSM.cpp
// Justyn Durnford
// Created on 12/18/2019
// Last updated on 5/28/2020

#include "FSM.hpp"

#include <string>
using std::string;
using std::to_string;
using std::stoi;
using std::stof;

#include <vector>
using std::vector;

#include <sstream>
using std::ostringstream;

#include <cctype>
using std::toupper;

#include <stdexcept>
using std::invalid_argument;

#include <iostream>
using std::hex;

//////////////////////////////////////////////////////////////////////
//                             SUBACTION                            //
//////////////////////////////////////////////////////////////////////

Subaction::Subaction() {}

Subaction::Subaction(const string& name, unsigned short id)
{
	_name = name;
	_id = id;
}

Subaction::~Subaction() {}

bool operator == (const Subaction& a, const Subaction& b)
{
	if (a._id != b._id)
		return false;

	if (a._name != b._name)
		return false;

	return true;
}

bool operator != (const Subaction& a, const Subaction& b)
{
	if (a._id != b._id)
		return true;

	if (a._name != b._name)
		return true;

	return false;
}

//////////////////////////////////////////////////////////////////////
//                             CHARACTER                            //
//////////////////////////////////////////////////////////////////////

Character::Character() {}

Character::Character(const string& name, unsigned char id)
{
	_name = name;
	_id = id;
}

Character::~Character() {}

bool operator == (const Character& a, const Character& b)
{
	if (a._id != b._id)
		return false;

	if (a._name != b._name)
		return false;

	return true;
}

bool operator != (const Character& a, const Character& b)
{
	if (a._id != b._id)
		return true;

	if (a._name != b._name)
		return true;

	return false;
}

//////////////////////////////////////////////////////////////////////
//                                FSM                               //
//////////////////////////////////////////////////////////////////////

FSM::FSM() { /* Default Constructor */ }

FSM::FSM(const Character& character, unsigned char frame,
	const Subaction& subaction, float multiplier)
{
	_character = character;
	_frame = frame;
	_subaction = subaction;
	_multiplier = multiplier;
}

FSM::~FSM() { /* Destructor */ }

Character FSM::character() const
{
	return _character;
}

unsigned char FSM::frame() const
{
	return _frame;
}

Subaction FSM::subaction() const
{
	return _subaction;
}

float FSM::multiplier() const
{
	return _multiplier;
}

void FSM::setCharacter(const Character& ch)
{
	_character = ch;
}

void FSM::setFrame(unsigned char frame)
{
	_frame = frame;
}

void FSM::setMultiplier(float multiplier)
{
	_multiplier = multiplier;
}

void FSM::clear()
{
	_character = { "", 0x0 };
	_frame = 0;
	_subaction = { "", 0x0 };
	_multiplier = 0.0f;
}

string FSM::toString() const
{
	string str = "";

	str += _character._name + ", ";
	str += _subaction._name + ", ";
	str += "x" + to_string(_multiplier);
	str += " @ frame " + to_string(_frame);

	return str;
}

string FSM::toHex() const
{
	string hex_str = "";
	ostringstream hex_str_stream;

	if (_character._id < 16)
		hex_str_stream << "0";
	hex_str_stream << hex << _character._id;

	if (_frame < 16)
		hex_str_stream << "0";
	hex_str_stream << hex << _frame;

	hex_str_stream << 8;
	if (_subaction._id < 256)
		hex_str_stream << "0";
	if (_subaction._id < 16)
		hex_str_stream << "0";
	hex_str_stream << hex << _subaction._id;

	hex_str_stream << " ";

	int* pMult = (int*)&_multiplier;
	hex_str_stream << hex << *pMult;

	hex_str = hex_str_stream.str();

	return hex_str;
}

bool operator == (const FSM& a, const FSM& b)
{
	if (a._character != b._character)
		return false;

	if (a._subaction != b._subaction)
		return false;

	return true;
}

bool operator != (const FSM& a, const FSM& b)
{
	if (a._character != b._character)
		return true;

	if (a._subaction != b._subaction)
		return true;

	return false;
}

vector<Character> character_list =
{
	{ "Captain Falcon", 0x0 }, { "Donkey Kong", 0x1 }, { "Fox", 0x2 },
	{ "Game&Watch", 0x3 }, { "Kirby", 0x4 }, { "Bowser", 0x5 },
	{ "Link", 0x6 }, { "Luigi", 0x7 }, { "Mario", 0x8 },
	{ "Marth", 0x9 }, { "Mewtwo", 0xa }, { "Ness", 0xb },
	{ "Peach", 0xc }, { "Pikachu", 0xd }, { "Ice Climbers", 0xe },
	{ "Jigglypuff", 0xf }, { "Samus", 0x10 }, { "Yoshi", 0x11 },
	{ "Zelda", 0x12 }, { "Sheik", 0x13 }, { "Falco", 0x14 },
	{ "Young Link", 0x15 }, { "Dr. Mario", 0x16 }, { "Roy", 0x17 },
	{ "Pichu", 0x18 }, { "Ganondorf", 0x19 }, { "Popo", 0x1a }
};