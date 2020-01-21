//Fraction.hpp
//Justyn P. Durnford
//Created on 12/14/2019
//Last Updated on 1/18/2020
//https://github.com/Yaboi-Gengarboi/Misc/tree/master/JLib

/*
This class allows an "exact" representation of the quotient
of two integers by storing them and allowing the use of the
individual integers or the actual result.
A Fraction can be constructed by default, with two individual
integers, a C-array or an std::array.
Fraction objects are also capable of arithmetic with integers
other Fraction objects.
A Fraction can be represented as an std::array with the to_arr
method or an std::string with the to_str method.
Note that any method that can assign or otherwise modify
_denominator will never allow it to be set to 0 and will result
in _denominator remaining at its default value of 1.
*/

#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <array>
#include <string>

class Fraction
{
	int _numerator = 0;
	int _denominator = 1;

public:

	//Constructors.
	Fraction();
	Fraction(int numer, int denom);
	Fraction(int f_arr[2]);
	Fraction(std::array<int, 2> f_arr);

	//Destructor.
	~Fraction();

	//Returns _numerator.
	int get_numerator() const;

	//Returns _denominator.
	int get_denominator() const;

	//Sets _numerator to numer.
	void set_numerator(int numer);

	//Sets _denominator to denom.
	void set_denominator(int denom);

	//Returns the integer division of the fraction.
	int int_result() const;

	//Returns the decimal division of the fraction.
	double double_result() const;

	//Adds num onto the fraction.
	void add(int num);

	//Subtracts num onto the fraction.
	void subtract(int num);

	//Multiplies num onto the fraction.
	void multiply(int num);

	//Divides num onto the fraction.
	void divide(int num);

	//Adds frac onto the fraction.
	void add(const Fraction& frac);

	//Subtracts frac onto the fraction.
	void subtract(const Fraction& frac);

	//Multiplies frac onto the fraction.
	void multiply(const Fraction& frac);

	//Divides frac onto the fraction.
	void divide(const Fraction& frac);

	//Returns an std::array representation of the fraction.
	std::array<int, 2> to_arr() const;

	//Returns an std::string representation of the fraction.
	std::string to_str() const;
};

#endif //#ifndef FRACTION_HPP