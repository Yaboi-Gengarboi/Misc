//Flag_Byte.hpp
//Justyn P. Durnford
//Created on 1/11/2020
//Last Updated on 1/14/2020
//Found at https://github.com/Yaboi-Gengarboi/Misc/tree/master/JLib

#include "Flag_Byte.hpp"

#include <string>
using std::string;

#include <bitset>
using std::bitset;

Flag_Byte::Flag_Byte()
{
	Flag_Byte_value = 0;
}

Flag_Byte::Flag_Byte(const unsigned char& param_c)
{
	Flag_Byte_value = param_c;
}

unsigned char Flag_Byte::get_value()
{
	return Flag_Byte_value;
}

void Flag_Byte::set_value(const unsigned char& param_c)
{
	Flag_Byte_value = param_c;
}

bool Flag_Byte::get_flag(const unsigned char& bit)
{
	if (bit >= 1 && bit <= 8)
	{
		if (Flag_Byte_value & (1 << (bit - 1)))
			return true;
	}
	//else
		return false;
}

string Flag_Byte::to_str()
{
	string str = bitset<8>(Flag_Byte_value).to_string();
	return str;
}