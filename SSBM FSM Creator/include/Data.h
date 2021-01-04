// SSBM FSM Creator
// Data.h
// Justyn Durnford
// Created on 2020-07-31
// Last updated on 2021-01-04

#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include "FSM.h"

extern array<Character, 27> character_list;
extern vector<vector<FSM>> fsm_list;

bool init_characters();

void sort_fsm_list();

array<vector<string>, 2> fsm_list_strings();

bool is_fsm_file_empty();

bool read_fsms();

void write_fsms();

#endif // DATA_H