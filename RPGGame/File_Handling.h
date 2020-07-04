// RPGGame
// File_Handling.h
// Justyn Durnford
// Created on 7/3/2020
// Last updated on 7/3/2020

#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

#include "Ability.h"
#include "Move.h"
#include "Pokemon.h"

#include <string>

std::string reverse_str(const std::string& str);

std::string to_hex(unsigned long long i);

std::string to_hex(float f);

#endif // FILE_HANDLING_H