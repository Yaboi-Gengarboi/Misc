// SSBM FSM Creator
// FSM.hpp
// Justyn P. Durnford
// Created on 12/17/2019
// Last updated on 6/4/2020

#ifndef FSM_HPP
#define FSM_HPP

#include <string>
#include <vector>
#include <memory>

struct Subaction
{
	std::string _name = "";
	unsigned short _id = -1;

	Subaction();
	Subaction(const std::string& name, unsigned short id);

	~Subaction();

	bool friend operator == (const Subaction& a, const Subaction& b);
	bool friend operator != (const Subaction& a, const Subaction& b);
};

struct Character
{
	std::string _name = "";
	unsigned char _id = -1;

	std::vector<Subaction> _subList;

	Character();
	Character(const std::string& name, unsigned char id);

	~Character();

	bool friend operator == (const Character& a, const Character& b);
	bool friend operator != (const Character& a, const Character& b);
};

class FSM
{
	Character _character;
	unsigned char _frame = 0;
	Subaction _subaction;
	float _multiplier = 0;

	public:

	FSM();

	FSM(const Character& character, unsigned char frame,
		const Subaction& subaction, float multiplier);

	~FSM();

	Character character() const;

	unsigned char frame() const;

	Subaction subaction() const;

	float multiplier() const;

	void setCharacter(const Character& ch);

	void setFrame(unsigned char frame);

	void setSubaction(const Subaction& sub);

	void setMultiplier(float m);

	void clear();

	std::string toString() const;

	std::string toHex() const;

	bool friend operator == (const FSM& a, const FSM& b);
	bool friend operator != (const FSM& a, const FSM& b);
};

std::string to_hex(unsigned long long i);

extern std::vector<Character> character_list;

#endif // FSM_HPP