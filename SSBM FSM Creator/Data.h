// SSBM FSM Creator
// Data.h
// Justyn Durnford
// Created on 7/31/2020
// Last updated on 7/31/2020

#ifndef DATA_H
#define DATA_H

#include "Subaction.h"
#include "Character.h"

#include <vector>

void init_characters();

extern std::vector<Character> character_list;

#endif // DATA_H