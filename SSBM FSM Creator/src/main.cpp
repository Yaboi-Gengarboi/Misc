// SSBM FSM Creator
// main.cpp
// Justyn Durnford
// Created on 2020-05-04
// Last updated on 2021-01-04

#define WIN32

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Button.H>

#include "Data.h"

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
	uint8_t frame = 0;
	Subaction subaction;
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
		if (character_list[i].name == character)
		{
			auto iter = character_list[i].subList.begin();
			while (iter != character_list[i].subList.end())
			{
				gui.subaction_choice->add(iter->second.name.c_str());
				++iter;
			}

			gui.subaction_choice->value("");
			return;
		}
	}
}

void show_fsms()
{
	array<vector<string>, 2> str_arr = fsm_list_strings();

	string hex_str;
	string eng_str;

	for (size_t i = 0; i < str_arr[0].size(); ++i)
	{
		if (i % 2 == 0)
			hex_str += str_arr[0][i] + ' ';
		else
			hex_str += str_arr[0][i] + '\n';
	}

	for (size_t i = 0; i < str_arr[1].size(); ++i)
		eng_str += str_arr[1][i] + '\n';

	gui.fsm_output->value(hex_str.c_str());
	gui.eng_output->value(eng_str.c_str());
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
			if (character_str == character_list[i].name)
				data.character = character_list[i];
		}
	}
	else return;

	if (!subaction_str.empty())
	{
		auto iter = data.character.subList.begin();
		bool found = false;
		while (iter != data.character.subList.end() && !found)
		{
			if (subaction_str == iter->second.name)
			{
				data.subaction = iter->second;
				found = true;
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
				data.frame = uint8_t(i);
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

	fsm_list[data.character.id].push_back(FSM(data.character, data.frame, data.subaction, data.multiplier));
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

void load_fsms(Fl_Widget* widget)
{
	if (is_fsm_file_read)
		return;

	if (read_fsms())
		show_fsms();

	is_fsm_file_read = true;
}

int main()
{
	init_characters();

	gui.window = new Fl_Window(760, 600, "SSBM FSM Creator");

	gui.character_label = new Fl_Output(20, 50, 180, 30);
	gui.character_label->value("Character");
	gui.character_choice = new Fl_Input_Choice(20, 80, 180, 30);
	for (unsigned char i = 0; i < character_list.size(); ++i)
	{
		gui.character_choice->add(character_list[i].name.c_str());
	}
	gui.character_choice->callback(set_subaction_list);

	gui.subaction_label = new Fl_Output(200, 50, 290, 30);
	gui.subaction_label->value("Subaction");
	gui.subaction_choice = new Fl_Input_Choice(200, 80, 290, 30);

	gui.frame_label = new Fl_Output(490, 50, 100, 30);
	gui.frame_label->value("Frame");
	gui.frame_input = new Fl_Input(490, 80, 100, 30);

	gui.multiplier_label = new Fl_Output(590, 50, 150, 30);
	gui.multiplier_label->value("Multiplier");
	gui.multiplier_input = new Fl_Input(590, 80, 150, 30);

	gui.make_fsm_button = new Fl_Button(20, 10, 100, 30, "Make FSM");
	gui.make_fsm_button->callback(make_fsm);

	gui.save_fsms_button = new Fl_Button(130, 10, 100, 30, "Save FSMs");
	gui.save_fsms_button->callback(save_fsms);

	gui.load_fsms_button = new Fl_Button(240, 10, 100, 30, "Load FSMs");
	gui.load_fsms_button->callback(load_fsms);

	gui.fsm_output = new Fl_Multiline_Output(20, 110, 290, 470);
	gui.fsm_output->textfont(FL_HELVETICA);

	gui.eng_output = new Fl_Multiline_Output(310, 110, 430, 470);

	gui.window->end();
	gui.window->show();

	gui.second_window = new Fl_Window(300, 200);
	gui.second_output = new Fl_Multiline_Output(10, 10, 280, 100);

	gui.second_window->end();

	return Fl::run();
}