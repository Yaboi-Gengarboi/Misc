// SSBM FSM Creator
// FSM.cpp
// Justyn Durnford
// Created on 12/18/2019
// Last updated on 8/2/2020

#include "FSM.h"
#include "Subaction.h"
#include "Character.h"
#include "Data.h"
#include "Tools.h"

#include <string>
using std::string;
using std::to_string;

#include <vector>
using std::vector;

FSM::FSM() { /* See FSM.h for default values. */ }

FSM::FSM(const Character& character, unsigned char frame,
	const Subaction& subaction, float multiplier)
{
	_character = character;
	_frame = frame;
	_subaction = subaction;
	_multiplier = multiplier;
}

FSM::~FSM() { /* Destructor */ }

const Character& FSM::character() const
{
	return _character;
}

unsigned char FSM::frame() const
{
	return _frame;
}

const Subaction& FSM::subaction() const
{
	return _subaction;
}

float FSM::multiplier() const
{
	return _multiplier;
}

void FSM::setCharacter(const Character& character)
{
	_character = character;
}

void FSM::setFrame(unsigned char frame)
{
	_frame = frame;
}

void FSM::setSubaction(const Subaction& subaction)
{
	_subaction = subaction;
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

	str += _character.name() + ", ";
	str += _subaction.name() + ", ";
	str += "x" + to_string(_multiplier) + ", @ ";
	str += to_string(_frame);

	return str;
}

string FSM::toHex() const
{
	string hex_str = "";

	if (_character.id() < 0x10)
		hex_str += '0';
	hex_str += to_hex(_character.id());

	if (_frame < 0x10)
		hex_str += '0';
	hex_str += to_hex(_frame);

	hex_str += '8';

	if (_subaction.id() < 0x10)
		hex_str += '0';
	if (_subaction.id() < 0x100)
		hex_str += '0';
	hex_str += to_hex(_subaction.id());

	hex_str += ' ';

	hex_str += to_hex(_multiplier);

	return hex_str;
}

bool operator == (const FSM& a, const FSM& b)
{
	if (a._character != b._character)
		return false;

	if (a._frame != b._frame)
		return false;

	if (a._subaction != b._subaction)
		return false;

	return true;
}

bool operator != (const FSM& a, const FSM& b)
{
	if (a._character != b._character)
		return true;

	if (a._frame != b._frame)
		return true;

	if (a._subaction != b._subaction)
		return true;

	return false;
}

bool compareFSMs(const FSM& a, const FSM& b)
{
	if (a.character().id() > b.character().id())
		return true;

	if (a.subaction().id() > b.subaction().id())
		return true;

	if (a.frame() < b.frame())
		return true;

	return false;
}