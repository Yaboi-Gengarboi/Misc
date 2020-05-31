// SSBM FSM Creator
// main.cpp
// Justyn Durnford
// Created on 5/4/2020
// Last updated on 5/28/2020

#include "FSM.hpp"

#include <iostream>
using std::cout;
using std::endl;

int main()
{
	for (unsigned int i = 0; i < common_subaction_list.size(); ++i)
	{
		cout << common_subaction_list[i]._id << ' ';
		cout << common_subaction_list[i]._name << endl;
	}

	for (unsigned int i = 0; i < Donkey_Kong_subaction_list.size(); ++i)
	{
		cout << Donkey_Kong_subaction_list[i]._id << ' ';
		cout << Donkey_Kong_subaction_list[i]._name << endl;
	}

	return 0;
}