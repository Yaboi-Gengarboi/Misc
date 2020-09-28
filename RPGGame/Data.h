// RPGGame
// Data.h
// Justyn Durnford
// Created on 2020-08-14
// Last updated on 2020-09-28

#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include <string>

std::string long_to_hex(long i);

std::string float_to_hex(float f);

std::string eng_to_hex(const std::string& str);

long hex_to_long(const std::string& str);

std::string hex_to_eng(const std::string& str);

#endif // DATA_H