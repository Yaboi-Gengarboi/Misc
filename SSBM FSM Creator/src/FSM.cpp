// SSBM FSM Creator
// FSM.cpp
// Justyn Durnford
// Created on 2019-12-18
// Last updated on 2021-01-04
// Source file for the FSM struct.

#include "FSM.h"

FSM::FSM(const Character& new_character, uint8_t new_frame,
		 const Subaction& new_subaction, float new_multiplier)
	: character(new_character), frame(new_frame),
	  subaction(new_subaction), multiplier(new_multiplier) {}

string FSM::toString() const
{
	string str = "";

	str += character.name + ", ";
	str += subaction.name + ", ";
	str += "x" + to_string(multiplier) + ", @ ";
	str += to_string(frame);

	return str;
}

string FSM::toHex() const
{
	string hex_str = "";

	if (character.id < 0x10)
		hex_str += '0';
	hex_str += to_hex(character.id);

	if (frame < 0x10)
		hex_str += '0';
	hex_str += to_hex(frame);

	hex_str += '8';

	if (subaction.id < 0x10)
		hex_str += '0';
	if (subaction.id < 0x100)
		hex_str += '0';
	hex_str += to_hex(subaction.id);

	hex_str += ' ';

	hex_str += to_hex(multiplier);

	return hex_str;
}

strong_ordering compare(const FSM& A, const FSM& B)
{
	if (A.character.id < B.character.id)
		return strong_ordering::less;
	else if (A.character.id > B.character.id)
		return strong_ordering::greater;

	if (A.frame > B.frame)
		return strong_ordering::less;
	else if (A.frame < B.frame)
		return strong_ordering::greater;

	if (A.subaction.id < B.subaction.id)
		return strong_ordering::less;
	if (A.subaction.id > B.subaction.id)
		return strong_ordering::greater;

	return strong_ordering::equal;
}

bool operator == (const FSM& A, const FSM& B)
{
	if (A.character != B.character)
		return false;

	if (A.frame != B.frame)
		return false;

	if (A.subaction != B.subaction)
		return false;

	return true;
}

bool operator != (const FSM& A, const FSM& B)
{
	if (A.character != B.character)
		return true;

	if (A.frame != B.frame)
		return true;

	if (A.subaction != B.subaction)
		return true;

	return false;
}