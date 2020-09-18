// Color.cpp
// Justyn Durnford
// Created on 2020-06-11
// Last updated on 2020-09-17
// Header file for Color class
// This is free and unencumbered software released into the public domain.
// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software, either in source code form or as a compiled
// binary, for any purpose, commercial or non-commercial, and by any
// means.
// In jurisdictions that recognize copyright laws, the author or authors
// of this software dedicate any and all copyright interest in the
// software to the public domain. We make this dedication for the benefit
// of the public at large and to the detriment of our heirs and
// successors. We intend this dedication to be an overt act of
// relinquishment in perpetuity of all presentand future rights to this
// software under copyright law.
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
// OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
// For more information, please refer to http://unlicense.org/

#include "Color.h"

#include <ostream>
using std::ostream;

#include <string>
using std::string;
using std::to_string;

void Color::setValues(unsigned char r, unsigned char g, unsigned char b, unsigned char alpha, char set)
{
	switch (set)
	{
		case 0:
			_r = r;
			break;

		case 1:
			_g = g;
			break;

		case 2:
			_b = b;
			break;

		case 3:
			_alpha = alpha;
			break;

		case 4:
			_r = r;
			_b = b;
			_g = g;
			break;

		default:
			_r = r;
			_g = g;
			_b = b;
			_alpha = alpha;
			break;
	}
}

Color::Color(unsigned char r, unsigned char g, unsigned char b)
{
	setValues(r, g, b, 0, 4);
}

Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char alpha)
{
	setValues(r, g, b, alpha, 5);
}

Color::Color(unsigned char arr[4])
{
	setValues(arr[0], arr[1], arr[2], arr[3], 5);
}

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
	setValues(r, 0, 0, 0, 0);
}

void Color::setGreen(unsigned char g)
{
	setValues(0, g, 0, 0, 1);
}

void Color::setBlue(unsigned char b)
{
	setValues(0, 0, b, 0, 2);
}

void Color::setAlpha(unsigned char alpha)
{
	setValues(0, 0, 0, alpha, 3);
}

string Color::toString() const
{
	string str = "(" + to_string(_r) + ", " + to_string(_g) + ", " + to_string(_b) + ", " + to_string(_alpha);

	return str;
}

string Color::toHex() const
{
	string hexstr;

	return hexstr;
}