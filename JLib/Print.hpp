//Print.hpp
//Justyn P. Durnford
//Created on 1/14/2020
//Last Updated on 1/21/2020
//https://github.com/Yaboi-Gengarboi/Misc/tree/master/JLib

#ifndef PRINT_HPP
#define PRINT_HPP

#include <string>
#include <vector>

//Prints the C-string to the iostream and end the line.
void printCstr(const char* cstr);

//Prints the string to the iostream and end the line.
void printStr(const std::string& str);

//Prints the int to the iostream and end the line.
void printInt(const int& num_int);

//Prints the double to the iostream and end the line.
void printDoub(const double& num_double);

//Prints the character to the iostream and end the line.
void printChar(const char& ch);

//Prints the contents of the C-array to the iostream and end the line.
template <typename Type>
void printArr(const Type arr[]);

//Prints the contents of the std::vector to the iostream and end the line.
template <typename Type>
void printArr(const std::vector<Type>& vec);

#endif //#ifndef PRINT_HPP