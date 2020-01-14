//Small_Int.cpp
//Justyn P. Durnford
//Created on 12/27/2019
//Last Updated on 12/27/2019

#include "Small_Int.hpp"

#include <string>

Small_Int::Small_Int()
{
	Small_Int_value = 0;
}

Small_Int::Small_Int(const char& param_char)
{
	Small_Int_value = param_char;
}