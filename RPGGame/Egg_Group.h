// RPGGame
// Egg_Group.h
// Justyn Durnford
// Created on 7/1/2020
// Last updated on 8/11/2020

#ifndef EGG_GROUP
#define EGG_GROUP

#include <string>
#include <vector>

//
//
//
class Egg_Group
{
	std::string _name;
	unsigned char _id = 0;

	public:

	// Default constructor.
	Egg_Group();

	// Primary constructor.
	Egg_Group(const std::string& name, unsigned char id);

	// Destructor.
	~Egg_Group();

	// Returns _name.
	std::string name() const;

	// Returns _id.
	unsigned char id() const;
};

extern std::vector<Egg_Group> egg_group_list;

#endif // EGG_GROUP