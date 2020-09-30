// RPGGame
// main.cpp
// Justyn Durnford
// Created on 2020-04-27
// Last updated on 2020-09-30

#include "Ability.h"
#include "Chance.h"
#include "Characteristic.h"
#include "Egg_Group.h"
#include "Matrix.h"
#include "Move.h"
#include "Nature.h"
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

array<Ability, 194> ability_arr;

array<Characteristic, 30> characteristic_arr;

array<Egg_Group, 15> egg_group_arr;

array<Move_Kind, 3> move_kind_arr;

array<Nature, 25> nature_arr;

array<Terrain, 5> terrain_arr;

array<Type, 18> type_arr;
Matrix<float> type_matchups(18, 18);

array<Weather, 6> weather_arr;

bool init()
{
    characteristic_arr[0]  = Characteristic(0, "Loves to eat.", 0);
    characteristic_arr[1]  = Characteristic(1, "Takes plenty of siestas.", 0);
    characteristic_arr[2]  = Characteristic(2, "Nods off a lot.", 0);
    characteristic_arr[3]  = Characteristic(3, "Scatters things often.", 0);
    characteristic_arr[4]  = Characteristic(4, "Likes to relax.", 0);
    characteristic_arr[5]  = Characteristic(5, "Proud of its power.", 1);
    characteristic_arr[6]  = Characteristic(6, "Likes to thrash about.", 1);
    characteristic_arr[7]  = Characteristic(7, "A little quick tempered.", 1);
    characteristic_arr[8]  = Characteristic(8, "Likes to fight.", 1);
    characteristic_arr[9]  = Characteristic(9, "Quick tempered.", 1);
    characteristic_arr[10] = Characteristic(10, "Sturdy body.", 2);
    characteristic_arr[11] = Characteristic(11, "Capable of taking hits.", 2);
    characteristic_arr[12] = Characteristic(12, "Highly persistent.", 2);
    characteristic_arr[13] = Characteristic(13, "Good endurance.", 2);
    characteristic_arr[14] = Characteristic(14, "Good perseverance.", 2);
    characteristic_arr[15] = Characteristic(15, "Highly curious.", 3);
    characteristic_arr[16] = Characteristic(16, "Mischievous.", 3);
    characteristic_arr[17] = Characteristic(17, "Thoroughly cunning.", 3);
    characteristic_arr[18] = Characteristic(18, "Often lost in thought.", 3);
    characteristic_arr[19] = Characteristic(19, "Very finicky.", 3);
    characteristic_arr[20] = Characteristic(20, "Strong willed.", 4);
    characteristic_arr[21] = Characteristic(21, "Somewhat vain.", 4);
    characteristic_arr[22] = Characteristic(22, "Strongly defiant.", 4);
    characteristic_arr[23] = Characteristic(23, "Hates to lose.", 4);
    characteristic_arr[24] = Characteristic(24, "Somewhat stubborn.", 4);
    characteristic_arr[25] = Characteristic(25, "Likes to run.", 5);
    characteristic_arr[26] = Characteristic(26, "Alert to sounds.", 5);
    characteristic_arr[27] = Characteristic(27, "Impetuous and silly.", 5);
    characteristic_arr[28] = Characteristic(28, "Somewhat of a clown.", 5);
    characteristic_arr[29] = Characteristic(29, "Quick to flee.", 5);

    egg_group_arr[0]  = Egg_Group(0, "Monster");
    egg_group_arr[1]  = Egg_Group(1, "Water 1");
    egg_group_arr[2]  = Egg_Group(2, "Bug");
    egg_group_arr[3]  = Egg_Group(3, "Flying");
    egg_group_arr[4]  = Egg_Group(4, "Field");
    egg_group_arr[5]  = Egg_Group(5, "Fairy");
    egg_group_arr[6]  = Egg_Group(6, "Plant");
    egg_group_arr[7]  = Egg_Group(7, "Human-Like");
    egg_group_arr[8]  = Egg_Group(8, "Water 3");
    egg_group_arr[9]  = Egg_Group(9, "Mineral");
    egg_group_arr[10] = Egg_Group(10, "Amorphous");
    egg_group_arr[11] = Egg_Group(11, "Water 2");
    egg_group_arr[12] = Egg_Group(12, "Ditto");
    egg_group_arr[13] = Egg_Group(13, "Dragon");
    egg_group_arr[14] = Egg_Group(14, "Undiscovered");

    move_kind_arr[0] = Move_Kind(0, "Physical");
    move_kind_arr[1] = Move_Kind(1, "Special");
    move_kind_arr[2] = Move_Kind(2, "Status");

    nature_arr[0]  = Nature(0, "Adamant", 1, 3);
    nature_arr[1]  = Nature(1, "Bashful", -1, -1);
    nature_arr[2]  = Nature(2, "Bold", 2, 1);
    nature_arr[3]  = Nature(3, "Brave", 1, 5);
    nature_arr[4]  = Nature(4, "Calm", 4, 1);
    nature_arr[5]  = Nature(5, "Careful", 4, 3);
    nature_arr[6]  = Nature(6, "Docile", -1, -1);
    nature_arr[7]  = Nature(7, "Gentle", 4, 2);
    nature_arr[8]  = Nature(8, "Hardy", -1, -1);
    nature_arr[9]  = Nature(9, "Hasty", 5, 2);
    nature_arr[10] = Nature(10, "Impish", 2, 3);
    nature_arr[11] = Nature(11, "Jolly", 5, 3);
    nature_arr[12] = Nature(12, "Lax", 2, 4);
    nature_arr[13] = Nature(13, "Lonely", 1, 2);
    nature_arr[14] = Nature(14, "Mild", 3, 2);
    nature_arr[15] = Nature(15, "Modest", 3, 1);
    nature_arr[16] = Nature(16, "Naive", 5, 4);
    nature_arr[17] = Nature(17, "Naughty", 1, 4);
    nature_arr[18] = Nature(18, "Quiet", 3, 5);
    nature_arr[19] = Nature(19, "Quirky", -1, -1);
    nature_arr[20] = Nature(20, "Rash", 3, 4);
    nature_arr[21] = Nature(21, "Relaxed", 2, 5);
    nature_arr[22] = Nature(22, "Sassy", 4, 5);
    nature_arr[23] = Nature(23, "Serious", -1, -1);
    nature_arr[24] = Nature(24, "Timid", 5, 1);

    terrain_arr[0] = Terrain(0, "", "");
    terrain_arr[1] = Terrain(1, "An electric current runs across the battlefield!", "The electricity disappeared from the battlefield");
    terrain_arr[3] = Terrain(2, "A field of grass covers the battlefield!", "The grass disappeared from the battlefield.");
    terrain_arr[3] = Terrain(3, "Mist swirls around the battlefield!", "The mist disappeared from the battlefield.");
    terrain_arr[4] = Terrain(4, "The battlefield got weird!", "The weirdness disappeared from the battlefield.");

    type_arr[0]  = Type(0, "Normal");
    type_arr[1]  = Type(1, "Fighting");
    type_arr[2]  = Type(2, "Flying");
    type_arr[3]  = Type(3, "Poison");
    type_arr[4]  = Type(4, "Ground");
    type_arr[5]  = Type(5, "Rock");
    type_arr[6]  = Type(6, "Bug");
    type_arr[7]  = Type(7, "Ghost");
    type_arr[8]  = Type(8, "Steel");
    type_arr[9]  = Type(9, "Fire");
    type_arr[10] = Type(10, "Water");
    type_arr[11] = Type(11, "Plant");
    type_arr[12] = Type(12, "Electric");
    type_arr[13] = Type(13, "Psychic");
    type_arr[14] = Type(14, "Ice");
    type_arr[15] = Type(15, "Dragon");
    type_arr[16] = Type(16, "Dark");
    type_arr[17] = Type(17, "Fairy");

    type_matchups.setRow(0,  { 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 0.0, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 });
    type_matchups.setRow(1,  { 2.0, 1.0, 0.5, 0.5, 1.0, 2.0, 0.5, 0.0, 2.0, 1.0, 1.0, 1.0, 1.0, 0.5, 2.0, 1.0, 2.0, 0.5 });
    type_matchups.setRow(2,  { 1.0, 2.0, 1.0, 1.0, 1.0, 0.5, 2.0, 1.0, 0.5, 1.0, 1.0, 2.0, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0 });
    type_matchups.setRow(3,  { 1.0, 1.0, 1.0, 0.5, 0.5, 0.5, 1.0, 0.5, 0.0, 1.0, 2.0, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0 });
    type_matchups.setRow(4,  { 1.0, 1.0, 0.0, 2.0, 1.0, 2.0, 0.5, 1.0, 2.0, 2.0, 1.0, 0.5, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0 });
    type_matchups.setRow(5,  { 1.0, 0.5, 2.0, 1.0, 0.5, 1.0, 2.0, 1.0, 0.5, 2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0 });
    type_matchups.setRow(6,  { 1.0, 0.5, 0.5, 0.5, 1.0, 1.0, 1.0, 0.5, 0.5, 0.5, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 2.0, 2.0 });
    type_matchups.setRow(7,  { 0.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 2.0, 0.5, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 0.5, 1.0 });
    type_matchups.setRow(8,  { 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 0.5, 0.5, 0.5, 1.0, 0.5, 1.0, 2.0, 1.0, 1.0, 2.0 });
    type_matchups.setRow(9,  { 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 2.0, 1.0, 2.0, 0.5, 0.5, 2.0, 1.0, 1.0, 2.0, 0.5, 1.0, 1.0 });
    type_matchups.setRow(10, { 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 1.0, 1.0, 1.0, 2.0, 0.5, 0.5, 1.0, 1.0, 0.5, 0.5, 1.0, 1.0 });
    type_matchups.setRow(11, { 1.0, 1.0, 0.5, 0.5, 2.0, 2.0, 1.0, 1.0, 0.5, 0.5, 2.0, 0.5, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0 });
    type_matchups.setRow(12, { 1.0, 1.0, 2.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 0.5, 1.0, 1.0, 0.5, 1.0, 1.0 });
    type_matchups.setRow(13, { 1.0, 2.0, 1.0, 2.0, 1.0, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 0.0, 1.0 });
    type_matchups.setRow(14, { 1.0, 1.0, 2.0, 1.0, 2.0, 1.0, 1.0, 1.0, 0.5, 0.5, 1.0, 2.0, 1.0, 1.0, 0.5, 2.0, 1.0, 1.0 });
    type_matchups.setRow(15, { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.0 });
    type_matchups.setRow(16, { 1.0, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 0.5, 0.5 });
    type_matchups.setRow(17, { 1.0, 2.0, 1.0, 0.5, 1.0, 1.0, 0.5, 1.0, 0.5, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 1.0 });

    weather_arr[0] = Weather(0, "", "");
    weather_arr[1] = Weather(1, "The sunlight turned harsh!", "The harsh sunlight faded.");
    weather_arr[2] = Weather(2, "It started to rain!", "The rain stopped.");
    weather_arr[3] = Weather(3, "A sandstorm kicked up!", "The sandstorm subsided.");
    weather_arr[4] = Weather(4, "It started to hail!", "The hail stopped.");
    weather_arr[5] = Weather(5, "A thick smog filled the air!", "The air cleared up.");

	return true;
}

int main()
{
    if (!init())
        return -1;

    char r = 0;
    char c = 0;

    for (r = 0; r < 18; ++r)
    {
        for (c = 0; c < 17; ++c)
            cout << type_matchups(r, c) << ", ";

        cout << type_matchups(r, 17) << endl;
    }

    return 0;
}