// RPGGame
// Type.h
// Justyn Durnford
// Created on 2020-04-07
// Last updated on 2020-09-28

#ifndef TYPE_H_INCLUDED
#define TYPE_H_INCLUDED

#include "Matrix.h"

#include <array>
#include <string>

// Types are elemental properties of moves and Pokemon. Each move has 1 designated type
// while a Pokemon may have 1 or 2 types. Each type has varying effectiveness against 
// Pokemon of opposing types. There are 18 different types.
class Type
{
    unsigned char _id = 0;
    std::string _name;

    public:

    Type() = default;
    Type(const Type& type) = default;
    Type(Type&& type) = default;
    Type& operator = (const Type& type) = default;
    Type& operator = (Type&& type) = default;

    // Primary constructor.
    // _id = id
    // _name = name
    Type(unsigned char id, const std::string& name);

    // Destructor.
    ~Type() = default;

    // Returns _id.
    unsigned char id() const;

    // Returns _name.
    std::string name() const;
};

// Returns true ONLY IF t1.id() == t2.id()
bool operator == (const Type& t1, const Type& t2);

// Returns true ONLY IF t1.id() != t2.id()
bool operator != (const Type& t1, const Type& t2);

extern std::array<Type, 18> type_arr;
extern Matrix<float> type_matchups;

#endif // TYPE_H