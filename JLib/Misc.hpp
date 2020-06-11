// Misc.hpp
// Justyn Durnford
// Created on 6/11/2020
// Last updated on 6/11/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#ifndef MISC_HPP
#define MISC_HPP

#include <string>

std::string substring(const std::string& str, unsigned long long begin, unsigned long long end);

std::string replace(const std::string& str, const std::string& find, const std::string& repl);

std::string reverse_str(const std::string& str);

std::string to_hex(unsigned long long i);

void erase(std::string& str, unsigned long long begin, unsigned long long end);

#endif // MISC_HPP