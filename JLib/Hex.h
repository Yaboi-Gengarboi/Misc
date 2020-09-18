// Hex.h
// Justyn Durnford
// Created on 8/1/2020 2020-08-01
// Last updated on 8/5/2020 2020-08-05
// Header file for Hex classes

#ifndef HEX_H
#define HEX_H

#include <string>

class Hex_Char
{
	char _value = 0;
	std::string _hexstr;

	public:

	Hex_Char() = default;
	Hex_Char(const Hex_Char& hc) = default;
	Hex_Char(Hex_Char&& hc) = default;
	Hex_Char(char value);

	Hex_Char& operator = (const Hex_Char& hc) = default;
	Hex_Char& operator = (Hex_Char&& hc) = default;

	~Hex_Char() = default;
};

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

	Hex_Long& operator += (const long& l);
	Hex_Long& operator += (const Hex_Long& hl);

	Hex_Long& operator -= (const long& l);
	Hex_Long& operator -= (const Hex_Long& hl);

	Hex_Long& operator *= (const long& l);
	Hex_Long& operator *= (const Hex_Long& hl);

	Hex_Long& operator /= (const long& l);
	Hex_Long& operator /= (const Hex_Long& hl);
};

Hex_Long operator + (const Hex_Long& hl1, const Hex_Long& hl2);
Hex_Long operator + (const Hex_Long& hl1, const long& l);

Hex_Long operator - (const Hex_Long& hl1, const Hex_Long& hl2);
Hex_Long operator - (const Hex_Long& hl1, const long& l);

Hex_Long operator * (const Hex_Long& hl1, const Hex_Long& hl2);
Hex_Long operator * (const Hex_Long& hl1, const long& l);

Hex_Long operator / (const Hex_Long& hl1, const Hex_Long& hl2);
Hex_Long operator / (const Hex_Long& hl1, const long& l);

// Returns true if hl1._value == hl2._value.
bool operator == (const Hex_Long& hl1, const Hex_Long& hl2);

// Returns true if hl._value == i.
bool operator == (const Hex_Long& hl, const long& i);

// Returns true if hl._hexstr == str.
bool operator == (const Hex_Long& hl, const std::string& str);

// Returns true if hl1._value != hl2._value.
bool operator != (const Hex_Long& hl1, const Hex_Long& hl2);

// Returns true if hl._value != i.
bool operator != (const Hex_Long& hl, const long& i);

// Returns true if hl._hexstr != str.
bool operator != (const Hex_Long& hl, const std::string& str);

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