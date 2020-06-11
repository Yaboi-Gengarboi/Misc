// Misc.cpp
// Justyn Durnford
// Created on 6/11/2020
// Last updated on 6/11/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#include "Misc.hpp"

#include <string>
using std::string;

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