//Print.hpp
//Justyn P. Durnford
//Created on 1/14/2020
//Last Updated on 1/14/2020
//Found at https://github.com/Yaboi-Gengarboi/Misc/tree/master/JLib

#ifndef PRINT_HPP
#define PRINT_HPP

#include <string>

//Prints the Cstring to the iostream and end the line.
void println(const char* cstr);

//Prints the string to the iostream and end the line.
void println(const std::string& str);

//Prints the int to the iostream and end the line.
void println(const int& num_int);

//Prints the double to the iostream and end the line.
void println(const double& num_double);

//Prints the character to the iostream and end the line.
void println(const char& ch);

#endif //#ifndef PRINT_HPP