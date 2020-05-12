// SSBM FSM Creator
// FSM.hpp
// Justyn P. Durnford
// Created on 12/17/2019
// Last updated on 5/3/2020

#ifndef FSM_HPP
#define FSM_HPP

#include <string>
#include <vector>
#include <memory>

struct character
{
	std::string _name = "";
	unsigned char _id = 0x0;

	character();
	character(const std::string& str, unsigned char uc);

	~character() {}
};

struct subaction
{
	std::string _name = "";
	character _ch;
	unsigned short _id = 0x0;

	subaction();
	subaction(const std::string& str, const character& ch, unsigned short us);

	~subaction() {}
};

class FSM
{
	character _character = { "Captain Falcon", 0x0 };
	unsigned char _frame = 0;
	subaction _subaction = { "Spot Dodge", _character, 0x0 };
	float _multiplier = 0;

	public:

	FSM();

	FSM(const character& character, unsigned char frame,
		const subaction& subaction, float multiplier);

	~FSM();

	character getCharacter() const;

	unsigned char getFrame() const;

	subaction getSubaction() const;

	float getMultiplier() const;

	void setCharacter(const character& ch);

	void setFrame(unsigned char frame);

	void setSubaction(const subaction& sub);

	void setMultiplier(float m);

	void clear();

	std::string toString() const;

	std::string toHex() const;

	FSM operator = (FSM fsm);

	bool friend operator == (const FSM& fsm1, const FSM& fsm2);

	bool friend operator != (const FSM& fsm1, const FSM& fsm2);
};

//
bool operator == (const character& ch1, const character& ch2);
bool operator != (const character& ch1, const character& ch2);

//
bool operator == (const subaction& sub1, const subaction& sub2);
bool operator != (const subaction& sub1, const subaction& sub2);

extern character Captain_Falcon;
extern character Donkey_Kong;
extern character Fox;
extern character Game_and_Watch;
extern character Kirby;
extern character Bowser;
extern character Link;
extern character Luigi;
extern character Mario;
extern character Marth;
extern character Mewtwo;
extern character Ness;
extern character Peach;
extern character Pikachu;
extern character Ice_Climbers;
extern character Jigglypuff;
extern character Samus;
extern character Yoshi;
extern character Zelda;
extern character Sheik;
extern character Falco;
extern character Young_Link;
extern character Dr_Mario;
extern character Roy;
extern character Pichu;
extern character Ganondorf;

extern std::vector<character> character_list;
extern std::vector<subaction> common_subaction_list;
extern std::vector<subaction> Captain_Falcon_subaction_list;
extern std::vector<subaction> Donkey_Kong_subaction_list;
extern std::vector<subaction> Fox_subaction_list;
extern std::vector<subaction> Game_and_Watch_subaction_list;
extern std::vector<subaction> Kirby_subaction_list;
extern std::vector<subaction> Bowser_subaction_list;
extern std::vector<subaction> Link_subaction_list;
extern std::vector<subaction> Luigi_subaction_list;
extern std::vector<subaction> Mario_subaction_list;
extern std::vector<subaction> Marth_subaction_list;
extern std::vector<subaction> Mewtwo_subaction_list;
extern std::vector<subaction> Ness_subaction_list;
extern std::vector<subaction> Peach_subaction_list;
extern std::vector<subaction> Pikachu_subaction_list;
extern std::vector<subaction> Ice_Climbers_subaction_list;
extern std::vector<subaction> Jigglypuff_subaction_list;
extern std::vector<subaction> Samus_subaction_list;
extern std::vector<subaction> Yoshi_subaction_list;
extern std::vector<subaction> Zelda_subaction_list;
extern std::vector<subaction> Sheik_subaction_list;
extern std::vector<subaction> Falco_subaction_list;
extern std::vector<subaction> Young_Link_subaction_list;
extern std::vector<subaction> Dr_Mario_subaction_list;
extern std::vector<subaction> Roy_subaction_list;
extern std::vector<subaction> Pichu_subaction_list;
extern std::vector<subaction> Ganondorf_subaction_list;

#endif //#ifndef FSM_HPP