// Color.h
// Justyn Durnford
// Created on 2020-04-17
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

#ifndef COLOR_H
#define COLOR_H

#include <ostream>
#include <string>

class Color
{
	unsigned char _r = 0;
	unsigned char _g = 0;
	unsigned char _b = 0;
	unsigned char _alpha = 0;

	void setValues(unsigned char r, unsigned char g, unsigned char b, unsigned char alpha, char set);

	public:

	static const unsigned char MAX = 255;

	// Constructors.
	Color() = default;
	Color(const Color& c) = default;
	Color(Color&& c) = default;
	Color(unsigned char r, unsigned char g, unsigned char b);
	Color(unsigned char r, unsigned char g, unsigned char b, unsigned char alpha);
	Color(unsigned char arr[4]);

	// Assignment operators.
	Color& operator = (const Color& c) = default;
	Color& operator = (Color&& c) = default;

	// Destructor.
	~Color() = default;

	unsigned char red() const;

	unsigned char green() const;

	unsigned char blue() const;

	unsigned char alpha() const;

	void setRed(unsigned char r);

	void setGreen(unsigned char g);

	void setBlue(unsigned char b);

	void setAlpha(unsigned char alpha);

	void setAll(unsigned char r, unsigned char g, unsigned char b, unsigned char alpha);

	std::string toString() const;

	std::string toHex() const;
};

bool operator == (const Color& c1, const Color& c2);

bool operator != (const Color& c1, const Color& c2);

std::ostream& operator << (std::ostream& os, const Color& c);

#endif // COLOR_HPP