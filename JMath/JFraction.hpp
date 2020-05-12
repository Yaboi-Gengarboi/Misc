// JFraction.hpp
// Justyn P. Durnford
// Created on 12/14/2019
// Last updated on 4/2/2020

// This class allows an "exact" representation of the quotient
// of two integers by storing them and allowing the use of the
// individual integers or the actual result.
// A JFraction can be constructed by default, with two individual
// integers or a C-array or with another JFraction.
// JFraction objects are also capable of arithmetic with integers
// other Fraction objects.
// A Fraction can be represented as a std::string with the toString method.
// Note that any method that can assign or otherwise modify
// _denominator will never allow it to be set to 0 and will result
// in _denominator remaining at its default value of 1.

#ifndef JFRACTION_HPP
#define JFRACTION_HPP

#include <string>

class JFraction
{
	int _numerator = 0;
	int _denominator = 1;

	public:

	// Constructors
	JFraction();
	JFraction(int numer, int denom);
	JFraction(int fr_arr[2]);
	JFraction(const JFraction& fr);

	// Destructor
	~JFraction();

	// Returns _numerator
	int getNumerator() const;

	// Returns _denominator
	int getDenominator() const;

	// Sets _numerator to numer
	void setNumerator(int numer);

	// Sets _denominator to denom
	void setDenominator(int denom);

	// Returns the integer division of the JFraction
	int intResult() const;

	//Returns the decimal division of the JFraction
	double doubleResult() const;

	//Adds num onto the JFraction
	void add(int num);

	//Subtracts num onto the JFraction
	void subtract(int num);

	//Multiplies num onto the JFraction
	void multiply(int num);

	//Divides num onto the JFraction
	void divide(int num);

	//Adds frac onto the JFraction
	void add(const JFraction& fr);

	//Subtracts frac onto the JFraction
	void subtract(const JFraction& fr);

	//Multiplies frac onto the JFraction
	void multiply(const JFraction& fr);

	// Divides fr onto the JFraction
	void divide(const JFraction& fr);

	// Returns an std::string representation of the JFraction
	std::string toString() const;

	JFraction operator = (const JFraction& fr);
	JFraction operator = (int i);

	//
	JFraction& operator += (const JFraction& fr);
	JFraction& operator += (int i);

	JFraction& operator -= (const JFraction& fr);
	JFraction& operator -= (int i);

	JFraction& operator *= (const JFraction& fr);
	JFraction& operator *= (int i);

	JFraction& operator /= (const JFraction& fr);
	JFraction& operator /= (int i);
};

JFraction operator + (const JFraction& fr1, const JFraction& fr2);
JFraction operator + (const JFraction& fr, int i);

JFraction operator - (const JFraction& fr1, const JFraction& fr2);
JFraction operator - (const JFraction& fr, int i);

JFraction operator * (const JFraction& fr1, const JFraction& fr2);
JFraction operator * (const JFraction& fr, int i);

JFraction operator / (const JFraction& fr1, const JFraction& fr2);
JFraction operator / (const JFraction& fr, int i);

bool operator == (const JFraction& fr1, const JFraction& fr2);
bool operator == (const JFraction& fr, int i);
bool operator == (const JFraction& fr, double d);

bool operator != (const JFraction& fr1, const JFraction& fr2);
bool operator != (const JFraction& fr, int i);
bool operator != (const JFraction& fr, double d);

#endif // JFRACTION_HPP