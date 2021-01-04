// SSBM FSM Creator
// Subaction.h
// Justyn Durnford
// Created on 2020-07-29
// Last updated on 2021-01-04
// Header file for the Subaction struct.

#ifndef SUBACTION_H_INCLUDED
#define SUBACTION_H_INCLUDED

#include "Tools.h"

struct Subaction
{
	uint16_t id = 0;
	string name;

	// Default Constructor.
	Subaction() = default;

	// Copy constructor.
	Subaction(const Subaction& other) = default;

	// Move constructor.
	Subaction(Subaction&& other) = default;

	// Primary Constructor.
	// Sets id to new_id.
	// Sets name to new_name.
	Subaction(uint16_t new_id, const string& new_name);

	// Copy assignment operator.
	Subaction& operator = (const Subaction& other) = default;

	// Move assignment operator.
	Subaction& operator = (Subaction&& other) = default;

	// Destructor.
	~Subaction() = default;
};

// Equality comparison operator.
// Returns true if A.id == B.id
// Returns false otherwise.
bool operator == (const Subaction& A, const Subaction& B);

// Inequality comparison operator.
// Returns true if A.id != B.id
// Returns false otherwise.
bool operator != (const Subaction& A, const Subaction& B);

#endif // SUBACTION_H_INCLUDED