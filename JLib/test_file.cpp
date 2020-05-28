// test_file.cpp
// Justyn P. Durnford
// Created on 1/18/2020
// Last updated on 5/27/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#include "JVector3f.hpp"

#include <string>
using std::string;
using std::to_string;

#include <iostream>
using std::cout;

#include <vector>
using std::vector;

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

unsigned int str_length(const char* str)
{
	unsigned int i = 0;
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
	Jvector3f vec1;
	Jvector3f vec2 = vec1;

	println(vec1.toString());
	println(vec2.toString());

	return 0;
}