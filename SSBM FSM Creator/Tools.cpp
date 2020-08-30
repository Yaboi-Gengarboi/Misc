// SSBM FSM Creator
// Tools.cpp
// Justyn Durnford
// Created on 7/29/2020
// Last updated on 8/20/2020

#include "Tools.h"

#include <string>
using std::string;
using std::stoi;

unsigned long long pow(int i, int p)
{
	unsigned long long result = 1;

	if (p >= 0)
	{
		for (int q = 0; q < p; ++q)
			result *= i;
	}

	return result;
}

string to_hex(int i)
{
	string hexstr = "";
	unsigned char rem = 0;

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

string to_hex(float f)
{
	int* pf = (int*)&f;
	return to_hex(*pf);
}

string range_substr(const string& str, unsigned long long pos_begin, unsigned long long pos_end)
{
	string new_str;

	new_str = str.substr(pos_begin, pos_end - pos_begin);

	return new_str;
}