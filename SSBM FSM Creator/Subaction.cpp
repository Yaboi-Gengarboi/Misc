// SSBM FSM Creator
// Subaction.cpp
// Justyn Durnford
// Created on 7/29/2020
// Last updated on 7/30/2020

#include "Subaction.h"

#include <string>
using std::string;

Subaction::Subaction() { /* See Subaction.h for default values. */ }

Subaction::Subaction(const string& name, unsigned short id)
{
	_name = name;
	_id = id;
}

Subaction::~Subaction() { /* Destructor */ }

string Subaction::name() const
{
	return _name;
}

unsigned short Subaction::id() const
{
	return _id;
}

bool operator == (const Subaction& a, const Subaction& b)
{
	if (a._id == b._id)
		return true;

	return false;
}

bool operator != (const Subaction& a, const Subaction& b)
{
	if (a._id != b._id)
		return true;

	return false;
}