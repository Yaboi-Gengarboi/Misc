//Small_Int.cpp
//Justyn P. Durnford
//Created on 12/27/2019
//Last Updated on 1/1/2020

#include "Small_Int.hpp"

#include <string>
using std::string;
using std::to_string;
using std::stoi;

#include <stdexcept>
using std::invalid_argument;

Small_Int::Small_Int()
{
	Small_Int_value = 0;
}

Small_Int::Small_Int(const char& value)
{
	Small_Int_value = value;
}

char Small_Int::get_value() const
{
	return Small_Int_value;
}

void Small_Int::change_by(const char& value)
{
	Small_Int_value += value;
}

void Small_Int::change_to(const char& value)
{
	Small_Int_value = value;
}

int Small_Int::compare_to(const char& value) const
{
	if (Small_Int_value > value)
		return 1;
	else if (Small_Int_value < value)
		return -1;
	return 0;
}

int Small_Int::compare_to(const Small_Int& SI) const
{
	if (Small_Int_value > SI.get_value())
		return 1;
	else if (Small_Int_value < SI.get_value())
		return -1;
	return 0;
}

bool Small_Int::is_equal_to(const char& value) const
{
	if (Small_Int_value == value)
		return true;
	return false;
}

bool Small_Int::is_equal_to(const Small_Int& SI) const
{
	if (Small_Int_value == SI.get_value())
		return true;
	return false;
}

string Small_Int::to_str()
{
	return to_string((int)Small_Int_value);
}

Small_Int Small_Int::str_to_SI(const char* str)
{
	Small_Int si;

	try
	{
		string str_wrap = str;
		int str_to_int = stoi(str_wrap);
		si.change_to((char)str_to_int);
	}
	catch (const invalid_argument & ia)
	{/* Default constructor will set Small_Int_value to 0. */}

	return si;
}