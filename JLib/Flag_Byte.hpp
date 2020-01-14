//Flag_Byte.hpp
//Justyn P. Durnford
//Created on 1/10/2020
//Last Updated on 1/11/2020

#ifndef FLAG_BYTE_HPP
#define FLAG_BYTE_HPP

#include <array>
#include <string>

static const unsigned char FLAG_1 = 1;
static const unsigned char FLAG_2 = 2;
static const unsigned char FLAG_3 = 4;
static const unsigned char FLAG_4 = 8;
static const unsigned char FLAG_5 = 16;
static const unsigned char FLAG_6 = 32;
static const unsigned char FLAG_7 = 64;
static const unsigned char FLAG_8 = 128;
static const unsigned char FLAG_NONE = 0;
static const unsigned char FLAG_ALL = 255;

class Flag_Byte
{
	char Flag_Byte_value = 0;

	public:

		//Default Constructor
		Flag_Byte();

		//Primary Constructor
		Flag_Byte(const unsigned char& param_c);

		unsigned char get_value();

		void set_value(const unsigned char& param_c);

		bool get_flag(const unsigned char& param_c);

		void set_flag(const unsigned char& param_c, const bool& param_b);

		void clear();

		std::string to_str();
};

#endif