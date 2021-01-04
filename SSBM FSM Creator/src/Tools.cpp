// SSBM FSM Creator
// Tools.cpp
// Justyn Durnford
// Created on 2020-07-29
// Last updated on 2021-01-04
// Source file for Tools.h

#include "Tools.h"

string to_hex(uint32_t i)
{
	string hexstr = "";
	uint8_t rem = 0;

	if (i == 0)
		return "0";

	while (i != 0)
	{
		rem = i % 16;

		switch (rem)
		{
			case 10:
				hexstr.insert(0, 1, 'A');
				break;

			case 11:
				hexstr.insert(0, 1, 'B');
				break;

			case 12:
				hexstr.insert(0, 1, 'C');
				break;

			case 13:
				hexstr.insert(0, 1, 'D');
				break;

			case 14:
				hexstr.insert(0, 1, 'E');
				break;

			case 15:
				hexstr.insert(0, 1, 'F');
				break;

			default:
				hexstr.insert(0, 1, rem + 48);
				break;
		}

		i /= 16;
	}

	return hexstr;
}

string to_hex(uint16_t i)
{
	return to_hex(uint32_t(i));
}

string to_hex(uint8_t i)
{
	return to_hex(uint32_t(i));
}

string to_hex(float f)
{
	uint32_t* pf = (uint32_t*)&f;
	return to_hex(*pf);
}

string range_substr(const string& str, size_t pos_begin, size_t pos_end)
{
	return str.substr(pos_begin, pos_end - pos_begin);
}