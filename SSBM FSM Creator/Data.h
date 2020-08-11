// SSBM FSM Creator
// Data.h
// Justyn Durnford
// Created on 7/31/2020
// Last updated on 8/8/2020

#ifndef DATA_H
#define DATA_H

#include "FSM.h"
#include "Subaction.h"
#include "Character.h"

#include <vector>
#include <string>

extern std::vector<Character> character_list;

extern std::vector<std::vector<FSM>> fsm_list;

bool init_characters();

void add_fsm(const Character& character, unsigned char frame, const Subaction& subaction, float multiplier);

void swap_fsms(FSM& a, FSM& b);

void sort_fsm_list();

std::vector<std::string> fsm_list_strings();

bool is_fsm_file_empty();

bool read_fsms();

void write_fsms();

#endif // DATA_H