// test_file.cpp
// Justyn P. Durnford
// Created on 1/18/2020
// Last updated on 5/31/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#include "Jmisc.hpp"

#include <string>
using std::string;
using std::to_string;

#include <iostream>
using std::cout;

#include <random>
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;

string randString(unsigned int size)
{
	static string alphabet = "abcdefghijkmnopqrstuvwxyz"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890~!@#$%^&*()-_=+;:,./?";
	string newstr = "";

	random_device randDev;
	default_random_engine engine(randDev());
	uniform_int_distribution<int> uniformDist(0, alphabet.size() - 1);

	for (unsigned int i = 0; i < size; ++i)
		newstr += alphabet[uniformDist(engine)];

	return newstr;
}

void println(const string& str)
{
	cout << str << '\n';
}

unsigned long long str_length(const char* str)
{
	unsigned long long i = 0;
	while (str[i] != '\0')
		++i;
	return i;
}

//vector<unsigned int> str_find_all(const char* str, const char* find)
//{
//	unsigned int strL = str_length(str);
//}

//char* str_replace(const char* str, const char* find, const char* repl)
//{
//
//}

int main(int argc, char** argv)
{
	for (unsigned long long i = 0; i <= 100; ++i)
	{
		println(to_hex(i));
	}

	return 0;
}