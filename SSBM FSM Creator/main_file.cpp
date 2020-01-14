//SSBM FSM Creator
//main_file.cpp
//Justyn P. Durnford
//Created on 12/17/2019
//Last Updated on 12/25/2019

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

#include <stdexcept>
using std::invalid_argument;

#include <algorithm>
using std::find;

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
Fl_Multiline_Output* fsm_output;

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

void add_FSM_button_callback(Fl_Widget* window)
{
	bool does_fsm_exist = false;

	if (strcmp(character_choice->value(), "") != 0 &&
		strcmp(subaction_choice->value(), "") != 0 &&
		strcmp(multiplier_input->value(), "") != 0 &&
		strcmp(frame_input->value(), "") != 0)
	{
		string str = "";
		str = character_choice->value();
		fsm.set_character(str);
		
		str = subaction_choice->value();
		fsm.set_subaction(str);

		str = multiplier_input->value();
		fsm.set_multiplier(str);

		str = frame_input->value();
		fsm.set_frame(str);

		fsm.set_string();

		if (fsm.get_multiplier() != -1.0f && fsm.get_frame() != -1)
		{
			for (size_t i = 0; i < FSM_list.size(); ++i)
			{
				string debug = fsm.to_str();
				fsm_output->value(debug.c_str());
				if (FSM_list[i].to_str() == fsm.to_str())
				{
					does_fsm_exist = true;
					break;
				}
			}

			if (!does_fsm_exist)
			{
				FSM_list.push_back(fsm);
				sort_FSMs(FSM_list);
				string FSM_list_str = "";

				for (size_t i = 0; i < FSM_list.size(); ++i)
				{
					if (i % 2 == 0 && i != 0)
						FSM_list_str += "\n";
					FSM_list_str += FSM_list[i].to_hex() + " ";
				}

				fsm_output->value(FSM_list_str.c_str());
			}
		}
	}
}

int main()
{
	for (int i = 146; i <= 299; ++i)
	{
		cout << "         \"";
		cout << subaction_names[i];
		cout << "\"," << endl;
	}

	return 0;
}