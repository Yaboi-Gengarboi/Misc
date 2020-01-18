//Fraction.cpp
//Justyn P. Durnford
//Created on 12/14/2019
//Last Updated on 1/14/2020
//Found at https://github.com/Yaboi-Gengarboi/Misc/tree/master/JLib

#include "Fraction.hpp"

#include <string>
using std::string;
using std::to_string;

Fraction::Fraction()
{
	Fraction_numerator = 0;
	Fraction_denominator = 0;
}

Fraction::Fraction(const int& numer, const int& denom)
{
	Fraction_numerator = numer;
	Fraction_denominator = denom;
}

Fraction::~Fraction() {/* Destructor */}

int Fraction::get_numerator() const
{
	return Fraction_numerator;
}

int Fraction::get_denominator() const
{
	return Fraction_denominator;
}

void Fraction::set_numerator(const int& numer)
{
	Fraction_numerator = numer;
}

void Fraction::set_denominator(const int& denom)
{
	Fraction_denominator = denom;
}

int Fraction::int_result() const
{
	return Fraction_numerator / Fraction_denominator;
}

double Fraction::double_result() const
{
	return (long double)(Fraction_numerator / Fraction_denominator);
}

string Fraction::to_str() const
{
	string str = "";
	str += to_string(Fraction_numerator);
	str += " / ";
	str += to_string(Fraction_denominator);
	return str;
}