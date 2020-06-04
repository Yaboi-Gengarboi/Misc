// SSBM FSM Creator
// main.cpp
// Justyn Durnford
// Created on 5/4/2020
// Last updated on 6/3/2020

#define WIN32

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Button.H>

#include "FSM.hpp"

#include <string>
using std::string;
using std::to_string;
using std::getline;
using std::stoi;

#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;

struct GUI
{
	Fl_Window* window = nullptr;
	Fl_Output* character_label = nullptr;
	Fl_Input_Choice* character_choice = nullptr;
	Fl_Multiline_Output* output = nullptr;
};

GUI gui;

int main()
{
	// Load character data
	for (unsigned short i = 0; i < character_list.size(); ++i)
	{
		ifstream fin("Data/" + character_list[i]._name + ".txt");
		string line = "";
		string sub = "";
		unsigned short id = 0;

		while (fin.good())
		{
			getline(fin, line);
			id = stoi(line.substr(0, 5));
			sub = line.substr(6);
			character_list[i]._subList.push_back(Subaction(sub, id));
		}
	}

	gui.window = new Fl_Window(1200, 600, "SSBM FSM Creator");

	gui.character_label = new Fl_Output(20, 20, 200, 30);
	gui.character_label->value("Character");
	gui.character_choice = new Fl_Input_Choice(20, 50, 200, 30);
	for (unsigned char i = 0; i < character_list.size(); ++i)
	{
		gui.character_choice->add(character_list[i]._name.c_str());
	}

	gui.window->end();
	gui.window->show();

	return Fl::run();
}