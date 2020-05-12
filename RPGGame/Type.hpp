// Type.hpp
// Justyn Durnford
// Created on 4/7/2020
// Last updated on 4/25/2020

#ifndef TYPE_HPP
#define TYPE_HPP

#include <string>
#include <memory>

struct Type
{
    std::string _name;
    unsigned char _id;

    Type(const std::string& name, unsigned char id);

    ~Type();
};

bool operator == (std::shared_ptr<Type> t1, std::shared_ptr<Type> t2);

Type Normal("Normal", 0);
Type Fighting("Fighting", 1);
Type Flying("Flying", 2);
Type Poison("Poison", 3);
Type Ground("Ground", 4);
Type Rock("Rock", 5);
Type Bug("Bug", 6);
Type Ghost("Ghost", 7);
Type Steel("Steel", 8);
Type Fire("Fire", 9);
Type Water("Water", 10);
Type Grass("Grass", 11);
Type Electric("Electric", 12);
Type Psychic("Psychic", 13);
Type Ice("Ice", 14);
Type Dragon("Dragon", 15);
Type Dark("Dark", 16);
Type Fairy("Fairy", 17);

extern const float type_matchup[18][18];

#endif // TYPE_HPP