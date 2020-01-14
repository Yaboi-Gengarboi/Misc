//SSBM FSM Creator
//FSM.hpp
//Justyn P. Durnford
//Created on 12/17/2019
//Last Updated on 12/25/2019

#ifndef FSM_HPP
#define FSM_HPP

#include <string>
#include <vector>
#include <utility>

extern std::vector<std::string> characters;
extern std::vector<std::pair<int, int>> character_subaction_indexes;
extern std::vector<std::string> subaction_names;
extern std::vector<unsigned short int> subaction_ids;

class FSM
{
	int FSM_character = 0;
	int FSM_frame = 0;
	int FSM_subaction = 0;
	float FSM_multiplier = 0.0f;
	std::string FSM_str = "";

	public:

		FSM();

		FSM(int& param_int1, int& param_int2, 
			int& param_int3, float& param_float,
			std::string& param_str);

		int get_character() const;
		
		void set_character(const std::string& param_str);

		int get_frame() const;

		void set_frame(const std::string& param_str);

		int get_subaction() const;

		void set_subaction(const std::string& param_str);

		float get_multiplier() const;

		void set_multiplier(const std::string& param_str);

		void clear();

		void set_string();

		std::string to_str() const;

		std::string to_hex() const;
};

#endif //#ifndef FSM_HPP