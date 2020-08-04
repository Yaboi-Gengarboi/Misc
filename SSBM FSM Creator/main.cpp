// SSBM FSM Creator
// main.cpp
// Justyn Durnford
// Created on 5/4/2020
// Last updated on 8/2/2020

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
using std::stof;

#include <vector>
using std::vector;

#include <stdexcept>
using std::invalid_argument;
struct GUI
{
	Fl_Window* window = nullptr;
	Fl_Output* character_label = nullptr;
	Fl_Input_Choice* character_choice = nullptr;
	Fl_Output* subaction_label = nullptr;
	Fl_Input_Choice* subaction_choice = nullptr;
	Fl_Output* frame_label = nullptr;
	Fl_Input* frame_input = nullptr;
	Fl_Output* multiplier_label = nullptr;
	Fl_Input* multiplier_input = nullptr;
	Fl_Button* make_fsm_button = nullptr;
	Fl_Button* save_fsms_button = nullptr;
	Fl_Button* load_fsms_button = nullptr;
	Fl_Multiline_Output* fsm_output = nullptr;
	Fl_Multiline_Output* eng_output = nullptr;

	Fl_Window* second_window = nullptr;
	Fl_Multiline_Output* second_output = nullptr;
	Fl_Button* yes_button = nullptr;
	Fl_Button* no_button = nullptr;
};

struct DATA
{
	Character character;
	Subaction subaction;
	unsigned char frame = 0;
	float multiplier = 0;
};

GUI gui;
DATA data;
bool is_fsm_file_read = false;

/*void DEBUG()
{
	
}*/

void set_subaction_list(Fl_Widget* widget)
{
	string character(gui.character_choice->value());

	if (character.empty())
		return;

	gui.subaction_choice->clear();

	for (unsigned char i = 0; i < character_list.size(); ++i)
	{
		if (character_list[i].name() == character)
		{
			auto iter = character_list[i].subList().begin();
			while (iter != character_list[i].subList().end())
			{
				gui.subaction_choice->add(iter->second.name().c_str());
				++iter;
			}

			gui.subaction_choice->value("");
			return;
		}
	}
}

void show_fsms()
{
	vector<string> str_vec = fsm_list_strings();

	gui.fsm_output->value(str_vec[0].c_str());
	gui.eng_output->value(str_vec[1].c_str());
}

void make_fsm(Fl_Widget* widget)
{
	string character_str(gui.character_choice->value());
	string subaction_str(gui.subaction_choice->value());
	string frame_str(gui.frame_input->value());
	string multiplier_str(gui.multiplier_input->value());

	if (!character_str.empty())
	{
		for (unsigned char i = 0; i < character_list.size(); ++i)
		{
			if (character_str == character_list[i].name())
			{
				data.character = character_list[i];
				break;
			}
		}
	}
	else return;

	if (!subaction_str.empty())
	{
		auto iter = data.character.subList().begin();
		while (iter != data.character.subList().end())
		{
			if (subaction_str == iter->second.name())
			{
				data.subaction = iter->second;
				break;
			}
			++iter;
		}
	}
	else return;

	if (!frame_str.empty())
	{
		try
		{
			int i = stoi(frame_str);

			if (i >= 0 && i <= 255)
				data.frame = unsigned char(i);
			else return;
		}
		catch (const invalid_argument& ia)
		{
			return;
		}
	}
	else return;

	if (!multiplier_str.empty())
	{
		try
		{
			float f = stof(multiplier_str);

			if (f > 0)
				data.multiplier = f;
			else return;
		}
		catch (const invalid_argument& ia)
		{
			return;
		}
	}
	else return;

	add_fsm(data.character, data.frame, data.subaction, data.multiplier);
	sort_fsm_list();
	show_fsms();
}

void save_fsms(Fl_Widget* widget)
{
	if (!is_fsm_file_read && !is_fsm_file_empty())
	{
		gui.second_output->value("There are unloaded FSMs. Would you like to ignore and overwrite them?");

		gui.second_window->show();
	}

	write_fsms();
}

int main()
{
	init_characters();

	gui.window = new Fl_Window(750, 600, "SSBM FSM Creator");

	gui.character_label = new Fl_Output(20, 50, 180, 30);
	gui.character_label->value("Character");
	gui.character_choice = new Fl_Input_Choice(20, 80, 180, 30);
	for (unsigned char i = 0; i < character_list.size(); ++i)
	{
		gui.character_choice->add(character_list[i].name().c_str());
	}
	gui.character_choice->callback(set_subaction_list);

	gui.subaction_label = new Fl_Output(200, 50, 280, 30);
	gui.subaction_label->value("Subaction");
	gui.subaction_choice = new Fl_Input_Choice(200, 80, 280, 30);

	gui.frame_label = new Fl_Output(480, 50, 100, 30);
	gui.frame_label->value("Frame");
	gui.frame_input = new Fl_Input(480, 80, 100, 30);

	gui.multiplier_label = new Fl_Output(580, 50, 150, 30);
	gui.multiplier_label->value("Multiplier");
	gui.multiplier_input = new Fl_Input(580, 80, 150, 30);

	gui.make_fsm_button = new Fl_Button(20, 10, 100, 30, "Make FSM");
	gui.make_fsm_button->callback(make_fsm);

	gui.save_fsms_button = new Fl_Button(130, 10, 100, 30, "Save FSMs");
	gui.save_fsms_button->callback(save_fsms);

	gui.load_fsms_button = new Fl_Button(240, 10, 100, 30, "Load FSMs");

	gui.fsm_output = new Fl_Multiline_Output(20, 110, 280, 470);
	gui.fsm_output->textfont(FL_HELVETICA);

	gui.eng_output = new Fl_Multiline_Output(300, 110, 430, 470);

	gui.window->end();
	gui.window->show();

	gui.second_window = new Fl_Window(300, 200);
	gui.second_output = new Fl_Multiline_Output(10, 10, 280, 100);

	gui.second_window->end();

	return Fl::run();
}