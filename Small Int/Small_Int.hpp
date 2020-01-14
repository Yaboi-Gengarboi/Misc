//Small_Int.hpp
//Justyn P. Durnford
//Created on 12/26/2019
//Last Updated on 12/27/2019

#ifndef SMALL_INT_HPP
#define SMALL_INT_HPP

#include <string>

class Small_Int
{
	char Small_Int_value = 0;

	public:

		//Default Small_Int constructor.
		Small_Int();

		//Primary Small_Int constructor.
		Small_Int(const char& param_char);

		//Returns the value of Small_Int_value.
		char get_value() const;

		//Changes the value of Small_Int_value BY the given value.
		void change_value(const char& param_char);

		//Changes the value of Small_Int_value TO the given value. 
		void set_value(const char& param_char);

		//Returns a string representation of Small_Int_value.
		std::string to_string() const;

		//Compares Small_Int_value with the given value.
		//Returns -1 if Small_Int_value is less than param_char.
		//Returns 1 if Small_Int_value is greater than param_char.
		//Returns 0 if Small_Int_value is equal to param_char.
		int compare_to(const char& param_char) const;

		//Compares Small_Int_value with the given Small_Int.
		//Returns -1 if Small_Int_value is less than param_Small_Int.
		//Returns 1 if Small_Int_value is greater than param_Small_Int.
		//Returns 0 if Small_Int_value is equal to param_Small_Int.
		int compare_to(const Small_Int& param_Small_Int) const;

		//Returns true if Small_Int_value is equal to the given value.
		bool is_equal_to(const char& param_char) const;

		//Returns true if Small_Int_value is equal to the given Small_Int.
		bool is_equal_to(const Small_Int& param_Small_Int) const;
};

#endif //#ifndef SMALL_INT_HPP