// SSBM FSM Creator
// Tools.cpp
// Justyn Durnford
// Created on 7/29/2020
// Last updated on 7/30/2020

#include "Tools.h"

#include <string>
using std::string;

string reverse_str(const string& str)
{
	string newstr = "";

	for (unsigned long long i = str.size(); i > 0; --i)
		newstr += str[i - 1];

	return newstr;
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
				hexstr += 'a';
				break;

			case 11:
				hexstr += 'b';
				break;

			case 12:
				hexstr += 'c';
				break;

			case 13:
				hexstr += 'd';
				break;

			case 14:
				hexstr += 'e';
				break;

			case 15:
				hexstr += 'f';
				break;

			default:
				hexstr += rem + 48;
				break;
		}

		i /= 16;
	}

	return reverse_str(hexstr);
}

string to_hex(float f)
{
	int* pf = (int*)&f;
	return to_hex(*pf);
}