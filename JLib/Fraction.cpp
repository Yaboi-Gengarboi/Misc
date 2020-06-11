// Fraction.cpp
// Justyn P. Durnford
// Created on 12/14/2019
// Last updated on 6/11/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#include "Fraction.hpp"

#include <string>
using std::string;
using std::to_string;

Fraction::Fraction() { /* Default values are 0 */ }

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

Fraction::Fraction(const Fraction& fr)
{
	_numerator = fr.getNumerator();
	_denominator = fr.getDenominator();
}

Fraction::~Fraction() { /* Destructor */ }

int Fraction::getNumerator() const
{
	return _numerator;
}

int Fraction::getDenominator() const
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

int Fraction::intResult() const
{
	return _numerator / _denominator;
}

double Fraction::doubleResult() const
{
	return ( ( 1.0 * _numerator ) / ( 1.0 * _denominator ) );
}

bool Fraction::isValid() const
{
	return _denominator == 0;
}

string Fraction::toString() const
{
	string str = "";
	str += to_string(_numerator);
	str += " / ";
	str += to_string(_denominator);
	return str;
}

Fraction& Fraction::operator = (const Fraction& fr)
{
	_numerator = fr.getNumerator();
	_denominator = fr.getDenominator();
	return *this;
}

Fraction& Fraction::operator = (int i)
{
	_numerator = i;
	_denominator = 1;
	return *this;
}

Fraction& Fraction::operator += (const Fraction& fr)
{
	int fr_arr[2] = { fr.getNumerator(), fr.getDenominator() };
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
	int fr_arr[2] = { fr.getNumerator(), fr.getDenominator() };
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
	_numerator *= fr.getNumerator();
	_denominator *= fr.getDenominator();
	return *this;
}

Fraction& Fraction::operator *= (int i)
{
	_numerator *= i;
	return *this;
}

Fraction& Fraction::operator /= (const Fraction& fr)
{
	_numerator *= fr.getDenominator();
	_denominator *= fr.getNumerator();
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

	if (fr1.getDenominator() != fr2.getDenominator())
	{
		denom = fr1.getDenominator() * fr2.getDenominator();
		numer = fr1.getNumerator() * fr2.getDenominator() + fr2.getNumerator() * fr1.getDenominator();
	}

	Fraction newfr(numer, denom);
	return newfr;
}

Fraction operator + (const Fraction& fr, int i)
{
	int numer = fr.getNumerator();
	int denom = fr.getDenominator();

	numer += i * fr.getDenominator();

	Fraction newfr(numer, denom);
	return newfr;
}

Fraction operator - (const Fraction& fr1, const Fraction& fr2)
{
	int numer = 0;
	int denom = 0;

	if (fr1.getDenominator() != fr2.getDenominator())
	{
		denom = fr1.getDenominator() * fr2.getDenominator();
		numer = fr1.getNumerator() * fr2.getDenominator() - fr2.getNumerator() * fr1.getDenominator();
	}

	Fraction newfr(numer, denom);
	return newfr;
}

Fraction operator - (const Fraction& fr, int i)
{
	int numer = fr.getNumerator();
	int denom = fr.getDenominator();

	numer -= i * fr.getDenominator();

	Fraction newfr(numer, denom);
	return newfr;
}

Fraction operator * (const Fraction& fr1, const Fraction& fr2)
{
	int numer = fr1.getNumerator() * fr2.getNumerator();
	int denom = fr1.getDenominator() * fr2.getDenominator();

	Fraction newfr(numer, denom);
	return newfr;
}

Fraction operator * (const Fraction& fr, int i)
{
	int numer = fr.getNumerator() * i;
	int denom = fr.getDenominator();

	Fraction newfr(numer, denom);
	return newfr;
}

Fraction operator / (const Fraction& fr1, const Fraction& fr2)
{
	int numer = fr1.getNumerator() * fr2.getDenominator();
	int denom = fr1.getDenominator() * fr2.getNumerator();

	Fraction newfr(numer, denom);
	return newfr;
}

Fraction operator / (const Fraction& fr, int i)
{
	int numer = fr.getNumerator();
	int denom = fr.getDenominator() * i;

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