// RPGGame
// Terrain.cpp
// Justyn Durnford
// Created on 2020-09-24
// Last updated on 2020-09-24

#include "Terrain.h"

#include <array>
using std::array;

#include <string>
using std::string;

Terrain::Terrain(unsigned char id, const char* beginStr, const char* endStr)
{
	_id = id;
	_beginStr = beginStr;
	_endStr = endStr;
}

unsigned char Terrain::id() const
{
	return _id;
}

string Terrain::beginStr() const
{
	return _beginStr;
}

string Terrain::endStr() const
{
	return _endStr;
}