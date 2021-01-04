// SSBM FSM Creator
// FSM.h
// Justyn P. Durnford
// Created on 2019-12-17
// Last updated on 2021-01-03
// Header file for the FSM struct.

#ifndef FSM_H_INCLUDED
#define FSM_H_INCLUDED

#include "Character.h"

struct FSM
{
	Character character;
	uint8_t frame;
	Subaction subaction;
	float multiplier;

	// Default constructor.
	FSM() = default;

	// Copy constructor.
	FSM(const FSM& other) = default;

	// Move constructor.
	FSM(FSM&& other) = default;

	// Primary constructor.
	FSM(const Character& new_character, uint8_t new_frame,
		const Subaction& new_subaction, float new_multiplier);

	// Copy assignment operator.
	FSM& operator = (const FSM& other) = default;

	// Move assignment operator.
	FSM& operator = (FSM&& other) = default;

	// Destructor.
	~FSM() = default;

	// Returns a std::string representation of the FSM.
	string toString() const;

	// Returns a hex std::string representation of the FSM.
	string toHex() const;
};

// Compares the 2 given FSMs.
strong_ordering compare(const FSM& A, const FSM& B);

// Returns true if:
//  - A.character == B.character AND
//  - A.frame == B.frame         AND
//  - A.subaction == B.subaction AND
bool operator == (const FSM& A, const FSM& B);

// Returns true if:
//  - A.character != B.character OR
//  - A.frame != B.frame         OR
//  - A.subaction != B.subaction OR
bool operator != (const FSM& A, const FSM& B);

#endif // FSM_H_INCLUDED