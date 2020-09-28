// RPGGame
// Nature.h
// Justyn Durnford
// Created on 2020-06-25
// Last updated on 2020-09-28

#ifndef NATURE_H_INCLUDED
#define NATURE_H_INCLUDED

#include <array>
#include <string>

//
//
//
class Nature
{
	unsigned char _id = 0;
	std::string _name;
	unsigned char _goodStat = 0;
	unsigned char _badStat = 0;

	public:

	// Default constructor.
	Nature() = default;

	// Copy constructor.
	Nature(const Nature& nature) = default;

	// Move constructor.
	Nature(Nature&& nature) = default;

	// Primary constructor.
	Nature(unsigned char id, const char* name,
		   unsigned char goodStat, unsigned char badStat);

	// Copy assignment.
	Nature& operator = (const Nature& nature) = default;

	// Move assignment.
	Nature& operator = (Nature&& nature) = default;

	// Destructor.
	~Nature() = default;

	// Returns _id.
	unsigned char id() const;

	// Returns _name.
	std::string name() const;

	// Returns _goodStat.
	unsigned char goodStat() const;

	// Return _badStat.
	unsigned char badStat() const;
};

// Returns true ONLY IF n1.id() == n2.id()
bool operator == (const Nature& n1, const Nature& n2);

// Returns true ONLY IF n1.id() != n2.id()
bool operator != (const Nature& n1, const Nature& n2);

extern std::array<Nature, 25> nature_arr;

#endif // NATURE_H_INCLUDED