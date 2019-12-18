//Calculator_main.cpp
//Justyn P. Durnford
//Created on 12/6/2019
//Last Updated on 12/6/2019

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>

#include "Error.hpp"

int main()
{
	Fl_Window* main_window = new Fl_Window(300, 300);
	main_window->end();
	main_window->show();

	return Fl::run();
}