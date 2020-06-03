// SSBM FSM Creator
// main.cpp
// Justyn Durnford
// Created on 5/4/2020
// Last updated on 6/3/2020

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

#include <fstream>
using std::ofstream;

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
	

	return 0;
}