// Jcolor.hpp
// Justyn Durnford
// Created on 4/17/2020
// Last updated on 4/27/2020

#ifndef JCOLOR_HPP
#define JCOLOR_HPP

#include <string>

class Jcolor
{
	unsigned char _r = 0;
	unsigned char _g = 0;
	unsigned char _b = 0;
	unsigned char _alpha = 0;

	public:

	static const unsigned char MAX = 255;

	Jcolor();
	Jcolor(unsigned char r, unsigned char g, unsigned char b);
	Jcolor(unsigned char c_arr[3]);
	Jcolor(unsigned char r, unsigned char g, unsigned char b, unsigned char alpha);
	Jcolor(unsigned char c_arr[4]);
	Jcolor(const Jcolor& c);

	~Jcolor();

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

	Jcolor& operator = (const Jcolor& fr);
	Jcolor& operator = (unsigned char c_arr[3]);
	Jcolor& operator = (unsigned char c_arr[4]);
};

bool operator == (const Jcolor& c1, const Jcolor& c2);
bool operator == (const Jcolor& c, unsigned char c_arr[4]);

#endif // JCOLOR_HPP