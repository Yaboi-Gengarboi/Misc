//tools.cpp
//Justyn Durnford
//Created on 2/5/2020
//Last Updated on 2/5/2020

#include "tools.hpp"

#include <string>
using std::string;
using std::stoi;
using std::stof;

#include <sstream>
using std::ostringstream;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::hex;

#include <algorithm>
using std::transform;

#include <stdexcept>
using std::invalid_argument;

#include <cmath>
using std::abs;

short get_short()
{
	bool proceed = false;
	string str;
	short s = 0;

	while (!proceed)
	{
		cout << "Enter a short." << endl;
		getline(cin, str);

		try
		{
			int i = abs(stoi(str));

			if (i > 32767 || i < -32767)
				throw invalid_argument("");

			s = (short)i;
			proceed = true;
		}
		catch (const invalid_argument & ia)
		{
			cout << "Invalid input. Try again." << endl;
		}
	}

	return s;
}

float get_float()
{
	bool proceed = false;
	string str;
	float f = 0.0f;

	while (!proceed)
	{
		cout << "Enter a float." << endl;
		getline(cin, str);

		try
		{
			f = abs(stof(str));
			proceed = true;
		}
		catch (const invalid_argument & ia)
		{
			cout << "Invalid input. Try again." << endl;
		}
	}

	return f;
}

string float_to_hex(float f)
{
	string hex_str = "";
	ostringstream hex_str_stream;

	int* p = (int*)&f;
	hex_str_stream << hex << *p;

	hex_str = hex_str_stream.str();
	transform(hex_str.begin(), hex_str.end(), hex_str.begin(), ::toupper);

	return hex_str;
}