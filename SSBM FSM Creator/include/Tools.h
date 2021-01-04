// SSBM FSM Creator
// Tools.h
// Justyn Durnford
// Created on 2020-07-29
// Last updated on 2021-01-03
// Header file that defines various types and functions
// from the C++ standard library as well as some miscellaneous
// functions that do not belong to any struct or class.

#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

#include <array>
using std::array;

#include <cmath>
using std::pow;

#include <compare>
using std::strong_ordering;

#include <cstddef>
using std::size_t;

#include <cstdint>
using std::uint8_t;
using std::uint16_t;
using std::uint32_t;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iostream>
using std::cout;
using std::endl;

#include <map>
using std::map;

#include <stdexcept>
using std::invalid_argument;

#include <string>
using std::string;
using std::stoi;
using std::stof;
using std::to_string;

#include <utility>
using std::swap;

#include <vector>
using std::vector;

string to_hex(uint32_t i);

string to_hex(uint16_t i);

string to_hex(uint8_t i);

string to_hex(float f);

string range_substr(const string& str, size_t pos_begin, size_t pos_end);

#endif // TOOLS_H_INCLUDED