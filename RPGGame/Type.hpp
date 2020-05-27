// RPGGame
// Type.hpp
// Justyn Durnford
// Created on 4/7/2020
// Last updated on 5/27/2020

#ifndef TYPE_HPP
#define TYPE_HPP

#include <string>
#include <memory>
#include <array>

struct Type
{
    std::string _name = "";
    unsigned char _id = -1;

    Type();
    Type(const std::string& name, unsigned char id);

    ~Type();
};

bool operator == (std::shared_ptr<Type> t1, std::shared_ptr<Type> t2);

bool operator != (std::shared_ptr<Type> t1, std::shared_ptr<Type> t2);

extern std::array<std::shared_ptr<Type>, 18> types;

extern const float type_matchup[18][18];

#endif // TYPE_HPP