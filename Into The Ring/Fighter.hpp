//Into The Ring
//Fighter.hpp
//Justyn P. Durnford
//Created on 12/17/2019
//Last Updated on 12/17/2019

#include <string>

#ifndef FIGHTER_HPP
#define FIGHTER_HPP

class Fighter
{
	std::string Fighter_name = "";
	std::string Fighter_description = "";
	int Fighter_health = 0;

	public:

		//
		std::string get_name();

		//
		std::string get_description();

		//
		int get_health();

		//
		void change_health(const int& modify);
};

#endif //#ifndef FIGHTER_HPP