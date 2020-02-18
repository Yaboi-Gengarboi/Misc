//Fraction.cpp
//Justyn P. Durnford
//Created on 12/14/2019
//Last Updated on 1/18/2020
//https://github.com/Yaboi-Gengarboi/Misc/tree/master/JLib

#include "Fraction.hpp"

#include <array>
using std::array;

#include <string>
using std::string;
using std::to_string;

Fraction::Fraction() {/* Default values are 0 and 1. */}

Fraction::Fraction(int numer, int denom)
{
	_numerator = numer;

	if (denom != 0)
		_denominator = denom;
}

Fraction::Fraction(int f_arr[2])
{
	_numerator = f_arr[0];

	if (f_arr[1] != 0)
		_denominator = f_arr[1];
}

Fraction::Fraction(const array<int, 2>& f_arr)
{
	_numerator = f_arr[0];

	if (f_arr[1] != 0)
		_denominator = f_arr[1];
}

Fraction::~Fraction() {/* Destructor */}

int Fraction::get_numerator() const
{
	return _numerator;
}

int Fraction::get_denominator() const
{
	return _denominator;
}

void Fraction::set_numerator(int numer)
{
	_numerator = numer;
}

void Fraction::set_denominator(int denom)
{
	if (denom != 0)
		_denominator = denom;
}

int Fraction::int_result() const
{
	return _numerator / _denominator;
}

double Fraction::double_result() const
{
	return ((1.0 * _numerator) / (1.0 * _denominator));
}

void Fraction::add(int num)
{
	num *= _denominator;
	_numerator += num;
}

void Fraction::subtract(int num)
{
	num *= _denominator;
	_numerator -= num;
}

void Fraction::multiply(int num)
{
	_numerator *= num;
}

void Fraction::divide(int num)
{
	if (num != 0)
		_denominator *= num;
}

void Fraction::add(const Fraction& frac)
{
	array<int, 2> frac_arr = frac.to_arr();
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

void Fraction::subtract(const Fraction& frac)
{
	array<int, 2> frac_arr = frac.to_arr();
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

void Fraction::multiply(const Fraction& frac)
{
	_numerator *= frac.get_numerator();
}

void Fraction::divide(const Fraction& frac)
{
	_denominator *= frac.get_denominator();
}

array<int, 2> Fraction::to_arr() const
{
	array<int, 2> arr = { _numerator, _denominator };
	return arr;
}

string Fraction::to_str() const
{
	string str = "";
	str += to_string(_numerator);
	str += " / ";
	str += to_string(_denominator);
	return str;
}