// SSBM FSM Creator
// main.cpp
// Justyn Durnford
// Created on 5/4/2020
// Last updated on 5/31/2020

#include "FSM.hpp"

#include <string>
using std::string;
using std::to_string;

#include <sstream>
using std::ostringstream;

#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::hex;

string to_hex(unsigned long long i)
{
	ostringstream hex_str_stream;
	hex_str_stream << "0x";
	if (i < 256)
		hex_str_stream << '0';
	hex_str_stream << hex << i;
	return hex_str_stream.str();
}

int main()
{
	string str = "";

	for (unsigned int i = 0; i < common_subaction_list.size(); ++i)
	{
		cout << to_hex(common_subaction_list[i]._id) << ' ';
		cout << common_subaction_list[i]._name << endl;
	}

	for (unsigned int i = 0; i < Ganondorf_subaction_list.size(); ++i)
	{
		cout << to_hex(Ganondorf_subaction_list[i]._id) << ' ';
		cout << Ganondorf_subaction_list[i]._name << endl;
	}

	return 0;
}