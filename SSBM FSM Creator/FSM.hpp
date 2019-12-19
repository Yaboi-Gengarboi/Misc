//SSBM FSM Creator
//FSM.hpp
//Justyn P. Durnford
//Created on 12/17/2019
//Last Updated on 12/18/2019

#ifndef FSM_HPP
#define FSM_HPP

#include <string>
#include <array>

class FSM
{
	unsigned short int FSM_character;
	unsigned short int FSM_frame;
	unsigned short int FSM_subaction;
	float FSM_multiplier;
	std::string FSM_hexstr;
	std::string FSM_str;

	public:
		
		void set_character(const std::string& param_str);

		void set_frame(const std::string& param_str);

		void set_subaction(const std::string& param_str);

		void set_multiplier(const std::string& param_str);

		void update_FSM();

		std::string to_hex();

		std::string to_str();
};

#endif //#ifndef FSM_HPP