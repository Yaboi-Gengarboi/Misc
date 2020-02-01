//Print.hpp
//Justyn P. Durnford
//Created on 1/14/2020
//Last Updated on 1/21/2020
//https://github.com/Yaboi-Gengarboi/Misc/tree/master/JLib

#ifndef PRINT_HPP
#define PRINT_HPP

#include <vector>

//Prints the contents of the C-array to the iostream and end the line.
template <typename Type>
void printArr(const Type arr[]);

//Prints the contents of the std::vector to the iostream and end the line.
template <typename Type>
void printArr(const std::vector<Type>& vec);

#endif //#ifndef PRINT_HPP