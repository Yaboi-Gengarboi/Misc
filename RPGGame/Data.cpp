// RPGGame
// Data.cpp
// Justyn Durnford
// Created on 2020-08-14
// Last updated on 2020-09-28

#include "Data.h"

#include <string>
using std::string;
using std::to_string;
using std::stol;

string long_to_hex(long i)
{
	string hexstr;
	unsigned char rem = 0;

	if (i == 0)
		return "00";

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
				hexstr.insert(0, to_string(rem));
				break;
		}

		i /= 16;
	}

	if (hexstr.size() % 2 != 0)
		hexstr = '0' + hexstr;

	return hexstr;
}

string float_to_hex(float f)
{
	long* pf = (long*)&f;
	return long_to_hex(*pf);
}

string eng_to_hex(const string& str)
{
	string hexstr;

	for (size_t i = 0; i < str.size(); ++i)
	{
		hexstr += long_to_hex(str[i]);
	}

	return hexstr + "00";
}

long hex_to_long(const string& str)
{
	return stol(str, nullptr, 16);
}

string hex_to_eng(const string& str)
{
	string engstr;
	string hexsubstr;
	std::size_t i = 0;

	do
	{
		hexsubstr = str.substr(i, 2);
		engstr += hex_to_long(hexsubstr);
		i += 2;
	}
	while (hexsubstr != "00");

	return engstr;
}