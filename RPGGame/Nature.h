// RPGGame
// Nature.h
// Justyn Durnford
// Created on 6/25/2020
// Last updated on 6/26/2020

#ifndef NATURE_H
#define NATURE_H

#include <string>
#include <vector>

//
//
//
class Nature
{
	std::string _name = "";
	unsigned char _id = 0;
	unsigned char _goodStat = 0;
	unsigned char _badStat = 0;

	public:

	// Default constructor.
	Nature();

	// Primary constructor.
	Nature(const std::string& name, unsigned char id,
		   unsigned char goodStat, unsigned char badStat);

	// Destructor.
	~Nature();

	// Returns _name.
	std::string name() const;

	// Returns _id.
	unsigned char id() const;

	// Returns _goodStat.
	unsigned char goodStat() const;

	// Return _badStat.
	unsigned char badStat() const;
};

// Equality operators
bool operator == (const Nature& n1, const Nature& n2);
bool operator != (const Nature& n1, const Nature& n2);

extern std::vector<Nature> nature_list;

#endif // NATURE_H