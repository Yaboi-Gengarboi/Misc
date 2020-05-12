// Jint.hpp
// Justyn Durnford
// Created on 4/9/2020
// Last updated on 4/27/2020

#ifndef JINT_HPP
#define JINT_HPP

#include <string>

class Jint
{
	long long _front = 0;
	unsigned long long _back = 0;

	public:

	Jint();
	Jint(long long front, unsigned long long back);
	Jint(const Jint& ji);

	~Jint();

	std::string toString();
};

bool operator == (const Jint& ji1, const Jint& ji2);

#endif // JINT_HPP