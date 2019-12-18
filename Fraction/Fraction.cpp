//Fraction.cpp
//Justyn P. Durnford
//Created on 12/14/2019
//Last Updated on 12/14/2019

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
	return (double)(Fraction_numerator / Fraction_denominator);
}

const char* Fraction::to_cstr() const
{
	return to_str().c_str();
}

string Fraction::to_str() const
{
	string return_value = "";
	return_value += to_string(Fraction_numerator);
	return_value += " / ";
	return_value += to_string(Fraction_denominator);
	return return_value;
}