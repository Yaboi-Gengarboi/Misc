//Fraction.hpp
//Justyn P. Durnford
//Created on 12/14/2019
//Last Updated on 1/14/2020
//Found at https://github.com/Yaboi-Gengarboi/Misc/tree/master/JLib

#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <string>

class Fraction
{
	int Fraction_numerator = 0;
	int Fraction_denominator = 0;

	public:

		Fraction();

		Fraction(const int& numer, const int& denom);

		int get_numerator() const;

		int get_denominator() const;

		void set_numerator(const int& numer);

		void set_denominator(const int& denom);

		int int_result() const;

		double double_result() const;

		std::string to_str() const;
};

#endif //#ifndef FRACTION_HPP