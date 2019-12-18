//SSBM FSM Creator
//FSM.hpp
//Justyn P. Durnford
//Created on 12/17/2019
//Last Updated on 12/17/2019

#ifndef FSM_HPP
#define FSM_HPP

#include <string>

struct FSM
{
	unsigned int FSM_character;
	unsigned int FSM_frame;
	unsigned int FSM_action;
	float FSM_multiplier;
	std::string FSM_hexstr;
	std::string FSM_str;
};

#endif //#ifndef FSM_HPP