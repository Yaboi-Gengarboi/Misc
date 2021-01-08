// Decimal To Hex Converter
// main.cpp
// Justyn Durnford
// Created on 2021-01-07
// Last updated on 2021-01-07

#define WIN32

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Button.H>

#include <cstddef>
using std::size_t;

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::stoul;
using std::stof;
using std::to_string;

struct GUI
{
	Fl_Window* window = nullptr;
	Fl_Input* int_input = nullptr;
	Fl_Output* int_output = nullptr;
	Fl_Output* int_input_label = nullptr;
	Fl_Input* float_input = nullptr;
	Fl_Output* float_output = nullptr;
	Fl_Output* float_output_label = nullptr;
	Fl_Button* convert_button = nullptr;
};

GUI gui;

unsigned long ul_pow(unsigned long a, unsigned long n)
{
	unsigned long result = 1;

	for (unsigned long i = 0; i < n; ++i)
		result *= a;

	return result;
}

string to_hex(unsigned long i)
{
	string hexstr = "";
	unsigned char rem = 0;

	if (i == 0)
		return "0";

	while (i != 0)
	{
		rem = i % 16;

		switch (rem)
		{
			case 10:
				hexstr.insert(0, 1, 'A');
				break;

			case 11:
				hexstr.insert(0, 1, 'B');
				break;

			case 12:
				hexstr.insert(0, 1, 'C');
				break;

			case 13:
				hexstr.insert(0, 1, 'D');
				break;

			case 14:
				hexstr.insert(0, 1, 'E');
				break;

			case 15:
				hexstr.insert(0, 1, 'F');
				break;

			default:
				hexstr.insert(0, 1, rem + 48);
				break;
		}

		i /= 16;
	}

	return hexstr;
}

string to_hex(float f)
{
	unsigned long* pf = (unsigned long*)&f;
	return to_hex(*pf);
}

unsigned long to_decimal(const string& hexstr)
{
	unsigned long result = 0;
	const unsigned long size = hexstr.size();

	for (unsigned long i = size; i > 0; --i)
	{
		switch (hexstr[i - 1])
		{
			case '1':
				result += ul_pow(16, size - i);
				break;

			case '2':
				result += 2 * ul_pow(16, size - i);
				break;

			case '3':
				result += 3 * ul_pow(16, size - i);
				break;

			case '4':
				result += 4 * ul_pow(16, size - i);
				break;

			case '5':
				result += 5 * ul_pow(16, size - i);
				break;

			case '6':
				result += 6 * ul_pow(16, size - i);
				break;

			case '7':
				result += 7 * ul_pow(16, size - i);
				break;

			case '8':
				result += 8 * ul_pow(16, size - i);
				break;

			case '9':
				result += 9 * ul_pow(16, size - i);
				break;

			case 'A':
				result += 10 * ul_pow(16, size - i);
				break;

			case 'B':
				result += 11 * ul_pow(16, size - i);
				break;

			case 'C':
				result += 12 * ul_pow(16, size - i);
				break;

			case 'D':
				result += 13 * ul_pow(16, size - i);
				break;

			case 'E':
				result += 14 * ul_pow(16, size - i);
				break;

			case 'F':
				result += 15 * ul_pow(16, size - i);
				break;

			default:
				break;
		}
	}

	return result;
}

void convert(Fl_Widget* widget)
{
	try
	{
		string str = gui.int_input->value();
		unsigned long i = stoul(str);
		string hexstr = to_hex(i);
		gui.int_output->value(hexstr.c_str());
	}
	catch (...) {}

	try
	{
		string str = gui.float_input->value();
		float f = stof(str);
		string hexstr = to_hex(f);
		gui.float_output->value(hexstr.c_str());
	}
	catch (...) {}
}

int main()
{
	gui.window = new Fl_Window(340, 150, "Decimal To Hex Converter");

	gui.int_input_label = new Fl_Output(20, 20, 100, 30);
	gui.int_input_label->value("Integer");
	gui.int_input = new Fl_Input(120, 20, 100, 30);
	gui.int_output = new Fl_Output(220, 20, 100, 30);

	gui.float_output_label = new Fl_Output(20, 50, 100, 30);
	gui.float_output_label->value("Float");
	gui.float_input = new Fl_Input(120, 50, 100, 30);
	gui.float_output = new Fl_Output(220, 50, 100, 30);

	gui.convert_button = new Fl_Button(130, 100, 80, 30, "Convert");
	gui.convert_button->callback(convert);

	gui.window->end();
	gui.window->show();

	return Fl::run();
}