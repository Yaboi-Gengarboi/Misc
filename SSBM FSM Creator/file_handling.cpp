//SSBM FSM Creator
//file_handling.cpp
//Justyn P. Durnford
//Created on 12/24/2019
//Last Updated on 12/24/2019

#include "file_handling.hpp"
#include "FSM.hpp"

#include <vector>
using std::vector;

#include <string>
using std::string;
using std::getline;

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::endl;

bool does_file_exist()
{
	ifstream txt_file_ifstream("FSM_file.txt");
	return txt_file_ifstream.good();
}

void read_FSMS_from_file(vector<FSM>& FSM_list, FSM& fsm)
{
	if (does_file_exist())
	{
		ifstream txt_file_ifstream("FSM_file.txt");
		string line = "";
		string fsm_str = "";
		int begin = 0;
		int end = 0;

		while (line != "-------Hex-------")
		{
			getline(txt_file_ifstream, line);

			if (line != "-------Hex-------" && line != "-----English-----")
			{
				fsm_str = line;

				end = fsm_str.find(',', begin);
				fsm.set_character(fsm_str.substr(begin, end));

				begin = end + 2;
				end = fsm_str.find(',', begin);
				fsm.set_subaction(fsm_str.substr(begin, end));

				begin = end + 3;
				end = fsm_str.find(',', begin);
				fsm.set_multiplier(fsm_str.substr(begin, end));

				begin = end + 2;
				fsm.set_frame(fsm_str.substr(begin));

				FSM_list.push_back(fsm);
			}
		}
	}
}

void write_FSMS_to_file(const vector<FSM>& FSM_list)
{
	ofstream txt_file_ofstream("FSM_file.txt");
	txt_file_ofstream << "-----English-----" << endl;

	for (const FSM& fsm : FSM_list)
		txt_file_ofstream << fsm.to_str() << endl;

	txt_file_ofstream << "-------Hex-------" << endl;

	for (const FSM& fsm : FSM_list)
		txt_file_ofstream << fsm.to_hex() << endl;
}