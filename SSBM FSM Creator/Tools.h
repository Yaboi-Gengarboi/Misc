// SSBM FSM Creator
// Tools.h
// Justyn Durnford
// Created on 7/29/2020
// Last updated on 8/20/2020

#ifndef TOOLS_H
#define TOOLS_H

#include <string>

unsigned long long pow(int i, int p);

std::string to_hex(int i);

std::string to_hex(float f);

std::string range_substr(const std::string& str, unsigned long long pos_begin, unsigned long long pos_end);

#endif // TOOLS_H