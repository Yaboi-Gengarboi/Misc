// RPGGame
// Type.cpp
// Justyn Durnford
// Created on 4/12/2020
// Last updated on 5/27/2020

#include "Type.hpp"

#include <string>
using std::string;

#include <array>
using std::array;

#include <memory>
using std::shared_ptr;
using std::make_shared;

Type::Type() { /* See Type.hpp for default values */ }

Type::Type(const string& name, unsigned char id)
{
    _name = name;
    _id = id;
}

Type::~Type() { /* Destructor */ }

bool operator == (std::shared_ptr<Type> t1, std::shared_ptr<Type> t2)
{
    if (t1->_id == t2->_id)
        return true;
    return false;
}

bool operator != (std::shared_ptr<Type> t1, std::shared_ptr<Type> t2)
{
    return !(t1 == t2);
}

array<std::shared_ptr<Type>, 18> types
{
    make_shared<Type>("Normal", 0),
    make_shared<Type>("Fighting", 1),
    make_shared<Type>("Flying", 2),
    make_shared<Type>("Poison", 3),
    make_shared<Type>("Ground", 4),
    make_shared<Type>("Rock", 5),
    make_shared<Type>("Bug", 6),
    make_shared<Type>("Ghost", 7),
    make_shared<Type>("Steel", 8),
    make_shared<Type>("Fire", 9),
    make_shared<Type>("Water", 10),
    make_shared<Type>("Grass", 11),
    make_shared<Type>("Electric", 12),
    make_shared<Type>("Psychic", 13),
    make_shared<Type>("Ice", 14),
    make_shared<Type>("Dragon", 15),
    make_shared<Type>("Dark", 16),
    make_shared<Type>("Fairy", 17)
};

const float type_matchup[18][18] =
{
    /* Normal   */ { 1,   1,   1,   1,   1,  .5,   1,   0,  .5,   1,   1,   1,   1,   1,   1,   1,   1,   1 },
    /* Fighting */ { 2,   1,  .5,  .5,   1,   2,  .5,   0,   2,   1,   1,   1,   1,  .5,   2,   1,   2,  .5 },
    /* Flying   */ { 1,   2,   1,   1,   1,  .5,   2,   1,  .5,   1,   1,   2,  .5,   1,   1,   1,   1,   1 },
    /* Poison   */ { 1,   1,   1,  .5,  .5,  .5,   1,  .5,   0,   1,   2,   2,   1,   1,   1,   1,   1,   2 },
    /* Ground   */ { 1,   1,   0,   2,   1,   2,  .5,   1,   2,   2,   1,  .5,   2,   1,   1,   1,   1,   1 },
    /* Rock     */ { 1,  .5,   2,   1,  .5,   1,   2,   1,  .5,   2,   1,   1,   1,   1,   2,   1,   1,   1 }, 
    /* Bug      */ { 1,  .5,  .5,  .5,   1,   1,   1,  .5,   1,  .5,   1,   2,   1,   2,   1,   1,   2,   2 },
    /* Ghost    */ { 0,   1,   1,   1,   1,   1,   1,   2,   1,   1,   1,   1,   1,   2,   1,   1,  .5,   1 },
    /* Steel    */ { 1,   1,   1,   1,   1,   2,   1,   1,  .5,  .5,  .5,   1,  .5,   1,   2,   1,   1,   2 },
    /* Fire     */ { 1,   1,   1,   1,   1,  .5,   2,   1,   2,  .5,  .5,   2,   1,   1,   2,  .5,   1,   1 },
    /* Water    */ { 1,   1,   1,   1,   2,   2,   1,   1,   1,   2,  .5,  .5,   1,   1,   1,  .5,   1,   1 },
    /* Grass    */ { 1,   1,  .5,   1,   2,   2,  .5,   1,   1,  .5,   2,  .5,   1,   1,   1,  .5,   1,   1 },
    /* Electric */ { 1,   1,   2,   1,   0,   1,   1,   1,   1,   1,   2,  .5,  .5,   1,   1,  .5,   1,   1 },
    /* Psychic  */ { 1,   2,   1,   2,   1,   1,   1,   1,  .5,   1,   1,   1,   1,  .5,   1,   1,   0,   1 },
    /* Ice      */ { 1,   1,   2,   1,   2,   1,   1,   1,  .5,  .5,   1,   2,   1,   1,  .5,   2,   1,   1 },
    /* Dragon   */ { 1,   1,   1,   1,   1,  .5,   1,   1,  .5,   1,   1,   1,   1,   1,   1,   2,   1,   0 },
    /* Dark     */ { 1,  .5,   1,   1,   1,   1,   1,   2,   1,   1,   1,   1,   1,   2,   1,   1,  .5,  .5 },
    /* Fairy    */ { 1,   2,   1,  .5,   1,   1,  .5,   1,  .5,  .5,   1,   1,   1,   1,   1,   2,   2,   1 } 

    // Poison -> Water: 1 -> 2
    // Bug -> Steel: .5 -> 1
    // Bug -> Fairy: .5 -> 2
    // Grass -> Poison: .5 -> 1
    // Grass -> Steel: .5 -> 1
    // Ice -> Water: .5 -> 1
    // Dragon -> Rock: 1 -> .5
    // Fairy -> Bug: 1 -> .5
};