// JLib
// Jstring.hpp
// Justyn Durnford
// Created on 5/31/2020
// Last updated on 6/1/2020

#ifndef JSTRING_HPP
#define JSTRING_HPP

#include <string>

std::string j_substr(const std::string& str, unsigned long long begin, unsigned long long end);

std::string replace(const std::string& str, const std::string& find, const std::string& repl);

std::string reverse_str(const std::string& str);

std::string to_hex(unsigned long long i);

void j_erase(std::string& str, unsigned long long index);

#endif // JSTRING_HPP