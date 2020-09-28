// RPGGame
// Egg_Group.h
// Justyn Durnford
// Created on 2020-07-01
// Last updated on 2020-09-28

#ifndef EGG_GROUP_H_INCLUDED
#define EGG_GROUP_H_INCLUDED

#include <array>
#include <string>

//
//
//
class Egg_Group
{
	unsigned char _id = 0;
	std::string _name;

	public:

	// Default constructor.
	Egg_Group() = default;

	// Copy constructor.
	Egg_Group(const Egg_Group& egg_group) = default;

	// Move constructor.
	Egg_Group(Egg_Group&& egg_group) = default;

	// Primary constructor.
	Egg_Group(unsigned char id, const char* name);

	// Copy assignment.
	Egg_Group& operator = (const Egg_Group& egg_group) = default;

	// Move assignment.
	Egg_Group& operator = (Egg_Group&& egg_group) = default;

	// Destructor.
	~Egg_Group() = default;

	// Returns _id.
	unsigned char id() const;

	// Returns _name.
	std::string name() const;
};

extern std::array<Egg_Group, 15> egg_group_arr;

#endif // EGG_GROUP_H_INCLUDED