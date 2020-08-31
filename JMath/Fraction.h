// Fraction.h
// Justyn P. Durnford
// Created on 2019-12-14
// Last updated on 2020-08-28
// Header file for Fraction class
// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.
  
#ifndef FRACTION_H
#define FRACTION_H

#include <ostream>
#include <string>

// This class allows an "exact" representation of the quotient
// of two integers by storing them and allowing the use of the
// individual integers or the actual result.
class Fraction
{
	int _numerator = 0;
	int _denominator = 0;

	public:

	// Automatic Constructors
	Fraction() = default;
	Fraction(const Fraction& fr) = default;
	Fraction& operator = (const Fraction& fr) = default;
	Fraction(Fraction&& fr) = default;
	Fraction& operator = (Fraction&& fr) = default;

	// Manual Constructors
	Fraction(int numer, int denom);
	Fraction(int fr_arr[2]);
	Fraction& operator = (int i);

	// Destructor
	~Fraction() = default;

	// Returns _numerator
	int numerator() const;

	// Returns _denominator
	int denominator() const;

	// Sets _numerator to numer
	void setNumerator(int numer);

	// Sets _denominator to denom
	void setDenominator(int denom);

	// Returns the integer division of the Fraction
	int toInt() const;

	//Returns the decimal division of the Fraction
	double toDouble() const;

	// Returns a bool that determines if the Fraction is a
	// valid fraction (_denominator is NOT 0)
	bool isValid() const;
	operator bool() const;

	// Returns a std::string representation of the Fraction
	// in the format "n / d"
	std::string toString() const;

	Fraction& operator ++ ();
	Fraction operator ++ (int);

	Fraction& operator -- ();
	Fraction operator -- (int);

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
bool operator == (const Fraction& fr, float f);
bool operator == (const Fraction& fr, double d);

bool operator != (const Fraction& fr1, const Fraction& fr2);
bool operator != (const Fraction& fr, int i);
bool operator != (const Fraction& fr, float f);
bool operator != (const Fraction& fr, double d);

std::ostream& operator << (std::ostream& os, const Fraction& fr);

#endif // FRACTION_H