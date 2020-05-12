// Jfraction.hpp
// Justyn P. Durnford
// Created on 12/14/2019
// Last updated on 5/11/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

// This class allows an "exact" representation of the quotient
// of two integers by storing them and allowing the use of the
// individual integers or the actual result.
// A Jfraction can be constructed by default, with two individual
// integers or a C-array or with another Jfraction.
// Jfraction objects are also capable of arithmetic with integers
// other Fraction objects.
// A Fraction can be represented as a std::string with the toString method.

#ifndef JFRACTION_HPP
#define JFRACTION_HPP

#include <string>

class Jfraction
{
	int _numerator = 0;
	int _denominator = 0;

	public:

	// Constructors
	Jfraction();
	Jfraction(int numer, int denom);
	Jfraction(int fr_arr[2]);
	Jfraction(const Jfraction& fr);

	// Destructor
	~Jfraction();

	// Returns _numerator
	int getNumerator() const;

	// Returns _denominator
	int getDenominator() const;

	// Sets _numerator to numer
	void setNumerator(int numer);

	// Sets _denominator to denom
	void setDenominator(int denom);

	// Returns the integer division of the Jfraction
	int intResult() const;

	//Returns the decimal division of the Jfraction
	double doubleResult() const;

	// Returns a bool that determines if the Jfraction is a
	// valid fraction (_denominator is 0)
	bool isValid() const;

	// Returns a std::string representation of the Jfraction
	std::string toString() const;

	Jfraction& operator = (const Jfraction& fr);
	Jfraction& operator = (int i);

	Jfraction& operator += (const Jfraction& fr);
	Jfraction& operator += (int i);

	Jfraction& operator -= (const Jfraction& fr);
	Jfraction& operator -= (int i);

	Jfraction& operator *= (const Jfraction& fr);
	Jfraction& operator *= (int i);

	Jfraction& operator /= (const Jfraction& fr);
	Jfraction& operator /= (int i);
};

Jfraction operator + (const Jfraction& fr1, const Jfraction& fr2);
Jfraction operator + (const Jfraction& fr, int i);

Jfraction operator - (const Jfraction& fr1, const Jfraction& fr2);
Jfraction operator - (const Jfraction& fr, int i);

Jfraction operator * (const Jfraction& fr1, const Jfraction& fr2);
Jfraction operator * (const Jfraction& fr, int i);

Jfraction operator / (const Jfraction& fr1, const Jfraction& fr2);
Jfraction operator / (const Jfraction& fr, int i);

bool operator == (const Jfraction& fr1, const Jfraction& fr2);
bool operator == (const Jfraction& fr, int i);
bool operator == (const Jfraction& fr, double d);

bool operator != (const Jfraction& fr1, const Jfraction& fr2);
bool operator != (const Jfraction& fr, int i);
bool operator != (const Jfraction& fr, double d);

#endif // JFRACTION_HPP