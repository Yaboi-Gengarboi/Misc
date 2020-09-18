// RPGGame
// main.cpp
// Justyn Durnford
// Created on 2020-04-27
// Last updated on 2020-09-17

#include "Ability.h"
#include "Data.h"
#include "Matrix.h"
#include "Random.h"
#include "Type.h"

#include <array>
using std::array;

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::to_string;
using std::getline;

array<Type, 18> type_arr;

Matrix<float> type_matchups(18, 18);

bool init()
{
    string line;
    ifstream fin("Data/typedata.txt");

    for (int i = 0; i < 18; ++i)
    {
        getline(fin, line);
        type_arr[i] = Type(hex_to_long(line.substr(0, 2)), hex_to_eng(line.substr(2)));
    }

// 0  : Normal    { 1,   1,   1,   1,   1,  .5,   1,   0,  .5,   1,   1,   1,   1,   1,   1,   1,   1,   1 }
// 1  : Fighting  { 2,   1,  .5,  .5,   1,   2,  .5,   0,   2,   1,   1,   1,   1,  .5,   2,   1,   2,  .5 }
// 2  : Flying    { 1,   2,   1,   1,   1,  .5,   2,   1,  .5,   1,   1,   2,  .5,   1,   1,   1,   1,   1 }
// 3  : Poison    { 1,   1,   1,  .5,  .5,  .5,   1,  .5,   0,   1,   2,   2,   1,   1,   1,   1,   1,   2 }
// 4  : Ground    { 1,   1,   0,   2,   1,   2,  .5,   1,   2,   2,   1,  .5,   2,   1,   1,   1,   1,   1 }
// 5  : Rock      { 1,  .5,   2,   1,  .5,   1,   2,   1,  .5,   2,   1,   1,   1,   1,   2,   1,   1,   1 }
// 6  : Bug       { 1,  .5,  .5,  .5,   1,   1,   1,  .5,  .5,  .5,   1,   1,   1,   2,   1,   1,   2,   2 }
// 7  : Ghost     { 0,   1,   1,   1,   1,  .5,   1,   2,  .5,   1,   1,   1,   1,   2,   1,   1,  .5,   1 }
// 8  : Steel     { 1,   1,   1,   1,   1,   2,   1,   1,  .5,  .5,  .5,   1,  .5,   1,   2,   1,   1,   2 }
// 9  : Fire      { 1,   1,   1,   1,   1,  .5,   2,   1,   2,  .5,  .5,   2,   1,   1,   2,  .5,   1,   1 }
// 10 : Water     { 1,   1,   1,   1,   2,   2,   1,   1,   1,   2,  .5,  .5,   1,   1,  .5,  .5,   1,   1 }
// 11 : Plant     { 1,   1,  .5,  .5,   2,   2,   1,   1,  .5,  .5,   2,  .5,   1,   1,   1,  .5,   1,   1 }
// 12 : Electric  { 1,   1,   2,   1,   0,   1,   1,   1,   1,   1,   2,  .5,  .5,   1,   1,  .5,   1,   1 }
// 13 : Psychic   { 1,   2,   1,   2,   1,  .5,   1,   1,   1,   1,   1,   1,   1,  .5,   1,   1,   0,   1 }
// 14 : Ice       { 1,   1,   2,   1,   2,   1,   1,   1,  .5,  .5,   1,   2,   1,   1,  .5,   2,   1,   1 }
// 15 : Dragon    { 1,   1,   1,   1,   1,   1,   1,   1,  .5,   1,   1,   1,   1,   1,   1,   2,   1,   0 }
// 16 : Dark      { 1,  .5,   1,   1,   1,   1,   1,   2,   1,   1,   1,   1,   1,   2,   1,   1,  .5,  .5 }
// 17 : Fairy     { 1,   2,   1,  .5,   1,   1,  .5,   1,  .5,  .5,   1,   1,   1,   1,   1,   2,   2,   1 }



	return true;
}

int main()
{
    if (!init())
        return -1;

    for (int i = 0; i < 18; ++i)
        cout << to_string(type_arr[i].id()) << ": " << type_arr[i].name() << endl;

	return 0;
}