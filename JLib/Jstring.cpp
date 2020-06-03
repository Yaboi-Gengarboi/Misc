// JLib
// Jstring.cpp
// Justyn Durnford
// Created on 5/31/2020
// Last updated on 5/31/2020

#include "Jstring.hpp"

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
		return "0x0";

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

	return "0x" + reverse_str(hexstr);
}