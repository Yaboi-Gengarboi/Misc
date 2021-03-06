/*
Fraction.h
Justyn P. Durnford
Created on 2019-12-14
Last updated on 2020-09-06
Header file for Fraction class

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non - commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain.We make this dedication for the benefit
of the public at largeand to the detriment of our heirsand
successors.We intend this dedication to be an overt act of
relinquishment in perpetuity of all presentand future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>
*/
  
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

	// Sets _numerator to numer if set == 0 or 2
	// Sets _denominator to denom if set == 1 or 2
	void setValues(int numer, int denom, char set);

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
	// 
	int toInt() const;

	// Returns the decimal division of the Fraction
	// 
	double toDouble() const;

	// Returns a bool that determines if the Fraction is a
	// valid fraction (_denominator is NOT 0)
	bool isValid() const;
	operator bool() const;

	// Compares the Fraction to the given Fraction fr.
	// Returns 0 if the two Fractions are equal
	// Returns 1 if toDouble() > fr.toDouble()
	// Returns -1 if toDoible() < fr.toDouble()
	char compare(const Fraction& fr) const;
	char compare(double d) const;

	// Returns a std::string representation of the Fraction
	// in the format "n / d"
	std::string toString() const;

	// Preincrement operator
	Fraction& operator ++ ();

	// Postincrement operator
	Fraction operator ++ (int);

	// Predecrement operator
	Fraction& operator -- ();

	// Postdecrement operator
	Fraction operator -- (int);

	// 
	Fraction& operator += (const Fraction& fr);
	Fraction& operator += (int i);

	//
	Fraction& operator -= (const Fraction& fr);
	Fraction& operator -= (int i);

	//
	Fraction& operator *= (const Fraction& fr);
	Fraction& operator *= (int i);

	//
	Fraction& operator /= (const Fraction& fr);
	Fraction& operator /= (int i);
};

// Addition operators
Fraction operator + (const Fraction& fr1, const Fraction& fr2);
Fraction operator + (const Fraction& fr, int i);

// Subtraction operators
Fraction operator - (const Fraction& fr1, const Fraction& fr2);
Fraction operator - (const Fraction& fr, int i);

// Multiplication operators
Fraction operator * (const Fraction& fr1, const Fraction& fr2);
Fraction operator * (const Fraction& fr, int i);

// Division operators
Fraction operator / (const Fraction& fr1, const Fraction& fr2);
Fraction operator / (const Fraction& fr, int i);

// Equality comparison operators
bool operator == (const Fraction& fr1, const Fraction& fr2);
bool operator == (const Fraction& fr, double d);

// Inequality comparison operators
bool operator != (const Fraction& fr1, const Fraction& fr2);
bool operator != (const Fraction& fr, double d);

// Greater than comparison operators
bool operator > (const Fraction& fr1, const Fraction& fr2);
bool operator > (const Fraction& fr, double d);

// Greater than or equal to comparison operators
bool operator >= (const Fraction& fr1, const Fraction& fr2);
bool operator >= (const Fraction& fr, double d);

// Less than comparison operators
bool operator < (const Fraction& fr1, const Fraction& fr2);
bool operator < (const Fraction& fr, double d);

// Less than or equal to comparison operators
bool operator <= (const Fraction& fr1, const Fraction& fr2);
bool operator <= (const Fraction& fr, double d);

// ostream insertion operator
std::ostream& operator << (std::ostream& os, const Fraction& fr);

#endif // FRACTION_H