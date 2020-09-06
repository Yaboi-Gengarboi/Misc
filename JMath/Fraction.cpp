 /* 
 Fraction.cpp
 Justyn P. Durnford
 Created on 2019-12-14
 Last updated on 2020-09-06
 Source file for Fraction class

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

#include "Fraction.h"

#include <ostream>
using std::ostream;

#include <string>
using std::string;
using std::to_string;

void Fraction::setValues(int numer, int denom, char set)
{
	switch (set)
	{
		case 0: _numerator = numer;
			break;

		case 1: _denominator = denom;
			break;

		default:
			_numerator = numer;
			_denominator = denom;
			break;
	}

}

Fraction::Fraction(int numer, int denom)
{
	setValues(numer, denom, 2);
}

Fraction::Fraction(int fr_arr[2])
{
	setValues(fr_arr[0], fr_arr[1], 2);
}

Fraction& Fraction::operator = (int i)
{
	setValues(i, 1, 2);
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
	setValues(numer, 0, 0);
}

void Fraction::setDenominator(int denom)
{
	setValues(0, denom, 1);
}

int Fraction::toInt() const
{
	return _numerator / _denominator;
}

double Fraction::toDouble() const
{
	return ( ( 1.0 * _numerator ) / ( 1.0 * _denominator ) );
}

bool Fraction::isValid() const
{
	return _denominator != 0;
}

Fraction::operator bool() const
{
	return isValid();
}

char Fraction::compare(const Fraction& fr) const
{
	if (toDouble() > fr.toDouble())
		return 1;
	if (toDouble() < fr.toDouble())
		return -1;
	return 0;
}

char Fraction::compare(double d) const
{
	if (toDouble() > d)
		return 1;
	if (toDouble() < d)
		return -1;
	return 0;
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
	if (fr1.numerator() != fr2.numerator())
		return false;

	if (fr1.denominator() != fr2.denominator())
		return false;

	return true;
}

bool operator == (const Fraction& fr, double d)
{
	if (fr.toDouble() == d)
		return true;

	return false;
}

bool operator != (const Fraction& fr1, const Fraction& fr2)
{
	if (fr1.numerator() == fr2.numerator())
		return false;

	if (fr1.denominator() == fr2.denominator())
		return false;

	return true;
}

bool operator != (const Fraction& fr, double d)
{
	if (fr.toDouble() != d)
		return true;

	return false;
}

bool operator > (const Fraction& fr1, const Fraction& fr2)
{
	if (fr1.toDouble() > fr2.toDouble())
		return true;

	return false;
}

bool operator > (const Fraction& fr, double d)
{
	if (fr.toDouble() > d)
		return true;

	return false;
}

bool operator >= (const Fraction& fr1, const Fraction& fr2)
{
	if (fr1.toDouble() >= fr2.toDouble())
		return true;

	return false;
}

bool operator >= (const Fraction& fr, double d)
{
	if (fr.toDouble() >= d)
		return true;

	return false;
}

bool operator < (const Fraction& fr1, const Fraction& fr2)
{
	if (fr1.toDouble() < fr2.toDouble())
		return true;

	return false;
}

bool operator < (const Fraction& fr, double d)
{
	if (fr.toDouble() < d)
		return true;

	return false;
}

bool operator <= (const Fraction& fr1, const Fraction& fr2)
{
	if (fr1.toDouble() <= fr2.toDouble())
		return true;

	return false;
}

bool operator <= (const Fraction& fr, double d)
{
	if (fr.toDouble() <= d)
		return true;

	return false;
}

ostream& operator << (std::ostream& os, const Fraction& fr)
{
	os << fr.toString();
	return os;
}