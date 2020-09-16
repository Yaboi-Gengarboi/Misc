// RPGGame
// Type.h
// Justyn Durnford
// Created on 2020-04-07
// Last updated on 2020-09-12

#ifndef TYPE_H
#define TYPE_H

#include <string>
#include <vector>

// Types are elemental properties of moves and Pokemon. Each move has 1 designated type
// while a Pokemon may have 1 or 2 types. Each type has varying effectiveness against 
// Pokemon of opposing types. There are 18 different types.
class Type
{
    std::string _name;
    unsigned char _id = -1;

    public:

    Type() = default;
    Type(const Type& type) = delete;
    Type(Type&& type) = delete;
    Type& operator = (const Type& type) = delete;
    Type& operator = (Type&& type) = delete;

    // Primary constructor.
    // _name = name
    // _id = id
    Type(const std::string& name, unsigned char id);

    // Destructor.
    ~Type() = default;

    // Returns _name.
    std::string name() const;

    // Returns _id.
    unsigned char id() const;
};

// Returns true ONLY IF t1.id() == t2.id()
bool operator == (const Type& t1, const Type& t2);

// Returns true ONLY IF t1.id() != t2.id()
bool operator != (const Type& t1, const Type& t2);

extern std::vector<Type> type_list;

extern const float type_matchups[18][18];

#endif // TYPE_H