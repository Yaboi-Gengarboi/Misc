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

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::istringstream;
using std::vector;

vector<string> characters =
{
	"Captain Falcon",
	"Bowser"
};

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
	unsigned short int ch;
	//bool cont = true;
	//while (cont)
	//{

	//}
	
	cout << "Enter a character. Valid characters include: " << endl;
	for (string character : characters)
		cout << character << endl;
	ch = getCharacter();
	cout << ch << endl;

	

	return 0;
}