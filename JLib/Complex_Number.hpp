//Complex_Number.hpp
//Justyn P. Durnford
//Created on 12/28/2019
//Last Updated on 1/14/2020
//Found at https://github.com/Yaboi-Gengarboi/Misc/tree/master/JLib

#ifndef COMPLEX_NUMBER_HPP
#define COMPLEX_NUMBER_HPP

#include <string>

class Complex_Number
{
	long double Complex_Number_real = 0.0;
	long double Complex_Nuumber_imag = 0.0;

	public:

		Complex_Number();

		Complex_Number(const long double& param_ld1, const long double& param_ld2);

		void change_real_to(const long double& param_ld);

		friend Complex_Number operator + (const Complex_Number& param_cn1, const Complex_Number& param_cn2);
};

#endif //#ifndef COMPLEX_NUMBER_HPP