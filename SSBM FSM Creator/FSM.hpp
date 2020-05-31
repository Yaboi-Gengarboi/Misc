// SSBM FSM Creator
// FSM.hpp
// Justyn P. Durnford
// Created on 12/17/2019
// Last updated on 5/31/2020

#ifndef FSM_HPP
#define FSM_HPP

#include <string>
#include <vector>
#include <memory>

struct Subaction
{
	std::string _name = "";
	unsigned short _id = 0x0;

	Subaction();
	Subaction(const std::string& name, unsigned short id);

	~Subaction();

	bool friend operator == (const Subaction& a, const Subaction& b);
	bool friend operator != (const Subaction& a, const Subaction& b);
};

struct Character
{
	std::string _name = "";
	unsigned char _id = 0x0;

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

extern std::vector<Character> character_list;

extern std::vector<Subaction> common_subaction_list;
extern std::vector<Subaction> Captain_Falcon_subaction_list;
extern std::vector<Subaction> Donkey_Kong_subaction_list;
extern std::vector<Subaction> Fox_subaction_list;
extern std::vector<Subaction> Game_and_Watch_subaction_list;
extern std::vector<Subaction> Ganondorf_subaction_list;

#endif // FSM_HPP