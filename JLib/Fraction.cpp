// Fraction.cpp
// Justyn P. Durnford
// Created on 2019-12-14
// Last updated on 2020-08-28
// Source file for Fraction class
//
// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#include "Fraction.h"

#include <ostream>
using std::ostream;

#include <string>
using std::string;
using std::to_string;

Fraction::Fraction(int numer, int denom)
{
	_numerator = numer;
	_denominator = denom;
}

Fraction::Fraction(int fr_arr[2])
{
	_numerator = fr_arr[0];
	_denominator = fr_arr[1];
}

Fraction& Fraction::operator = (int i)
{
	_numerator = i;
	_denominator = 1;
	return *this;
}

int Fraction::numerator() const
{
	return _numerator;
}

int Fraction::denominator() const
{
	return _denominator;
}

void Fraction::setNumerator(int numer)
{
	_numerator = numer;
}

void Fraction::setDenominator(int denom)
{
	_denominator = denom;
}

int Fraction::toInt() const
{
	return _numerator / _denominator;
}

double Fraction::toDouble() const
{
	return ((1.0 * _numerator) / (1.0 * _denominator));
}

bool Fraction::isValid() const
{
	return _denominator != 0;
}

Fraction::operator bool() const
{
	return isValid();
}

string Fraction::toString() const
{
	string str = "";
	str += to_string(_numerator);
	str += " / ";
	str += to_string(_denominator);
	return str;
}

Fraction& Fraction::operator += (const Fraction& fr)
{
	int fr_arr[2] = { fr.numerator(), fr.denominator() };
	int temp = 0;

	if (_denominator != fr_arr[1])
	{
		_numerator *= fr_arr[1];
		fr_arr[0] *= _denominator;

		temp = _denominator;
		_denominator *= fr_arr[1];
		fr_arr[1] *= temp;
	}

	_numerator += fr_arr[0];
	return *this;
}

Fraction& Fraction::operator += (int i)
{
	i *= _denominator;
	_numerator += i;
	return *this;
}

Fraction& Fraction::operator -= (const Fraction& fr)
{
	int fr_arr[2] = { fr.numerator(), fr.denominator() };
	int temp = 0;

	if (_denominator != fr_arr[1])
	{
		_numerator *= fr_arr[1];
		fr_arr[0] *= _denominator;

		temp = _denominator;
		_denominator *= fr_arr[1];
		fr_arr[1] *= temp;
	}

	_numerator -= fr_arr[0];
	return *this;
}

Fraction& Fraction::operator -= (int i)
{
	i *= _denominator;
	_numerator -= i;
	return *this;
}

Fraction& Fraction::operator *= (const Fraction& fr)
{
	_numerator *= fr.numerator();
	_denominator *= fr.denominator();
	return *this;
}

Fraction& Fraction::operator *= (int i)
{
	_numerator *= i;
	return *this;
}

Fraction& Fraction::operator /= (const Fraction& fr)
{
	_numerator *= fr.denominator();
	_denominator *= fr.numerator();
	return *this;
}

Fraction& Fraction::operator /= (int i)
{
	_denominator *= i;
	return *this;
}

Fraction operator + (const Fraction& fr1, const Fraction& fr2)
{
	int numer = 0;
	int denom = 0;

	if (fr1.denominator() != fr2.denominator())
	{
		denom = fr1.denominator() * fr2.denominator();
		numer = fr1.numerator() * fr2.denominator() + fr2.numerator() * fr1.denominator();
	}

	Fraction newfr(numer, denom);
	return newfr;
}

Fraction operator + (const Fraction& fr, int i)
{
	int numer = fr.numerator();
	int denom = fr.denominator();

	numer += i * fr.denominator();

	Fraction newfr(numer, denom);
	return newfr;
}

Fraction operator - (const Fraction& fr1, const Fraction& fr2)
{
	int numer = 0;
	int denom = 0;

	if (fr1.denominator() != fr2.denominator())
	{
		denom = fr1.denominator() * fr2.denominator();
		numer = fr1.numerator() * fr2.denominator() - fr2.numerator() * fr1.denominator();
	}

	Fraction newfr(numer, denom);
	return newfr;
}

Fraction operator - (const Fraction& fr, int i)
{
	int numer = fr.numerator();
	int denom = fr.denominator();

	numer -= i * fr.denominator();

	Fraction newfr(numer, denom);
	return newfr;
}

Fraction operator * (const Fraction& fr1, const Fraction& fr2)
{
	int numer = fr1.numerator() * fr2.numerator();
	int denom = fr1.denominator() * fr2.denominator();

	Fraction newfr(numer, denom);
	return newfr;
}

Fraction operator * (const Fraction& fr, int i)
{
	int numer = fr.numerator() * i;
	int denom = fr.denominator();

	Fraction newfr(numer, denom);
	return newfr;
}

Fraction operator / (const Fraction& fr1, const Fraction& fr2)
{
	int numer = fr1.numerator() * fr2.denominator();
	int denom = fr1.denominator() * fr2.numerator();

	Fraction newfr(numer, denom);
	return newfr;
}

Fraction operator / (const Fraction& fr, int i)
{
	int numer = fr.numerator();
	int denom = fr.denominator() * i;

	Fraction newfr(numer, denom);
	return newfr;
}

bool operator == (const Fraction& fr1, const Fraction& fr2)
{


	return false;
}

bool operator == (const Fraction& fr, int i)
{
	return false;
}

bool operator == (const Fraction& fr, double d)
{
	return false;
}

bool operator != (const Fraction& fr1, const Fraction& fr2)
{
	return false;
}

bool operator != (const Fraction& fr, int i)
{
	return false;
}

bool operator != (const Fraction& fr, double d)
{
	return false;
}

ostream& operator << (std::ostream& os, const Fraction& fr)
{
	os << fr.toString();
	return os;
}