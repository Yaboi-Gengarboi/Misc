// Color.cpp
// Justyn Durnford
// Created on 6/11/2020
// Last updated on 6/11/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#include "Color.hpp"

#include <string>
using std::string;
using std::to_string;

Color::Color() { /* Default values are 0 */ }

Color::Color(unsigned char r, unsigned char g, unsigned char b)
{
	_r = r;
	_g = g;
	_b = b;
}

Color::Color(unsigned char c_arr[3])
{
	_r = c_arr[0];
	_g = c_arr[1];
	_b = c_arr[2];
}

Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char alpha)
{
	_r = r;
	_g = g;
	_b = b;
	_alpha = alpha;
}

Color::Color(unsigned char c_arr[4])
{
	_r = c_arr[0];
	_g = c_arr[1];
	_b = c_arr[2];
	_alpha = c_arr[3];
}

Color::Color(const Color& c) 
{
	_r = c.red();
	_g = c.green();
	_b = c.blue();
	_alpha = c.alpha();
}

Color::~Color() { /* Destructor */ }

unsigned char Color::red() const
{
	return _r;
}

unsigned char Color::green() const
{
	return _g;
}

unsigned char Color::blue() const
{
	return _b;
}

unsigned char Color::alpha() const
{
	return _alpha;
}

void Color::setRed(unsigned char r)
{
	_r = r;
}

void Color::setGreen(unsigned char g)
{
	_g = g;
}

void Color::setBlue(unsigned char b)
{
	_b = b;
}

void Color::setAlpha(unsigned char alpha)
{
	_alpha = alpha;
}

string Color::toString() const
{

}

string Color::toHex() const
{

}

Color& Color::operator = (const Color& fr)
{

}

Color& Color::operator = (unsigned char c_arr[3])
{

}

Color& Color::operator = (unsigned char c_arr[4])
{

}