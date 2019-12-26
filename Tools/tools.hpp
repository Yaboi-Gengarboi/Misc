//Tools.hpp
//Justyn P. Durnford
//Created on 12/14/2019
//Last Updated on 12/25/2019

#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <string>

class Point
{
	double Point_xpos = 0.0;
	double Point_ypos = 0.0;
	double Point_zpos = 0.0;

	public:

		//
		Point();

		//
		Point(const double& x, const double& y, const double& z);


};

class Fraction
{
	int Fraction_numerator = 0;
	int Fraction_denominator = 0;

	public:

		//Default Fraction constructor.
		Fraction();

		//Primary Fraction constructor.
		//Fraction_numerator takes on the value of numer.
		//Fraction_denominator takes on the value of denom.
		Fraction(const int& numer, const int& denom);

		//Returns Fraction_numerator.
		int get_numerator() const;

		//Returns Fraction_denominator.
		int get_denominator() const;

		//Sets the value of Fraction_numerator to numer.
		void set_numerator(const int& numer);

		//Sets the value of Fraction_denominator to denom.
		void set_denominator(const int& denom);

		//Returns the integer division of the Fraction.
		int int_result() const;

		//Returns the double division of the Fraction.
		double double_result() const;
	
		//Returns a string representation of the Fraction
		//in the format "N / D".
		std::string to_str() const;
};

#endif //#ifndef TOOLS_HPP