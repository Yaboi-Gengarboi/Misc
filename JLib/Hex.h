// Hex.h
// Justyn Durnford
// Created on 8/1/2020
// Last updated on 8/4/2020

#ifndef HEX_H
#define HEX_H

#include <string>

class Hex_Long
{
	long _value = 0;
	std::string _hexstr = "";

	public:

	// _value = 0
	// _hexstr = ""
	Hex_Long();

	// _value = value
	// _hexstr = to_hex(_value)
	Hex_Long(const long& value);

	// _value = hex_to_int(_hexstr)
	// _hexstr = hexstr
	// 
	Hex_Long(const std::string& hexstr);

	// _value = i
	// _hexstr = to_hex(_value)
	Hex_Long operator = (long i);

	// _value = to_long(_hexstr)
	// _hexstr = str
	// 
	Hex_Long operator = (const std::string& str);

	// Destructor.
	~Hex_Long();

	// Returns _value.
	long int value() const;

	// Returns _hexstr.
	std::string hexstr() const;

	// Sets _value to value and adjusts _hexstr appropriately.
	void setValue(const long& value);

	// Sets _hexstr to hexstr and adjusts _value appropriately.
	//
	void setValue(const std::string& hexstr);



};

// 
Hex_Long operator + (const Hex_Long& hi1, const Hex_Long& hi2);

// Returns true if hi1._value == hi2._value.
bool operator == (const Hex_Long& hi1, const Hex_Long& hi2);

// Returns true if hi._value == i.
bool operator == (const Hex_Long& hi, const long& i);

// Returns true if hi._hexstr == str.
bool operator == (const Hex_Long& hi, const std::string& str);

// Returns true if hi1._value != hi2._value.
bool operator != (const Hex_Long& hi1, const Hex_Long& hi2);

// Returns true if hi._value != i.
bool operator != (const Hex_Long& hi, const long& i);

// Returns true if hi._hexstr != str.
bool operator != (const Hex_Long& hi, const std::string& str);

class Hex_Float
{
	float _value = 0;
	std::string _hexstr = "";

	public:

	// Default constructor.
	Hex_Float();

	// long int constructor.
	Hex_Float(const float& value);

	// std::string constructor.
	Hex_Float(const std::string& hexstr);

	// Destructor.
	~Hex_Float();

	// Returns _value.
	long int value() const;

	// Returns _hexstr.
	std::string hexstr() const;

	// Sets _value to value and adjusts _hexstr appropriately.
	void setValue(const float& value);

	// Sets _hexstr to hexstr and adjusts _value appropriately.
	void setValue(const std::string& hexstr);
};

std::string to_hex(long i);

std::string to_hex(float f);

long to_long(const std::string& hexstr);

float to_float(const std::string& hexstr);

#endif // HEX_H