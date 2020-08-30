// File_Manager.cpp
// Justyn Durnford
// Created on 8/24/2020
// Last updated on 8/24/2020

#include "File_Manager.h"

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <stdexcept>
using std::invalid_argument;

#include <string>
using std::string;
using std::size_t;
using std::getline;

#include <vector>
using std::vector;

bool File_Manager::doesFileExist() const
{
	if (_fin)
		return true;

	return false;
}

string File_Manager::range_substr(const string& str, const size_t& begin, const size_t& end) const
{
	return str.substr(begin, end - begin);
}