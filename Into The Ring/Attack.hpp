//Into The Ring
//Attack.hpp
//Justyn P. Durnford
//Created on 12/17/2019
//Last Updated on 12/17/2019

#ifndef ATTACK_HPP
#define ATTACK_HPP

#include <string>

class Attack
{
	std::string Attack_name = "";
	std::string Attack_description = "";

	public:

		//
		std::string get_name();

		//
		std::string get_description();

		//
		void procedure(/*Fighter& self, Fighter& target*/);

};

#endif //#ifndef ATTACK_HPP