/*
FSM.cpp
Justyn P. Durnford
Created on 10/24/2019
Last updated on 11/9/2019
*/

#include <iostream>
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
using std::string;
using std::stringstream;
using std::vector;

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

unsigned short int getCharacter(const string& in)
{
	if (in == "Repeat")
	{

		return 0;
	}
	if (in == "Quit")
	{

		return 0;
	}
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
	if (in == "All") return 0;
	else
	{

	}
	return 0;
}

unsigned short int getAction(const string& in)
{
	if (in == "Repeat")
	{

		return 0;
	}
	if (in == "Quit")
	{

		return 0;
	}
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

	}
	return 0;
}

/*

*/
struct FSM
{
	unsigned short int character;
	unsigned short int frame;
	unsigned short int action;
	float multiplier;
	string hexStr;
	string engStr;
};

/*

*/
FSM createFSM(unsigned short int character,
	unsigned short int frame,
	unsigned short int action,
	float multiplier)
{
	stringstream stream;
	string hexStr = "";

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

}

/*

*/
void printFSMVectorHex(const vector<FSM>& fsmVec)
{
	for (FSM fsm : fsmVec)
		cout << fsm.hexStr << endl;
}

/*

*/
void printFSMVectorEng(const vector<FSM>& fsmVec)
{
	for (FSM fsm : fsmVec)
		cout << fsm.engStr << endl;
}

/*

*/
string getInput()
{
	string str = "";
	getline(cin, str);
	return str;
}

/*

*/
unsigned short int getCharacter()
{
	unsigned short int ch = 0;
	bool cont = true;
	string str;

	while (cont)
	{
		str = getInput();
		for (unsigned short i = 0; i < characters.size(); ++i)
		{
			if (str.compare(characters[i]) == 0)
			{
				ch = i;
				cont = false;
			}
		}
		if (cont)
		{
			cout << "Invalid input. Try again." << endl;
		}
	}
	
	return ch;
}

int main()
{
	//unsigned short int ch;
	//bool cont = true;
	//while (cont)
	//{

	//}
	
	//cout << "Enter a character. Valid characters include: " << endl;
	//for (string character : characters)
		//cout << character << endl;
	//ch = getCharacter();
	//cout << ch << endl;

	cout << floatToHex(1.0);

	return 0;
}