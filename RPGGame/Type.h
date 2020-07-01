// RPGGame
// Type.h
// Justyn Durnford
// Created on 4/7/2020
// Last updated on 6/30/2020

#ifndef TYPE_H
#define TYPE_H

#include <string>
#include <vector>

//
//
//
class Type
{
    std::string _name = "";
    unsigned char _index = 0;

    public:

    // Default constructor.
    Type();

    // Primary constructor.
    Type(const std::string& name, unsigned char index);

    // Destructor.
    ~Type();

    // Returns _name.
    std::string name() const;

    // Returns _index.
    unsigned char index() const;
};

// Returns true ONLY IF t1.index() == t2.index()
bool operator == (const Type& t1, const Type& t2);

// Returns true ONLY IF t1.index() != t2.index()
bool operator != (const Type& t1, const Type& t2);

extern std::vector<Type> type_list;

extern const float type_matchup[19][19];

#endif // TYPE_H