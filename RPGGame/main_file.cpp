// RPGGame
// main.cpp
// Justyn Durnford
// Created on 2020-04-27
// Last updated on 2020-09-26

#include "Ability.h"
#include "Data.h"
#include "Matrix.h"
#include "Random.h"
#include "Terrain.h"
#include "Type.h"
#include "Weather.h"

#include <array>
using std::array;

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cout;
using std::endl;

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <string>
using std::string;
using std::to_string;
using std::getline;

array<Type, 18> type_arr;
float type_matchups[18][18];

array<Weather, 7> weather_arr;

array<Terrain, 5> terrain_arr;

bool init_types()
{
    type_arr[0] = Type(0, "Normal");
    type_arr[1] = Type(1, "Fighting");
    type_arr[2] = Type(2, "Flying");
    type_arr[3] = Type(3, "Poison");
    type_arr[4] = Type(4, "Ground");
    type_arr[5] = Type(5, "Rock");
    type_arr[6] = Type(6, "Bug");
    type_arr[7] = Type(7, "Ghost");
    type_arr[8] = Type(8, "Steel");
    type_arr[9] = Type(9, "Fire");
    type_arr[10] = Type(10, "Water");
    type_arr[11] = Type(11, "Plant");
    type_arr[12] = Type(12, "Electric");
    type_arr[13] = Type(13, "Psychic");
    type_arr[14] = Type(14, "Ice");
    type_arr[15] = Type(15, "Dragon");
    type_arr[16] = Type(16, "Dark");
    type_arr[17] = Type(17, "Fairy");

    float type_matchups[18][18] =
    {
        { 1,   1,   1,   1,   1,  .5,   1,   0,  .5,   1,   1,   1,   1,   1,   1,   1,   1,   1 },
        { 2,   1,  .5,  .5,   1,   2,  .5,   0,   2,   1,   1,   1,   1,  .5,   2,   1,   2,  .5 },
        { 1,   2,   1,   1,   1,  .5,   2,   1,  .5,   1,   1,   2,  .5,   1,   1,   1,   1,   1 },
        { 1,   1,   1,  .5,  .5,  .5,   1,  .5,   0,   1,   2,   2,   1,   1,   1,   1,   1,   2 },
        { 1,   1,   0,   2,   1,   2,  .5,   1,   2,   2,   1,  .5,   2,   1,   1,   1,   1,   1 },
        { 1,  .5,   2,   1,  .5,   1,   2,   1,  .5,   2,   1,   1,   1,   1,   2,   1,   1,   1 },
        { 1,  .5,  .5,  .5,   1,   1,   1,  .5,  .5,  .5,   1,   1,   1,   2,   1,   1,   2,   2 },
        { 0,   1,   1,   1,   1,  .5,   1,   2,  .5,   1,   1,   1,   1,   2,   1,   1,  .5,   1 },
        { 1,   1,   1,   1,   1,   2,   1,   1,  .5,  .5,  .5,   1,  .5,   1,   2,   1,   1,   2 },
        { 1,   1,   1,   1,   1,  .5,   2,   1,   2,  .5,  .5,   2,   1,   1,   2,  .5,   1,   1 },
        { 1,   1,   1,   1,   2,   2,   1,   1,   1,   2,  .5,  .5,   1,   1,  .5,  .5,   1,   1 },
        { 1,   1,  .5,  .5,   2,   2,   1,   1,  .5,  .5,   2,  .5,   1,   1,   1,  .5,   1,   1 },
        { 1,   1,   2,   1,   0,   1,   1,   1,   1,   1,   2,  .5,  .5,   1,   1,  .5,   1,   1 },
        { 1,   2,   1,   2,   1,  .5,   1,   1,   1,   1,   1,   1,   1,  .5,   1,   1,   0,   1 },
        { 1,   1,   2,   1,   2,   1,   1,   1,  .5,  .5,   1,   2,   1,   1,  .5,   2,   1,   1 },
        { 1,   1,   1,   1,   1,   1,   1,   1,  .5,   1,   1,   1,   1,   1,   1,   2,   1,   0 },
        { 1,  .5,   1,   1,   1,   1,   1,   2,   1,   1,   1,   1,   1,   2,   1,   1,  .5,  .5 },
        { 1,   2,   1,  .5,   1,   1,  .5,   1,  .5,  .5,   1,   1,   1,   1,   1,   2,   2,   1 }
    };

	return true;
}

bool init_weather()
{
    weather_arr[0] = Weather(0, "", "");
    weather_arr[1] = Weather(1, "The sunlight turned harsh!", "The harsh sunlight faded.");
    weather_arr[2] = Weather(2, "It started to rain!", "The rain stopped.");
    weather_arr[3] = Weather(3, "A sandstorm kicked up!", "The sandstorm subsided.");
    weather_arr[4] = Weather(4, "It started to hail!", "The hail stopped.");
    weather_arr[5] = Weather(5, "A thick smog filled the air!", "The air cleared up.");
    weather_arr[6] = Weather(6, "The wind became strong!", "The wind slowed down.");

    return true;
}

bool init_terrain()
{
    terrain_arr[0] = Terrain(0, "", "");
    terrain_arr[1] = Terrain(1, "An electric current runs across the battlefield!", "The electricity disappeared from the battlefield");
    terrain_arr[3] = Terrain(2, "A field of grass covers the battlefield!", "The grass disappeared from the battlefield.");
    terrain_arr[3] = Terrain(3, "Mist swirls around the battlefield!", "The mist disappeared from the battlefield.");
    terrain_arr[4] = Terrain(4, "The battlefield got weird!", "The weirdness disappeared from the battlefield.");

    return true;
}

int main()
{
    if (!init_types())
        return -1;

    for (int i = 0; i < 18; ++i)
        cout << to_string(type_arr[i].id()) << ": " << type_arr[i].name() << endl;

    array<int, 6> int_arr = { 0, 1, 2, 3, 4, 5 };
    
    for (unsigned char i = 0; i < 6; ++i)
        cout << int_arr[i] << endl;

    { shared_ptr<int> int_ptr = make_shared<int>(int_arr[3]); }

    for (unsigned char i = 0; i < 6; ++i)
        cout << int_arr[i] << endl;

	return 0;
}