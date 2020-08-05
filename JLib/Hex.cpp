// Hex.cpp
// Justyn Durnford
// Created on 8/4/2020
// Last updated on 8/4/2020

#include "Hex.h"

#include <string>
using std::string;

Hex_Long::Hex_Long() {}

Hex_Long::Hex_Long(const long& value)
{

}

Hex_Long::Hex_Long(const string& hexstr)
{

}

Hex_Long::~Hex_Long() {}

long int Hex_Long::value() const
{
	return _value;
}

string Hex_Long::hexstr() const
{
	return _hexstr;
}

void Hex_Long::setValue(const long& value)
{

}

void Hex_Long::setValue(const string& hexstr)
{

}

string to_hex(long i)
{
	string hexstr;
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
	long* pf = (long*)&f;
	return to_hex(*pf);
}

long to_long(const string& hexstr)
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

float hex_to_float(const string& hexstr)
{
	float result = 0;

	return result;
}