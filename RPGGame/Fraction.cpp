// RPGGame
// Fraction.cpp
// Justyn Durnford
// Created on 6/29/2020
// Last updated on 6/30/2020

#include "Fraction.h"

#include <string>
using std::string;
using std::to_string;
using std::stoi;

#include <stdexcept>
using std::invalid_argument;

Fraction::Fraction() { /* See Fraction.h for default values. */ }

Fraction::Fraction(int numerator, int denominator)
{
	_numerator = numerator;
	_denominator = denominator;
}

Fraction::Fraction(const Fraction& fr)
{
	_numerator = fr.numerator();
	_denominator = fr.denominator();
}

Fraction::Fraction(const string& str)
{
	try
	{
		_numerator = stoi(str.substr(0, str.find('/')));
		_denominator = stoi(str.substr(str.find('/') + 1));
	}
	catch (const invalid_argument& ia) { /* See Fraction.h for default values. */ }
}

Fraction::~Fraction() { /* Destructor. */ }

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

float Fraction::toFloat() const
{
	return ( ( 1.0f * _numerator ) / ( 1.0f * _denominator ) );
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
	_numerator = fr.numerator();
	_denominator = fr.denominator();

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
	if (fr1.toFloat() == fr2.toFloat())
		return true;
	return false;
}

bool operator == (const Fraction& fr, float f)
{
	if (fr.toFloat() == f)
		return true;
	return false;
}

bool operator != (const Fraction& fr1, const Fraction& fr2)
{
	if (fr1.toFloat() != fr2.toFloat())
		return true;
	return false;
}

bool operator != (const Fraction& fr, float f)
{
	if (fr.toFloat() != f)
		return true;
	return false;
}

bool operator > (const Fraction& fr1, const Fraction& fr2)
{
	if (fr1.toFloat() > fr2.toFloat())
		return true;
	return false;
}

bool operator > (const Fraction& fr, float f)
{
	if (fr.toFloat() > f)
		return true;
	return false;
}

bool operator >= (const Fraction& fr1, const Fraction& fr2)
{
	if (fr1.toFloat() >= fr2.toFloat())
		return true;
	return false;
}

bool operator >= (const Fraction& fr, float f)
{
	if (fr.toFloat() >= f)
		return true;
	return false;
}

bool operator < (const Fraction& fr1, const Fraction& fr2)
{
	if (fr1.toFloat() < fr2.toFloat())
		return true;
	return false;
}

bool operator < (const Fraction& fr, float f)
{
	if (fr.toFloat() < f)
		return true;
	return false;
}

bool operator <= (const Fraction& fr1, const Fraction& fr2)
{
	if (fr1.toFloat() <= fr2.toFloat())
		return true;
	return false;
}

bool operator <= (const Fraction& fr, float f)
{
	if (fr.toFloat() <= f)
		return true;
	return false;
}