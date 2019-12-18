//SSBM FSM Creator
//error_handling.hpp
//Justyn P. Durnford
//Created on 12/17/2019
//Last Updated on 12/17/2019

#ifndef ERROR_HANDLING_HPP
#define ERROR_HANDLING_HPP

#include <string>

//Creates a temporary window that will display a message
//that handles an error, telling the user what to do.
//@PARAM const string& msg: Message to display.
void displayError(const std::string& msg);

#endif //#ifndef ERROR_HANDLING_HPP