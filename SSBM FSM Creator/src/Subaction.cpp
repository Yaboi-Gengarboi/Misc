// SSBM FSM Creator
// Subaction.cpp
// Justyn Durnford
// Created on 2020-07-29
// Last updated on 2021-01-03
// Source file for the Subaction struct.

#include "Subaction.h"

Subaction::Subaction(uint16_t new_id, const string& new_name)
	: id(new_id), name(new_name) {}

bool operator == (const Subaction& A, const Subaction& B)
{
	return A.id == B.id;
}

bool operator != (const Subaction& A, const Subaction& B)
{
	return A.id != B.id;
}