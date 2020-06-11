// Fraction.hpp
// Justyn P. Durnford
// Created on 12/14/2019
// Last updated on 6/11/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

// This class allows an "exact" representation of the quotient
// of two integers by storing them and allowing the use of the
// individual integers or the actual result.
// A Fraction can be constructed by default, with two individual
// integers or a C-array or with another Fraction.
// Fraction objects are also capable of arithmetic with integers
// other Fraction objects.
// A Fraction can be represented as a std::string with the toString method.

#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <string>

class Fraction
{
	int _numerator = 0;
	int _denominator = 0;

	public:

	// Constructors
	Fraction();
	Fraction(int numer, int denom);
	Fraction(int fr_arr[2]);
	Fraction(const Fraction& fr);

	// Destructor
	~Fraction();

	// Returns _numerator
	int getNumerator() const;

	// Returns _denominator
	int getDenominator() const;

	// Sets _numerator to numer
	void setNumerator(int numer);

	// Sets _denominator to denom
	void setDenominator(int denom);

	// Returns the integer division of the Fraction
	int intResult() const;

	//Returns the decimal division of the Fraction
	double doubleResult() const;

	// Returns a bool that determines if the Fraction is a
	// valid fraction (_denominator is 0)
	bool isValid() const;

	// Returns a std::string representation of the Fraction
	std::string toString() const;

	Fraction& operator = (const Fraction& fr);
	Fraction& operator = (int i);

	Fraction& operator += (const Fraction& fr);
	Fraction& operator += (int i);

	Fraction& operator -= (const Fraction& fr);
	Fraction& operator -= (int i);

	Fraction& operator *= (const Fraction& fr);
	Fraction& operator *= (int i);

	Fraction& operator /= (const Fraction& fr);
	Fraction& operator /= (int i);
};

Fraction operator + (const Fraction& fr1, const Fraction& fr2);
Fraction operator + (const Fraction& fr, int i);

Fraction operator - (const Fraction& fr1, const Fraction& fr2);
Fraction operator - (const Fraction& fr, int i);

Fraction operator * (const Fraction& fr1, const Fraction& fr2);
Fraction operator * (const Fraction& fr, int i);

Fraction operator / (const Fraction& fr1, const Fraction& fr2);
Fraction operator / (const Fraction& fr, int i);

bool operator == (const Fraction& fr1, const Fraction& fr2);
bool operator == (const Fraction& fr, int i);
bool operator == (const Fraction& fr, double d);

bool operator != (const Fraction& fr1, const Fraction& fr2);
bool operator != (const Fraction& fr, int i);
bool operator != (const Fraction& fr, double d);

#endif // FRACTION_HPP