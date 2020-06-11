// Big_Int.hpp
// Justyn Durnford
// Created on 4/9/2020
// Last updated on 6/11/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#ifndef BIG_INT_HPP
#define BIG_INT_HPP

#include <string>

class Big_Int
{
	long long _front = 0;
	unsigned long long _back = 0;

	public:

	Big_Int();
	Big_Int(long long front, unsigned long long back);
	Big_Int(const Big_Int& ji);

	~Big_Int();

	std::string toString();
};

bool operator == (const Big_Int& ji1, const Big_Int& ji2);

#endif // BIG_INT_HPP