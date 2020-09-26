// RPGGame
// Weather.cpp
// Justyn Durnford
// Created on 2020-09-24
// Last updated on 2020-09-24

#include "Weather.h"

#include <array>
using std::array;

#include <string>
using std::string;

Weather::Weather(unsigned char id, const char* beginStr, const char* endStr)
{
	_id = id;
	_beginStr = beginStr;
	_endStr = endStr;
}

unsigned char Weather::id() const
{
	return _id;
}

string Weather::beginStr() const
{
	return _beginStr;
}

string Weather::endStr() const
{
	return _endStr;
}