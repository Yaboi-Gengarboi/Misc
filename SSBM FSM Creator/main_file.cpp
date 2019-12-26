//SSBM FSM Creator
//main_file.cpp
//Justyn P. Durnford
//Created on 12/17/2019
//Last Updated on 12/24/2019

#include "FSM.hpp"
#include "error_handling.hpp"
#include "file_handling.hpp"

#define WIN32
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Box.h>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Button.H>
#include <Fl/Fl_Input_Choice.H>
#include <Fl/Fl_Widget.H>
#include <FL/fl_ask.H>

#include <string>
using std::string;
using std::to_string;
using std::stoi;
using std::stof;

#include <cstring>
using std::strcmp;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;

#include <iostream>
using std::cout;
using std::endl;

vector<FSM> FSM_list;
FSM fsm;

//
int subaction_character_range[] = { 0, 0 };
Fl_Input_Choice* character_choice;
Fl_Input_Choice* subaction_choice;
Fl_Input* multiplier_input;
Fl_Input* frame_input;

//Allows the window to close
void window_callback(Fl_Widget* window)
{
	if (fl_ask("Do you really want to quit?"))
		exit(0);
}

void character_choice_callback(Fl_Widget* window)
{
	subaction_choice->clear();

	for (size_t i = 0; i < characters.size(); ++i)
	{
		if (strcmp(character_choice->value(), characters[i].c_str()) == 0)
		{
			subaction_character_range[0] = character_subaction_indexes[i].first;
			subaction_character_range[1] = character_subaction_indexes[i].second;
		}
	}

	for (size_t i = 0; i < 54; ++i)
		subaction_choice->add(subaction_names[i].c_str());

	for (size_t i = subaction_character_range[0];
		 i <= subaction_character_range[1]; ++i)
	{
		subaction_choice->add(subaction_names[i].c_str());
	}
}

int main()
{
	/*
	Fl_Window* window = new Fl_Window(800, 400);

	Fl_Box* character_box = new Fl_Box(20, 20, 140, 30, "Character");;
	character_choice = new Fl_Input_Choice(20, 50, 140, 30);
	for (string str : characters)
		character_choice->add(str.c_str());
	character_choice->callback(character_choice_callback);


	Fl_Box* subaction_box = new Fl_Box(160, 20, 300, 30, "Subaction");
	subaction_choice = new Fl_Input_Choice(160, 50, 300, 30);
	
	window->callback(window_callback);

	window->end();
	window->show();
	return Fl::run();
	*/

	read_FSMS_from_file(FSM_list, fsm);
	for (size_t i = 0; i < FSM_list.size(); ++i)
	{
		cout << FSM_list[i].to_str() << endl;
	}

	return 0;
}