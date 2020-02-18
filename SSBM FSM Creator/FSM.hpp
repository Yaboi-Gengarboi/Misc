//SSBM FSM Creator
//FSM.hpp
//Justyn P. Durnford
//Created on 12/17/2019
//Last Updated on 2/1/2020

#ifndef FSM_HPP
#define FSM_HPP

#include <string>
#include <vector>

struct character
{
	std::string name = "";
	short id = 0x0;
};

struct subaction
{
	std::string name = "";
	short id = 0x0;
};

class FSM
{
	character _character = { "Captain Falcon", 0x0 };
	short _frame = 0;
	subaction _subaction = { "Spot Dodge", 0x0 };
	float _multiplier = 0.0f;

public:

	FSM();

	FSM(const character& character, short frame,
		const subaction& subaction, float multiplier);

	character get_character() const;

	void set_character(const character& character);

	short get_frame() const;

	void set_frame(short frame);

	subaction get_subaction() const;

	void set_subaction(const subaction& subaction);

	float get_multiplier() const;

	void set_multiplier(float multiplier);

	void clear();

	std::string to_str() const;

	std::string to_hex() const;
};

//
bool compare_character(const character& ch1, const character& ch2);
bool operator == (const character& ch1, const character& ch2);
bool operator != (const character& ch1, const character& ch2);

//
bool compare_subaction(const subaction& sub1, const subaction& sub2);
bool operator == (const subaction& sub1, const subaction& sub2);
bool operator != (const subaction& sub1, const subaction& sub2);

//
bool compare_FSM(const FSM& fsm1, const FSM& fsm2);
bool operator == (const FSM& fsm1, const FSM& fsm2);
bool operator != (const FSM& fsm1, const FSM& fsm2);

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