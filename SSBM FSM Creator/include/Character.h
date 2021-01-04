// SSBM FSM Creator
// Character.h
// Justyn Durnford
// Created on 2020-07-29
// Last updated on 2021-01-04
// Header file for the Character struct.

#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include "Subaction.h"

struct Character
{
	uint8_t id = 0;
	string name;

	map<uint16_t, Subaction> subList;

	// Default constructor.
	Character() = default;

	// Copy constructor.
	Character(const Character& other) = default;

	// Move constructor.
	Character(Character&& other) = default;

	// Primary constructor.
	// Sets id to new_id.
	// Sets name to new_name.
	Character(uint8_t new_id, const string& new_name);

	// Copy assignment operator.
	Character& operator = (const Character& other) = default;

	// Move assignment operator.
	Character& operator = (Character && other) = default;

	// Destructor.
	~Character() = default;
};

// Equality comparison operator.
// Returns true if A.id == B.id.
// Returns false otherwise.
bool operator == (const Character& A, const Character& B);

// Inequality comparison operator.
// Returns true if A.id != B.id.
// Returns false otherwise.
bool operator != (const Character& A, const Character& B);

#endif // CHARACTER_H_INCLUDED