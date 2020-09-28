// RPGGame
// Move.cpp
// Justyn Durnford
// Created on 2020-05-23
// Last updated on 2020-09-27

#include "Move.h"

#include "Type.h"
class Type;

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <string>
using std::string;

Move_Kind::Move_Kind(unsigned char id, const char* name)
{
	_id = id;
	_name = name;
}

Move::Move(unsigned short id, const char* name, const char* desc,
		   const Type& type, const Move_Kind& kind, unsigned char power,
		   unsigned char pp, unsigned short accuracy, unsigned short additionalChance,
		   char priority)
{
	_id = id;
	_name = name;
	_desc = desc;
	_type = make_shared<Type>(type);
	_kind = make_shared<Move_Kind>(kind);
	_power = power;
	_pp = pp;
	_accuracy = accuracy;
	_additionalChance = additionalChance;
	_priority = priority;
}

unsigned short Move::id() const
{
	return _id;
}

string Move::name() const
{
	return _name;
}

string Move::desc() const
{
	return _desc;
}

shared_ptr<Type> Move::type() const
{
	return _type;
}

shared_ptr<Move_Kind> Move::kind() const
{
	return _kind;
}

unsigned char Move::power() const
{
	return _power;
}

unsigned char Move::pp() const
{
	return _pp;
}

unsigned short Move::accuracy() const
{
	return _accuracy;
}

unsigned short Move::additionalChance() const
{
	return _additionalChance;
}

char Move::priority() const
{
	return _priority;
}

bool operator == (const Move_Kind& m1, const Move_Kind& m2)
{
	if (m1._id == m2._id)
		return true;
	return false;
}

bool operator != (const Move_Kind& m1, const Move_Kind& m2)
{
	if (m1._id != m2._id)
		return true;
	return false;
}

bool operator == (const Move& m1, const Move& m2)
{
	if (m1.id() == m2.id())
		return true;
	return false;
}

bool operator != (const Move& m1, const Move& m2)
{
	if (m1.id() != m2.id())
		return true;
	return false;
}