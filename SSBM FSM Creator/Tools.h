// SSBM FSM Creator
// Tools.h
// Justyn Durnford
// Created on 7/29/2020
// Last updated on 7/31/2020

#ifndef TOOLS_H
#define TOOLS_H

#include <string>

unsigned long long pow(int i, int p);

std::string reverse_str(const std::string& str);

std::string to_hex(int i);

std::string to_hex(float f);

int hex_to_int(const std::string& hexstr);

#endif // TOOLS_H