/*
FSM.hpp
Justyn P. Durnford
Created on 10/24/2019
Last updated on
Header file for FSM struct
*/

#ifndef FSM_HPP
#define FSM_HPP

#include <string>

/*

*/
struct FSM
{
	unsigned short int character;
	unsigned short int frame;
	unsigned short int action;
	float multiplier;
	std::string toHexString();
	std::string toString();
};

#endif