/*
FSM.cpp
Justyn P. Durnford
Created on 10/24/2019
Last updated on 11/9/2019
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::transform;
using std::hex;
using std::sort;
using std::stoi;
using std::stof;
using std::to_string;
using std::ifstream;
using std::ofstream;
using std::string;
using std::ostringstream;
using std::vector;

const string characters[] =
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

const string actions[] =
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

/*

*/
struct FSM
{
	unsigned int character;
	unsigned int frame;
	unsigned int action;
	float multiplier;
	string hexStr;
	string engStr;
};

/*

*/
FSM createFSM(unsigned int character,
	unsigned int frame,
	unsigned int action,
	float multiplier, 
	string engStr)
{
	string hexStr;
	ostringstream stream;

	if (character < 16)
		stream << "0";
	stream << hex << character;

	if (frame < 16)
		stream << "0";
	stream << hex << frame;

	stream << 8;
	if (action < 256)
		stream << "0";
	if (action < 16)
		stream << "0";
	stream << hex << action;

	stream << " ";

	int* pMult = (int*)&multiplier;
	stream << hex << *pMult;
	hexStr = stream.str();

	transform(hexStr.begin(), hexStr.end(), hexStr.begin(), ::toupper);

	FSM newFSM{ character, frame, action, multiplier, hexStr, engStr };
	return newFSM;
}

unsigned int getCharacter(const string& in)
{
	if (in == "Captain Falcon") return 0;
	if (in == "Donkey Kong") return 1;
	if (in == "Fox") return 2;
	if (in == "Game&Watch") return 3;
	if (in == "Kirby") return 4;
	if (in == "Bowser") return 5;
	if (in == "Link") return 6;
	if (in == "Luigi") return 7;
	if (in == "Mario") return 8;
	if (in == "Marth") return 9;
	if (in == "Mewtwo") return 10;
	if (in == "Ness") return 11;
	if (in == "Peach") return 12;
	if (in == "Pikachu") return 13;
	if (in == "Ice Climbers") return 14;
	if (in == "Jigglypuff") return 15;
	if (in == "Samus") return 16;
	if (in == "Yoshi") return 17;
	if (in == "Zelda") return 18;
	if (in == "Sheik") return 19;
	if (in == "Falco") return 20;
	if (in == "Young Link") return 21;
	if (in == "Dr. Mario") return 22;
	if (in == "Roy") return 23;
	if (in == "Pichu") return 24;
	if (in == "Ganondorf") return 25;
	if (in == "Popo") return 26;
	if (in == "All") return 255;
	else
	{
		cout << "Invalid input. Try again" << endl;
	}
	return 256;
}

unsigned int getAction(const string& in)
{
	if (in == "Spot Dodge") return 41;
	if (in == "Forward Roll") return 42;
	if (in == "Back Roll") return 43;
	if (in == "Air Dodge") return 44;
	if (in == "Jab 1") return 46;
	if (in == "Jab 2") return 47;
	if (in == "Jab 3") return 48;
	if (in == "Rapid Jab Start") return 49;
	if (in == "Rapid Jab Loop") return 50;
	if (in == "Rapid Jab End") return 51;
	if (in == "Dash Attack") return 52;
	if (in == "Side Tilt High") return 53;
	if (in == "Side Tilt Midhigh") return 54;
	if (in == "Side Tilt Middle") return 55;
	if (in == "Side Tilt Midlow") return 56;
	if (in == "Side Tilt Low") return 57;
	if (in == "Up Tilt") return 58;
	if (in == "Down Tilt") return 59;
	if (in == "Side Smash High") return 60;
	if (in == "Side Smash Midhigh") return 61;
	if (in == "Side Smash Middle") return 62;
	if (in == "Side Smash Midlow") return 63;
	if (in == "Side Smash Low") return 64;
	if (in == "Up Smash") return 66;
	if (in == "Down Smash") return 67;
	if (in == "Neutral Aerial") return 68;
	if (in == "Forward Aerial") return 69;
	if (in == "Back Aerial") return 70;
	if (in == "Up Aerial") return 71;
	if (in == "Down Aerial") return 72;
	if (in == "Neutral Tech") return 199;
	if (in == "Forward Tech") return 200;
	if (in == "Back Tech") return 201;
	if (in == "Wall Tech") return 202;
	if (in == "Wall Jump Tech") return 203;
	if (in == "Ceiling Tech") return 204;
	if (in == "Ledge Getup Slow") return 219;
	if (in == "Ledge Getup Fast") return 220;
	if (in == "Ledge Attack Slow") return 221;
	if (in == "Ledge Attack Fast") return 222;
	if (in == "Ledge Roll Slow") return 223;
	if (in == "Ledge Roll Fast") return 224;
	if (in == "Ledge Jump 1 Slow") return 225;
	if (in == "Ledge Jump 2 Slow") return 226;
	if (in == "Ledge Jump 1 Fast") return 227;
	if (in == "Ledge Jump 2 Fast") return 228;
	if (in == "Left Taunt") return 239;
	if (in == "Right Taunt") return 240;
	if (in == "Grab") return 242;
	if (in == "Dash Grab") return 243;
	if (in == "Forward Throw") return 247;
	if (in == "Back Throw") return 248;
	if (in == "Up Throw") return 249;
	if (in == "Down Throw") return 250;
	else
	{
		cout << "Invalid input. Try again" << endl;
	}
	return 256;
}

