// SSBM FSM Creator
// Tools.cpp
// Justyn Durnford
// Created on 7/29/2020
// Last updated on 8/2/2020

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
				hexstr += 'A';
				break;

			case 11:
				hexstr += 'B';
				break;

			case 12:
				hexstr += 'C';
				break;

			case 13:
				hexstr += 'D';
				break;

			case 14:
				hexstr += 'E';
				break;

			case 15:
				hexstr += 'F';
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

int hex_to_int(const std::string& hexstr)
{
	int result = 0;

	for (unsigned char i = 0; i < hexstr.size(); ++i)
	{
		switch (hexstr[i])
		{
			case 'A':
				result += 10 * pow(16, hexstr.size() - i - 1);
			break;

			case 'B':
				result += 11 * pow(16, hexstr.size() - i - 1);
			break;

			case 'C':
				result += 12 * pow(16, hexstr.size() - i - 1);
			break;

			case 'D':
				result += 13 * pow(16, hexstr.size() - i - 1);
			break;

			case 'E':
				result += 14 * pow(16, hexstr.size() - i - 1);
			break;

			case 'F':
				result += 15 * pow(16, hexstr.size() - i - 1);
			break;

			default:
				result += (hexstr[i] - 48) * pow(16, hexstr.size() - i - 1);
			break;
		}
	}

	return result;
}