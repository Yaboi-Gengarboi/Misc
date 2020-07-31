// SSBM FSM Creator
// FSM.h
// Justyn P. Durnford
// Created on 12/17/2019
// Last updated on 7/30/2020

#ifndef FSM_H
#define FSM_H

#include "Subaction.h"
#include "Character.h"

#include <string>
#include <vector>

class FSM
{
	Character _character;
	unsigned char _frame = 0;
	Subaction _subaction;
	float _multiplier = 0;

	public:

	// Default constructor.
	FSM();

	// Primary constructor.
	FSM(const Character& character, unsigned char frame,
		const Subaction& subaction, float multiplier);

	// Destructor.
	~FSM();

	// Returns character_list[_character.id()].
	const Character& character() const;

	// Returns _frame.
	unsigned char frame() const;

	// Returns _character.subList(_subaction.id()).
	const Subaction& subaction() const;

	// Returns _multiplier.
	float multiplier() const;

	// Sets _character to character.
	void setCharacter(const Character& character);

	// Sets _frame to frame.
	void setFrame(unsigned char frame);

	// Sets _subaction to subaction.
	void setSubaction(const Subaction& subaction);

	// Sets _multiplier to multiplier.
	void setMultiplier(float multiplier);

	// Reverts all values to their default values.
	void clear();

	// Returns a std::string representation of the FSM.
	std::string toString() const;

	// Returns a hex std::string representation of the FSM.
	std::string toHex() const;

	// Returns true if:
	//   a.character == b.character AND
	//   a.frame == b.frame         AND
	//   a.subaction == b.subaction AND
	bool friend operator == (const FSM& a, const FSM& b);

	// Returns true if:
	//   a.character != b.character OR
	//   a.frame != b.frame         OR
	//   a.subaction != b.subaction OR
	bool friend operator != (const FSM& a, const FSM& b);
};

extern std::vector<Character> character_list;

#endif // FSM_H