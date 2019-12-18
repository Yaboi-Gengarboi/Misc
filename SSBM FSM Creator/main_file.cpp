//SSBM FSM Creator
//main_file.cpp
//Justyn P. Durnford
//Created on 12/17/2019
//Last Updated on 12/17/2019

#include "FSM.hpp"

#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
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

#include <vector>
using std::vector;

#include <memory>
using std::unique_ptr;
using std::make_unique;

vector<string> characters =
{
	"Captain Falcon", "Donkey Kong", "Fox",
	"Game&Watch", "Kirby", "Bowser",
	"Link", "Luigi", "Mario",
	"Marth", "Mewtwo", "Ness",
	"Peach", "Pikachu", "Ice Climbers",
	"Jigglypuff", "Samus", "Yoshi",
	"Zelda", "Sheik", "Falco",
	"Young Link", "Dr. Mario", "Roy",
	"Pichu", "Ganondorf", "Popo"
};

vector<string> actions =
{
	"Spot Dodge", "Forward Roll", "Back Roll",
	"Air Dodge", "Jab 1", "Jab 2", "Jab 3",
	"Rapid Jab Start", "Rapid Jab Loop",
	"Rapid Jab End", "Dash Attack",
	"Side Tilt High", "Side Tilt Midhigh",
	"Side Tilt Middle", "Side Tilt Midlow",
	"Side Tilt Low", "Up Tilt", "Down Tilt",
	"Side Smash High", "Side Smash Midhigh",
	"Side Smash Middle", "Side Smash Midlow",
	"Side Smash Low", "Up Smash", "Down Smash",
	"Neutral Aerial", "Foward Aerial", "Back Aerial",
	"Up Aerial", "Down Aerial", "Neutral Tech",
	"Forward Tech", "Back Tech", "Wall Tech",
	"Wall Jump Tech", "Ceiling Tech",
	"Ledge Getup Slow", "Ledge Getup Fast",
	"Ledge Attack Slow", "Ledge Attack Fast",
	"Ledge Roll Slow", "Ledge Roll Fast",
	"Ledge Jump 1 Slow", "Ledge Jump 2 Slow",
	"Ledge Jump 1 Fast", "Ledge Jump 2 Fast",
	"Left Taunt", "Right Taunt",
	"Grab", "Dash Grab", "Forward Throw",
	"Back Throw", "Up Throw", "Down Throw"
};

vector<FSM> fsmList;

int main()
{
	return 0;
}