// Color.hpp
// Justyn Durnford
// Created on 4/17/2020
// Last updated on 6/11/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#ifndef COLOR_HPP
#define COLOR_HPP

#include <string>

class Color
{
	unsigned char _r = 0;
	unsigned char _g = 0;
	unsigned char _b = 0;
	unsigned char _alpha = 0;

	public:

	static const unsigned char MAX = 255;

	Color();
	Color(unsigned char r, unsigned char g, unsigned char b);
	Color(unsigned char c_arr[3]);
	Color(unsigned char r, unsigned char g, unsigned char b, unsigned char alpha);
	Color(unsigned char c_arr[4]);
	Color(const Color& c);

	~Color();

	unsigned char red() const;

	unsigned char green() const;

	unsigned char blue() const;

	unsigned char alpha() const;

	void setRed(unsigned char red);

	void setGreen(unsigned char green);

	void setBlue(unsigned char blue);

	void setAlpha(unsigned char alpha);

	std::string toString() const;

	std::string toHexString() const;

	Color& operator = (const Color& fr);
	Color& operator = (unsigned char c_arr[3]);
	Color& operator = (unsigned char c_arr[4]);
};

bool operator == (const Color& c1, const Color& c2);
bool operator == (const Color& c, unsigned char c_arr[4]);

#endif // COLOR_HPP