// SSBM FSM Creator
// Character.cpp
// Justyn Durnford
// Created on 2020-07-29
// Last updated on 2021-01-03
// Source file for the Character struct.

#include "Character.h"

Character::Character(uint8_t new_id, const string& new_name)
	: id(new_id), name(new_name) {}

bool operator == (const Character& A, const Character& B)
{
	return A.id == B.id;
}

bool operator != (const Character& A, const Character& B)
{
	return A.id != B.id;
}