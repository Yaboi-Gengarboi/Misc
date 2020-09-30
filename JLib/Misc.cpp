// Misc.cpp
// Justyn Durnford
// Created on 2020-06-11
// Last updated on 2020-09-30

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#include "Misc.hpp"

#include <string>
using std::string;
using std::to_string;
using std::stol;

string reverse_str(const string& str)
{
	string newstr = "";

	for (unsigned long long i = str.size(); i > 0; --i)
		newstr += str[i - 1];

	return newstr;
}

string replace(const string& str, const string& find, const string& repl)
{
	string newstr = "";

	while (str.find(find) != -1)
	{

	}

	return newstr;
}

string to_hex(unsigned long long i)
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

float ft_to_m(unsigned int ft, unsigned char in)
{
	return (ft + ( in / 12.0f )) * 0.3048f;
}

float lb_to_kg(float lb)
{
	return lb * 0.453592f;
}

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