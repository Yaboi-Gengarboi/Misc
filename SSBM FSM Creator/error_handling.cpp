//SSBM FSM Creator
//error_handling.cpp
//Justyn P. Durnford
//Created on 12/17/2019
//Last Updated on 12/17/2019

#include "error_handling.hpp"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Multiline_Output.H>

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