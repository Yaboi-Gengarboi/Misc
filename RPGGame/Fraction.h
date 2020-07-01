// RPGGame
// Fraction.h
// Justyn Durnford
// Created on 6/29/2020
// Last updated on 6/30/2020

#ifndef FRACTION_H
#define FRACTION_H

#include <string>

// This class allows an "exact" representation of the quotient
// of two integers by storing them and allowing the use of the
// individual integers or the actual result.
class Fraction
{
	int _numerator = 0;
	int _denominator = 0;

	public:

	// Default constructor.
	Fraction();

	// Primary constructor.
	Fraction(int numerator, int denominator);

	// Copy constructor.
	Fraction(const Fraction& fr);

	// String constructor.
	Fraction(const std::string& str);

	// Destructor.
	~Fraction();

	// Returns _numerator.
	int numerator() const;

	// Returns _denominator.
	int denominator() const;

	// Sets _numerator to numerator.
	void setNumerator(int numerator);

	// Sets _denominator to denominator.
	void setDenominator(int denominator);

	// Returns the integer division of the Fraction.
	int toInt() const;

	// Returns the float division of the Fraction.
	float toFloat() const;

	// Returns true only if _denominator != 0.
	bool isValid() const;

	// Returns a std::string representation of the Fraction.
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

// Returns true only if fr1.toFloat() == fr2.toFloat().
bool operator == (const Fraction& fr1, const Fraction& fr2);

// Returns true only if fr.toFloat() == f.
bool operator == (const Fraction& fr, float f);

// Returns true only if fr1.toFloat() != fr2.toFloat().
bool operator != (const Fraction& fr1, const Fraction& fr2);

// Returns true only if fr.toFloat() != f.
bool operator != (const Fraction& fr, float f);

// Returns true only if fr1.toFloat() > fr2.toFloat().
bool operator > (const Fraction& fr1, const Fraction& fr2);

// Returns true only if fr.toFloat > f.
bool operator > (const Fraction& fr, float f);

// Returns true only if fr1.toFloat() >= fr2.toFloat().
bool operator >= (const Fraction& fr1, const Fraction& fr2);

// Returns true only if fr.toFloat >= f.
bool operator >= (const Fraction& fr, float f);

// Returns true only if fr1.toFloat() < fr2.toFloat().
bool operator < (const Fraction& fr1, const Fraction& fr2);

// Returns true only if fr.toFloat < f.
bool operator < (const Fraction& fr, float f);

// Returns true only if fr1.toFloat() <= fr2.toFloat().
bool operator <= (const Fraction& fr1, const Fraction& fr2);

// Returns true only if fr.toFloat <= f.
bool operator <= (const Fraction& fr, float f);

#endif // FRACTION_H