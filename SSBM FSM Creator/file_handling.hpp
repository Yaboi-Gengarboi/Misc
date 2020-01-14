//SSBM FSM Creator
//file_handling.hpp
//Justyn P. Durnford
//Created on 12/24/2019
//Last Updated on 12/25/2019

#ifndef FILE_HANDLING_HPP
#define FILE_HANDLING_HPP

#include "FSM.hpp"

#include <vector>

//Checks if the txt file exists.
bool does_file_exist();

//Sorts FSM list.
void sort_FSMs(std::vector<FSM>& FSM_list);

//Reads FSMS from txt file and adds them to the FSM vector.
void read_FSMS_from_file(std::vector<FSM>& FSM_list, FSM& fsm);

//Takes all FSMS from the FSM vector and writes them to the txt file.
void write_FSMS_to_file(const std::vector<FSM>& FSM_list);

#endif //#ifndef FILE_HANDLING_HPP