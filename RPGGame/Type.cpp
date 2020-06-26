// RPGGame
// Type.cpp
// Justyn Durnford
// Created on 4/12/2020
// Last updated on 6/21/2020

#include "Type.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

Type::Type() { /* See Type.h for default values. */ }

Type::Type(const string& name, unsigned char id)
{
    _name = name;
    _id = id;
}

Type::~Type() { /* Destructor. */ }

string Type::name() const
{
    return _name;
}

unsigned char Type::id() const
{
    return _id;
}

bool operator == (const Type& t1, const Type& t2)
{
    if (t1.id() == t2.id())
        return true;
    return false;
}

bool operator != (const Type& t1, const Type& t2)
{
    if (t1.id() != t2.id())
        return true;
    return false;
}

vector<Type> type_list =
{
    Type("Normal", 0),
    Type("Fighting", 1),
    Type("Flying", 2),
    Type("Poison", 3),
    Type("Ground", 4),
    Type("Rock", 5),
    Type("Bug", 6),
    Type("Ghost", 7),
    Type("Steel", 8),
    Type("Fire", 9),
    Type("Water", 10),
    Type("Grass", 11),
    Type("Electric", 12),
    Type("Psychic", 13),
    Type("Ice", 14),
    Type("Dragon", 15),
    Type("Dark", 16),
    Type("Fairy", 17),
    Type("Null", 18)
};

const float type_matchup[19][19] =
{
    /* 0  : Normal   */ { 1,   1,   1,   1,   1,  .5,   1,   0,  .5,   1,   1,   1,   1,   1,   1,   1,   1,   1,  1 },
    /* 1  : Fighting */ { 2,   1,  .5,  .5,   1,   2,  .5,   0,   2,   1,   1,   1,   1,  .5,   2,   1,   2,  .5,  1 },
    /* 2  : Flying   */ { 1,   2,   1,   1,   1,  .5,   2,   1,  .5,   1,   1,   2,  .5,   1,   1,   1,   1,   1,  1 },
    /* 3  : Poison   */ { 1,   1,   1,  .5,  .5,  .5,   1,  .5,   0,   1,   2,   2,   1,   1,   1,   1,   1,   2,  1 },
    /* 4  : Ground   */ { 1,   1,   0,   2,   1,   2,  .5,   1,   2,   2,   1,  .5,   2,   1,   1,   1,   1,   1,  1 },
    /* 5  : Rock     */ { 1,  .5,   2,   1,  .5,   1,   2,   1,  .5,   2,   1,   1,   1,   1,   2,   1,   1,   1,  1 },
    /* 6  : Bug      */ { 1,  .5,  .5,  .5,   1,   1,   1,  .5,  .5,  .5,   1,   1,   1,   2,   1,   1,   2,   2,  1 },
    /* 7  : Ghost    */ { 0,   1,   1,   1,   1,  .5,   1,   2,   1,   1,   1,   1,   1,   2,   1,   1,  .5,   1,  1 },
    /* 8  : Steel    */ { 1,   1,   1,   1,   1,   2,   1,   1,  .5,  .5,  .5,   1,  .5,   1,   2,   1,   1,   2,  1 },
    /* 9  : Fire     */ { 1,   1,   1,   1,   1,  .5,   2,   1,   2,  .5,  .5,   2,   1,   1,   2,  .5,   1,   1,  1 },
    /* 10 : Water    */ { 1,   1,   1,   1,   2,   2,   1,   1,   1,   2,  .5,  .5,   1,   1,  .5,  .5,   1,   1,  1 },
    /* 11 : Grass    */ { 1,   1,  .5,  .5,   2,   2,   1,   1,  .5,  .5,   2,  .5,   1,   1,   1,  .5,   1,   1,  1 },
    /* 12 : Electric */ { 1,   1,   2,   1,   0,   1,   1,   1,   1,   1,   2,  .5,  .5,   1,   1,  .5,   1,   1,  1 },
    /* 13 : Psychic  */ { 1,   2,   1,   2,   1,   1,  .5,   1,  .5,   1,   1,   1,   1,  .5,   1,   1,   0,   1,  1 },
    /* 14 : Ice      */ { 1,   1,   2,   1,   2,   1,   1,   1,  .5,  .5,   1,   2,   1,   1,  .5,   2,   1,   1,  1 },
    /* 15 : Dragon   */ { 1,   1,   1,   1,   1,  .5,   1,   1,  .5,   1,   1,   1,   1,   1,   1,   2,   1,   0,  1 },
    /* 16 : Dark     */ { 1,  .5,   1,   1,   1,  .5,  .5,   2,   1,   1,   1,   1,   1,   2,   1,   1,  .5,  .5,  1 },
    /* 17 : Fairy    */ { 1,   2,   1,  .5,   1,   1,  .5,   1,  .5,  .5,   1,   1,   1,   1,   1,   2,   2,   1,  1 },
    /* 18 : Null     */ { 1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,  1 }

    // Poison -> Water: 1 -> 2
    // Bug -> Grass: 2 -> 1
    // Bug -> Fairy: .5 -> 2
    // Ghost -> Rock: 1 -> .5
    // Ghost -> Steel: .5 -> 1
    // Water -> Ice: 1 -> .5
    // Grass -> Bug: .5 -> 1
    // Psychic -> Bug: 1 -> .5
    // Ice -> Water: .5 -> 1
    // Dragon -> Rock: 1 -> .5
    // Dark -> Rock: 1 -> .5
    // Dark -> Bug: 1 -> .5
    // Dark -> Steel: .5 -> 1
    // Fairy -> Bug: 1 -> .5
};