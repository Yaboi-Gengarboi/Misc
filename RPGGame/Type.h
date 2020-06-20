// RPGGame
// Type.h
// Justyn Durnford
// Created on 4/7/2020
// Last updated on 6/20/2020

#ifndef TYPE_H
#define TYPE_H

#include <string>
#include <memory>

//
//
//
class Type
{
    std::string _name = "";
    unsigned char _id = -1;

    public:

    // Default constructor.
    Type();

    // Primary constructor.
    Type(const std::string& name, unsigned char id);

    // Destructor.
    ~Type();

    // Returns _name.
    std::string name() const;

    // Returns _id.
    unsigned char id() const;
};

bool operator == (const std::shared_ptr<Type>& t1, const std::shared_ptr<Type>& t2);
bool operator != (const std::shared_ptr<Type>& t1, const std::shared_ptr<Type>& t2);

extern std::shared_ptr<Type> Normal;
extern std::shared_ptr<Type> Fighting;
extern std::shared_ptr<Type> Flying;
extern std::shared_ptr<Type> Poison;
extern std::shared_ptr<Type> Ground;
extern std::shared_ptr<Type> Rock;
extern std::shared_ptr<Type> Bug;
extern std::shared_ptr<Type> Ghost;
extern std::shared_ptr<Type> Steel;
extern std::shared_ptr<Type> Fire;
extern std::shared_ptr<Type> Water;
extern std::shared_ptr<Type> Grass;
extern std::shared_ptr<Type> Electric;
extern std::shared_ptr<Type> Psychic;
extern std::shared_ptr<Type> Ice;
extern std::shared_ptr<Type> Dragon;
extern std::shared_ptr<Type> Dark;
extern std::shared_ptr<Type> Fairy;

extern const float type_matchup[18][18];

#endif // TYPE_H