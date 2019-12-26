//SSBM FSM Creator
//FSM.cpp
//Justyn P. Durnford
//Created on 12/18/2019
//Last Updated on 12/24/2019

#include "FSM.hpp"

#include <string>
using std::string;
using std::to_string;
using std::stoi;
using std::stof;

#include <sstream>
using std::ostringstream;

#include <algorithm>
using std::find;
using std::distance;
using std::transform;

#include <cctype>
using std::toupper;

#include <stdexcept>
using std::invalid_argument;

#include <iostream>
using std::hex;

FSM::FSM() { /*Default values*/ }

FSM::FSM(int& param_int1, int& param_int2,
		 int& param_int3, float& param_float,
		 string& param_str)
{
	FSM_character = param_int1;
	FSM_frame = param_int2;
	FSM_subaction = param_int3;
	FSM_multiplier = param_float;
	FSM_str = param_str;
}

void FSM::set_character(const string& param_str)
{
	for (unsigned short int i = 0; i < characters.size(); ++i)
	{
		if (characters[i] == param_str)
		{
			FSM_character = i;
			FSM_str += param_str + ", ";
		}
	}
	/*Default character is 0*/
}

void FSM::set_frame(const string& param_str)
{
	try
	{
		int frame = stoi(param_str);
		if (frame > 0 && frame < 256)
		{
			FSM_frame = frame;
			FSM_str += "Frame " + frame;
		}
	}
	catch (invalid_argument& ia) {/*Default frame is 0*/}
}

void FSM::set_subaction(const string& param_str)
{
	auto iter = find(subaction_names.begin(), subaction_names.end(), param_str);
	if (iter != subaction_names.end())
	{
		auto i = distance(subaction_names.begin(), iter);
		FSM_subaction = subaction_ids[i];
		FSM_str += subaction_ids[i] + ", ";
	}
	/*Default subaction is 0*/
}

void FSM::set_multiplier(const string& param_str)
{
	try
	{
		FSM_multiplier = stof(param_str);
		FSM_str += "x" + param_str + ", ";
	}
	catch (invalid_argument & ia) {/*Default multiplier is 0.0f*/}
}

void FSM::clear()
{
	FSM_character = 0;
	FSM_frame = 0;
	FSM_subaction = 0;
	FSM_multiplier = 0.0f;
	FSM_str = "";
}

string FSM::to_hex() const
{
	string hex_str = "";
	ostringstream hex_str_stream;

	if (FSM_character < 16)
		hex_str_stream << "0";
	hex_str_stream << hex << FSM_character;

	if (FSM_frame < 16)
		hex_str_stream << "0";
	hex_str_stream << hex << FSM_frame;

	hex_str_stream << 8;
	if (FSM_subaction < 256)
		hex_str_stream << "0";
	if (FSM_subaction < 16)
		hex_str_stream << "0";
	hex_str_stream << hex << FSM_subaction;

	hex_str_stream << " ";

	int* pMult = (int*)&FSM_multiplier;
	hex_str_stream << hex << *pMult;

	hex_str = hex_str_stream.str();
	transform(hex_str.begin(), hex_str.end(), hex_str.begin(), ::toupper);
	return hex_str;
}

string FSM::to_str() const
{
	return FSM_str;
}