bool compareFSM(const FSM& A, const FSM& B)
{
	if (A.character > B.character)
		return true;
	if (A.character == B.character)
	{
		if (A.frame > B.frame)
			return true;
		if (A.frame == B.frame)
		{
			if (A.action > B.action)
				return true;
		}
	}

	return false;
}

/*

*/
void printFSMVectorHex(vector<FSM>& vec)
{
	sort(vec.rbegin(), vec.rend(), compareFSM);
	for (FSM fsm : vec)
		cout << fsm.hexStr << endl;
}

/*

*/
void printFSMVectorEng(vector<FSM>& vec)
{
	sort(vec.rbegin(), vec.rend(), compareFSM);
	for (FSM fsm : vec)
		cout << fsm.engStr << endl;
}

/*
*/
void writeFSMsToFile(const vector<string>& fsmList)
{
	string line;
	string fsm;
	ifstream fin;
	bool cont = true;

	//Check if file exists
	if (fin) //Get FSMs from file
	{
		while (cont)
		{
			getline(fin, line);
			if (line.empty())
				cont = false;
			else
			{

			}
		}
	}
	else //Go ahead and create new file
	{

	}
}


/*

*/
string getInput()
{
	string str = "";
	getline(cin, str);
	return str;
}

int main()
{
	//ofstream fout("FSM.txt");
	//ifstream fin("FSM.txt");

	vector<FSM> fsmList;

	unsigned int character = 256;
	unsigned int frame = 256;
	unsigned int action = 256;
	float multiplier = 0.0;
	string engStr;

	bool cont = true;
	int dummy = 0;
	float dummy2 = 0.0;
	string temp = "";

	string in = "";

	while (cont)
	{
		cout << "Enter \"Make FSM\" to create a FSM" << endl;
		cout << "Enter \"Print FSMs\" to print your FSMs" << endl;
		cout << "Enter \"Quit\" to quit" << endl;
		in = getInput();

		if (in == "Print FSMs")
		{
			printFSMVectorHex(fsmList);
			printFSMVectorEng(fsmList);
			cout << endl;
		}
		else if (in == "Quit")
		{
			cont = false;
		}
		else if (in == "Make FSM")
		{
			in = "";
			character = 256;
			frame = 256;
			action = 256;
			multiplier = 0.0;
			engStr = "";
			//256 = Retry

			while (character == 256)
			{
				cout << "Enter a character. Valid characters are:" << endl;
				for (unsigned int i = 0; i < 27; ++i)
					cout << characters[i] << endl;
				in = getInput();
				character = getCharacter(in);
				cout << endl;
			}
			engStr += in;
			engStr += ", ";

			while (action == 256)
			{
				cout << "Enter an action. Valid actions are:" << endl;
				for (unsigned int i = 0; i < 27; ++i)
					cout << actions[i] << endl;
				in = getInput();
				action = getAction(in);
				cout << endl;
			}
			engStr += in;
			engStr += ", ";

			while (frame == 256)
			{
				cout << "Enter a frame" << endl;
				in = getInput();

				try
				{
					dummy = stoi(in, nullptr);
					if (dummy < 0)
					{
						cout << "Invalid input. Try again" << endl;
						frame = 256;
					}
					else
						frame = dummy;
				}
				catch (const std::invalid_argument& error)
				{
					cout << "Invalid input. Try again" << endl;
					frame = 256;
				}

				cout << endl;
			}
			engStr += "Frame ";
			engStr += to_string(frame);
			engStr += " @ ";

			while (multiplier <= 0.0f)
			{
				cout << "Enter a multiplier" << endl;
				in = getInput();

				try
				{
					dummy2 = stof(in, nullptr);
					if (dummy2 <= 0.0f)
					{
						cout << "Invalid input. Try again" << endl;
						multiplier = 0.0f;
					}
					else
						multiplier = dummy2;
				}
				catch (const std::invalid_argument & error)
				{
					cout << "Invalid input. Try again" << endl;
					multiplier = 0.0f;
				}

				cout << endl;
			}
			engStr += to_string(multiplier);
			fsmList.push_back(createFSM(character, frame, action, multiplier, engStr));
		}
	}
	
	


	return 0;
}