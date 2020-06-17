// RPGGame
// Type.cpp
// Justyn Durnford
// Created on 4/12/2020
// Last updated on 6/15/2020

#include "Type.hpp"

#include <string>
using std::string;

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

bool operator == (const shared_ptr<Type>& t1, const shared_ptr<Type>& t2)
{
    if (t1->_id == t2->_id)
        return true;
    return false;
}

bool operator != (const shared_ptr<Type>& t1, const shared_ptr<Type>& t2)
{
    if (t1->_id != t2->_id)
        return true;
    return false;
}

shared_ptr<Type> Normal = make_shared<Type>("Normal", 0);
shared_ptr<Type> Fighting = make_shared<Type>("Fighting", 1);
shared_ptr<Type> Flying = make_shared<Type>("Flying", 2);
shared_ptr<Type> Poison = make_shared<Type>("Poison", 3);
shared_ptr<Type> Ground = make_shared<Type>("Ground", 4);
shared_ptr<Type> Rock = make_shared<Type>("Rock", 5);
shared_ptr<Type> Bug = make_shared<Type>("Bug", 6);
shared_ptr<Type> Ghost = make_shared<Type>("Ghost", 7);
shared_ptr<Type> Steel = make_shared<Type>("Steel", 8);
shared_ptr<Type> Fire = make_shared<Type>("Fire", 9);
shared_ptr<Type> Water = make_shared<Type>("Water", 10);
shared_ptr<Type> Grass = make_shared<Type>("Grass", 11);
shared_ptr<Type> Electric = make_shared<Type>("Electric", 12);
shared_ptr<Type> Psychic = make_shared<Type>("Psychic", 13);
shared_ptr<Type> Ice = make_shared<Type>("Ice", 14);
shared_ptr<Type> Dragon = make_shared<Type>("Dragon", 15);
shared_ptr<Type> Dark = make_shared<Type>("Dark", 16);
shared_ptr<Type> Fairy = make_shared<Type>("Fairy", 17);

const float type_matchup[18][18] =
{
    /* 0  : Normal   */ { 1,   1,   1,   1,   1,  .5,   1,   0,  .5,   1,   1,   1,   1,   1,   1,   1,   1,   1 },
    /* 1  : Fighting */ { 2,   1,  .5,  .5,   1,   2,  .5,   0,   2,   1,   1,   1,   1,  .5,   2,   1,   2,  .5 },
    /* 2  : Flying   */ { 1,   2,   1,   1,   1,  .5,   2,   1,  .5,   1,   1,   2,  .5,   1,   1,   1,   1,   1 },
    /* 3  : Poison   */ { 1,   1,   1,  .5,  .5,  .5,   1,  .5,   0,   1,   2,   2,   1,   1,   1,   1,   1,   2 },
    /* 4  : Ground   */ { 1,   1,   0,   2,   1,   2,  .5,   1,   2,   2,   1,  .5,   2,   1,   1,   1,   1,   1 },
    /* 5  : Rock     */ { 1,  .5,   2,   1,  .5,   1,   2,   1,  .5,   2,   1,   1,   1,   1,   2,   1,   1,   1 },
    /* 6  : Bug      */ { 1,  .5,  .5,  .5,   1,   1,   1,  .5,  .5,  .5,   1,   1,   1,   2,   1,   1,   2,   2 },
    /* 7  : Ghost    */ { 0,   1,   1,   1,   1,  .5,   1,   2,   1,   1,   1,   1,   1,   2,   1,   1,  .5,   1 },
    /* 8  : Steel    */ { 1,   1,   1,   1,   1,   2,   1,   1,  .5,  .5,  .5,   1,  .5,   1,   2,   1,   1,   2 },
    /* 9  : Fire     */ { 1,   1,   1,   1,   1,  .5,   2,   1,   2,  .5,  .5,   2,   1,   1,   2,  .5,   1,   1 },
    /* 10 : Water    */ { 1,   1,   1,   1,   2,   2,   1,   1,   1,   2,  .5,  .5,   1,   1,  .5,  .5,   1,   1 },
    /* 11 : Grass    */ { 1,   1,  .5,  .5,   2,   2,   1,   1,  .5,  .5,   2,  .5,   1,   1,   1,  .5,   1,   1 },
    /* 12 : Electric */ { 1,   1,   2,   1,   0,   1,   1,   1,   1,   1,   2,  .5,  .5,   1,   1,  .5,   1,   1 },
    /* 13 : Psychic  */ { 1,   2,   1,   2,   1,   1,  .5,   1,  .5,   1,   1,   1,   1,  .5,   1,   1,   0,   1 },
    /* 14 : Ice      */ { 1,   1,   2,   1,   2,   1,   1,   1,  .5,  .5,   1,   2,   1,   1,  .5,   2,   1,   1 },
    /* 15 : Dragon   */ { 1,   1,   1,   1,   1,  .5,   1,   1,  .5,   1,   1,   1,   1,   1,   1,   2,   1,   0 },
    /* 16 : Dark     */ { 1,  .5,   1,   1,   1,  .5,  .5,   2,   1,   1,   1,   1,   1,   2,   1,   1,  .5,  .5 },
    /* 17 : Fairy    */ { 1,   2,   1,  .5,   1,   1,  .5,   1,  .5,  .5,   1,   1,   1,   1,   1,   2,   2,   1 }

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