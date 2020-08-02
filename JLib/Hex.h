// Hex.h
// Justyn Durnford
// Created on 8/1/2020
// Last updated on 8/1/2020

#ifndef HEX_H
#define HEX_H

#include <string>

class Hex_Int
{
	long int _value = 0;
	std::string _hexstr = "";

	public:

	// Default constructor.
	Hex_Int();

	// long int constructor.
	Hex_Int(const long int& value);

	// std::string constructor.
	Hex_Int(const std::string& hexstr);

	// Destructor.
	~Hex_Int();

	// Returns _value.
	long int value() const;

	// Returns _heexstr.
	std::string hexstr() const;

	// Sets _value to value and adjusts _hexstr appropriately.
	void setValue(const long int& value);

	// Sets _hexstr to hexstr and adjusts _value appropriately.
	void setValue(const std::string& hexstr);
};

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

	// Returns _heexstr.
	std::string hexstr() const;

	// Sets _value to value and adjusts _hexstr appropriately.
	void setValue(const float& value);

	// Sets _hexstr to hexstr and adjusts _value appropriately.
	void setValue(const std::string& hexstr);
};

std::string to_hex(const long int& i);

std::string to_hex(const float& f);

long int hex_to_int(const std::string& hexstr);

float hex_to_float(const std::string& hexstr);

#endif // HEX_H