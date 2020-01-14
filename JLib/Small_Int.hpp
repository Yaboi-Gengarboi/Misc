//Small_Int.hpp
//Justyn P. Durnford
//Created on 12/26/2019
//Last Updated on 1/1/2020

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
		Small_Int(const char& value);

		//Returns the value of Small_Int_value.
		char get_value() const;

		//Changes the value of Small_Int_value BY the given value.
		void change_by(const char& value);

		//Changes the value of Small_Int_value TO the given value. 
		void change_to(const char& value);

		//Compares Small_Int_value with the given value.
		//Returns -1 if Small_Int_value is less than param_char.
		//Returns 1 if Small_Int_value is greater than param_char.
		//Returns 0 if Small_Int_value is equal to param_char.
		int compare_to(const char& value) const;

		//Compares Small_Int_value with the given Small_Int.
		//Returns -1 if Small_Int_value is less than param_Small_Int.
		//Returns 1 if Small_Int_value is greater than param_Small_Int.
		//Returns 0 if Small_Int_value is equal to param_Small_Int.
		int compare_to(const Small_Int& SI) const;

		//Returns true if Small_Int_value is equal to the given value.
		bool is_equal_to(const char& value) const;

		//Returns true if Small_Int_value is equal to the given Small_Int.
		bool is_equal_to(const Small_Int& SI) const;

		//Returns a string representation of Small_Int_value.
		std::string to_str();

		//Grabs a Small_Int from the string.
		Small_Int str_to_SI(const char* str);
};

#endif //#ifndef SMALL_INT_HPP