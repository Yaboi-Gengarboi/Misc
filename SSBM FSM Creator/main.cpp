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

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <stdexcept>
using std::invalid_argument;

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
	Fl_Output* multiplier_label = nullptr;
	Fl_Input* multiplier_input = nullptr;
	Fl_Button* make_fsm_button = nullptr;
	Fl_Button* save_fsms_button = nullptr;
	Fl_Button* load_fsms_button = nullptr;
	Fl_Multiline_Output* fsm_output = nullptr;
	Fl_Multiline_Output* eng_output = nullptr;
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

vector<FSM> fsm_list;

/*void DEBUG()
{
	
}*/

void swapFSMs(FSM& a, FSM& b)
{
	FSM c = a;
	a = b;
	b = c;
}

void sortFSMs()
{
	if (fsm_list.size() < 2)
		return;

	bool loop = true;

	while (loop)
	{
		loop = false;

		for (unsigned long long i = 0; i < fsm_list.size() - 1; ++i)
		{

			if (compareFSMs(fsm_list[i], fsm_list[i + 1]))
			{
				swapFSMs(fsm_list[i], fsm_list[i + 1]);
				loop = true;
				break;
			}
			else if (fsm_list[i] == fsm_list[i + 1])
			{
				fsm_list.erase(fsm_list.begin() + i);
				loop = true;
				break;
			}
		}
	}
}

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

void showFSMs()
{
	string fsm_out;
	string eng_out;

	for (unsigned long long i = 0; i < fsm_list.size(); ++i)
	{
		if (i % 2 == 0 && i != 0)
			fsm_out += '\n';
		else if (i != 0)
			fsm_out += ' ';
		
		fsm_out += fsm_list[i].toHex();
	}

	gui.fsm_output->value(fsm_out.c_str());
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

	fsm_list.push_back(FSM(data.character, data.frame, data.subaction, data.multiplier));
	
	sortFSMs();
	showFSMs();


}

int main()
{
	init_characters();

	gui.window = new Fl_Window(700, 600, "SSBM FSM Creator");

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

	gui.multiplier_label = new Fl_Output(580, 50, 100, 30);
	gui.multiplier_label->value("Multiplier");
	gui.multiplier_input = new Fl_Input(580, 80, 100, 30);

	gui.make_fsm_button = new Fl_Button(20, 10, 100, 30, "Make FSM");
	gui.make_fsm_button->callback(make_fsm);

	gui.save_fsms_button = new Fl_Button(130, 10, 100, 30, "Save FSMs");
	gui.load_fsms_button = new Fl_Button(240, 10, 100, 30, "Load FSMs");

	gui.fsm_output = new Fl_Multiline_Output(20, 110, 330, 470);
	gui.eng_output = new Fl_Multiline_Output(350, 110, 330, 470);

	gui.window->end();
	gui.window->show();

	return Fl::run();
}