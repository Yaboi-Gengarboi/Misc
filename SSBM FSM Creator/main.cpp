// SSBM FSM Creator
// main.cpp
// Justyn Durnford
// Created on 5/4/2020
// Last updated on 8/1/2020

#define WIN32

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Button.H>

#include "FSM.h"
#include "Subaction.h"
#include "Character.h"
#include "Data.h"
#include "Tools.h"

#include <string>
using std::string;
using std::to_string;
using std::getline;
using std::stoi;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <stdexcept>
using std::out_of_range;

#include <iostream>
using std::cout;
using std::endl;

struct GUI
{
	Fl_Window* window = nullptr;
	Fl_Output* character_label = nullptr;
	Fl_Input_Choice* character_choice = nullptr;
	Fl_Output* subaction_label = nullptr;
	Fl_Input_Choice* subaction_choice = nullptr;
	Fl_Output* frame_label = nullptr;
	Fl_Input* frame_input = nullptr;
	Fl_Multiline_Output* output = nullptr;
};

struct DATA
{
	Character current_character;
	Subaction current_subaction;
	unsigned char current_frame = 0;
	float current_multiplier = 0;
};

GUI gui;
DATA data;

void set_subaction_list(Fl_Widget* widget)
{
	string character = gui.character_choice->value();

	if (character.empty())
		return;

	for (unsigned char i = 0; i < character_list.size(); ++i)
	{
		if (character_list[i].name() == character)
		{
			gui.subaction_choice->clear();
			for (unsigned short p = 0; p < character_list[i].subListSize(); ++p)
			{
				try
				{
					gui.subaction_choice->add(character_list[i].subList(p).name().c_str());
				}
				catch (const out_of_range& oor) { /* Subaction does not exist with id p. */ }
			}

			return;
		}
	}
}

int main()
{
	init_characters();

	gui.window = new Fl_Window(1200, 600, "SSBM FSM Creator");

	gui.character_label = new Fl_Output(20, 20, 200, 30);
	gui.character_label->value("Character");
	gui.character_choice = new Fl_Input_Choice(20, 50, 200, 30);
	for (unsigned char i = 0; i < character_list.size(); ++i)
	{
		gui.character_choice->add(character_list[i].name().c_str());
	}
	gui.character_choice->callback(set_subaction_list);

	gui.subaction_label = new Fl_Output(220, 20, 200, 30);
	gui.subaction_label->value("Subaction");
	gui.subaction_choice = new Fl_Input_Choice(220, 50, 200, 30);

	gui.frame_label = new Fl_Output(420, 20, 200, 30);
	gui.frame_label->value("Frame");
	gui.frame_input = new Fl_Input(420, 50, 200, 30);

	gui.window->end();
	gui.window->show();

	return Fl::run();
}