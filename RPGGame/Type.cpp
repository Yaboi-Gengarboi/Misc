// RPGGame
// Type.cpp
// Justyn Durnford
// Created on 2020-04-12
// Last updated on 2020-09-17

#include "Type.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

Type::Type(unsigned char id, const string& name)
{
    _name = name;
    _id = id;
}

unsigned char Type::id() const
{
    return _id;
}

string Type::name() const
{
    return _name;
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
  
//const float type_matchups[18][18] = 
//{
//    /* 0  : Normal   */ { 1,   1,   1,   1,   1,  .5,   1,   0,  .5,   1,   1,   1,   1,   1,   1,   1,   1,   1 },
//    /* 1  : Fighting */ { 2,   1,  .5,  .5,   1,   2,  .5,   0,   2,   1,   1,   1,   1,  .5,   2,   1,   2,  .5 },
//    /* 2  : Flying   */ { 1,   2,   1,   1,   1,  .5,   2,   1,  .5,   1,   1,   2,  .5,   1,   1,   1,   1,   1 },
//    /* 3  : Poison   */ { 1,   1,   1,  .5,  .5,  .5,   1,  .5,   0,   1,   2,   2,   1,   1,   1,   1,   1,   2 },
//    /* 4  : Ground   */ { 1,   1,   0,   2,   1,   2,  .5,   1,   2,   2,   1,  .5,   2,   1,   1,   1,   1,   1 },
//    /* 5  : Rock     */ { 1,  .5,   2,   1,  .5,   1,   2,   1,  .5,   2,   1,   1,   1,   1,   2,   1,   1,   1 },
//    /* 6  : Bug      */ { 1,  .5,  .5,  .5,   1,   1,   1,  .5,  .5,  .5,   1,   1,   1,   2,   1,   1,   2,   2 },
//    /* 7  : Ghost    */ { 0,   1,   1,   1,   1,  .5,   1,   2,  .5,   1,   1,   1,   1,   2,   1,   1,  .5,   1 },
//    /* 8  : Steel    */ { 1,   1,   1,   1,   1,   2,   1,   1,  .5,  .5,  .5,   1,  .5,   1,   2,   1,   1,   2 },
//    /* 9  : Fire     */ { 1,   1,   1,   1,   1,  .5,   2,   1,   2,  .5,  .5,   2,   1,   1,   2,  .5,   1,   1 },
//    /* 10 : Water    */ { 1,   1,   1,   1,   2,   2,   1,   1,   1,   2,  .5,  .5,   1,   1,  .5,  .5,   1,   1 },
//    /* 11 : Plant    */ { 1,   1,  .5,  .5,   2,   2,   1,   1,  .5,  .5,   2,  .5,   1,   1,   1,  .5,   1,   1 },
//    /* 12 : Electric */ { 1,   1,   2,   1,   0,   1,   1,   1,   1,   1,   2,  .5,  .5,   1,   1,  .5,   1,   1 },
//    /* 13 : Psychic  */ { 1,   2,   1,   2,   1,  .5,   1,   1,   1,   1,   1,   1,   1,  .5,   1,   1,   0,   1 },
//    /* 14 : Ice      */ { 1,   1,   2,   1,   2,   1,   1,   1,  .5,  .5,   1,   2,   1,   1,  .5,   2,   1,   1 },
//    /* 15 : Dragon   */ { 1,   1,   1,   1,   1,   1,   1,   1,  .5,   1,   1,   1,   1,   1,   1,   2,   1,   0 },
//    /* 16 : Dark     */ { 1,  .5,   1,   1,   1,   1,   1,   2,   1,   1,   1,   1,   1,   2,   1,   1,  .5,  .5 },
//    /* 17 : Fairy    */ { 1,   2,   1,  .5,   1,   1,  .5,   1,  .5,  .5,   1,   1,   1,   1,   1,   2,   2,   1 }
//
//    // Flying -> Rock:     x1 -> x0.5
//    // Poison -> Water:    x1 -> x2
//    // Bug -> Plant:       x2 -> x1
//    // Bug -> Fairy:     x0.5 -> x2
//    // Ghost -> Rock:      x1 -> x0.5
//    // Water -> Ice:       x1 -> x0.5
//    // Plant -> Bug:     x0.5 -> x1
//    // Psychic -> Rock:    x1 -> x0.5
//    // Psychic -> Steel: x0.5 -> x1
//    // Ice -> Water:     x0.5 -> x1
//    // Dark -> Steel:    x0.5 -> x1
//    // Fairy -> Bug:       x1 -> x0.5
//};