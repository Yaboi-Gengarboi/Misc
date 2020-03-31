//Fraction.cpp
//Justyn Durnford
//Created on 2/18/2020
//Last Updated on 2/18/2020
//

#include "JSpace.hpp"

using std::string;
using std::to_string;

JSpace::Fraction::Fraction() {/* Default values are 0 and 1. */}

JSpace::Fraction::Fraction(int numer, int denom)
{
	_numerator = numer;

	if (denom != 0)
		_denominator = denom;
}

JSpace::Fraction::Fraction(int frac_arr[2])
{
	_numerator = frac_arr[0];

	if (frac_arr[1] != 0)
		_denominator = frac_arr[1];
}

JSpace::Fraction::Fraction(const Fraction& frac)
{
	_numerator = frac.get_numerator();
	_denominator = frac.get_denominator();
}

JSpace::Fraction::~Fraction() {/* Destructor */}

int JSpace::Fraction::get_numerator() const
{
	return _numerator;
}

int JSpace::Fraction::get_denominator() const
{
	return _denominator;
}

void JSpace::Fraction::set_numerator(int numer)
{
	_numerator = numer;
}

void JSpace::Fraction::set_denominator(int denom)
{
	if (denom != 0)
		_denominator = denom;
}

int JSpace::Fraction::int_result() const
{
	return _numerator / _denominator;
}

double JSpace::Fraction::double_result() const
{
	return ((1.0 * _numerator) / (1.0 * _denominator));
}

void JSpace::Fraction::add(int num)
{
	num *= _denominator;
	_numerator += num;
}

void JSpace::Fraction::subtract(int num)
{
	num *= _denominator;
	_numerator -= num;
}

void JSpace::Fraction::multiply(int num)
{
	_numerator *= num;
}

void JSpace::Fraction::divide(int num)
{
	if (num != 0)
		_denominator *= num;
}

void JSpace::Fraction::add(const Fraction& frac)
{
	int frac_arr[2] = { frac.get_numerator(), frac.get_denominator() };
	int temp = 0;

	if (_denominator != frac_arr[1])
	{
		_numerator *= frac_arr[1];
		frac_arr[0] *= _denominator;

		temp = _denominator;
		_denominator *= frac_arr[1];
		frac_arr[1] *= temp;
	}

	_numerator += frac_arr[0];
}

void JSpace::Fraction::subtract(const Fraction& frac)
{
	int frac_arr[2] = { frac.get_numerator(), frac.get_denominator() };
	int temp = 0;

	if (_denominator != frac_arr[1])
	{
		_numerator *= frac_arr[1];
		frac_arr[0] *= _denominator;

		temp = _denominator;
		_denominator *= frac_arr[1];
		frac_arr[1] *= temp;
	}

	_numerator -= frac_arr[0];
}

void JSpace::Fraction::multiply(const Fraction& frac)
{
	_numerator *= frac.get_numerator();
}

void JSpace::Fraction::divide(const Fraction& frac)
{
	_denominator *= frac.get_denominator();
}

string JSpace::Fraction::to_str() const
{
	string str = "";

	str += to_string(_numerator);
	str += " / ";
	str += to_string(_denominator);

	return str;
}