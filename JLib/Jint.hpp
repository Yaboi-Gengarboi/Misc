// Jint.hpp
// Justyn Durnford
// Created on 4/9/2020
// Last updated on 5/11/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

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