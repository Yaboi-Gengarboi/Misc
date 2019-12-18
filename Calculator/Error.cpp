//Functions.hpp
//Justyn P. Durnford
//Created on 12/6/2019
//Last Updated on 12/6/2019

#include "Error.hpp"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>

#include <string>
using std::string;

void callback(Fl_Widget* window)
{
	window->hide();
}

void displayError(const string& message)
{
	Fl_Window* error_window = new Fl_Window(300, 60);
	Fl_Output* error_output = new Fl_Output(20, 15, 260, 30);

	error_output->value(message.c_str());
	error_window->callback(callback);
	error_window->end();
	error_window->show();
}