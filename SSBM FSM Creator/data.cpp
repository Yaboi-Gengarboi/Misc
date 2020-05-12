// SSBM FSM Creator
// data.cpp
// Justyn Durnford
// Created on 5/3/2019
// Last updated on 5/3/2020

#include "FSM.hpp"

// #include <string>

// #include <vector>
using std::vector;

vector<character> character_list =
{
    { "Captain Falcon", 0x0 }, { "Donkey Kong", 0x1 }, { "Fox", 0x2 },
    { "Game&Watch", 0x3 }, { "Kirby", 0x4 }, { "Bowser", 0x5 },
    { "Link", 0x6 }, { "Luigi", 0x7 }, { "Mario", 0x8 },
    { "Marth", 0x9 }, { "Mewtwo", 0xa }, { "Ness", 0xb },
    { "Peach", 0xc }, { "Pikachu", 0xd }, { "Ice Climbers", 0xe },
    { "Jigglypuff", 0xf }, { "Samus", 0x10 }, { "Yoshi", 0x11 }, 
    { "Zelda", 0x12 }, { "Sheik", 0x13 }, { "Falco", 0x14 },
    { "Young Link", 0x15 }, { "Dr. Mario", 0x16 }, { "Roy", 0x17 },
    { "Pichu", 0x18 }, { "Ganondorf", 0x19 }, { "Popo", 0x1a }
};

vector<subaction> common_subaction_list =
{
    { "Spot Dodge", 0x029 },
    { "Forward Roll", 0x02a },
    { "Back Roll", 0x02b },
    { "Air Dodge", 0x02c },
    { "Jab 1", 0x02e },
    { "Jab 2", 0x02f },
    { "Jab 3", 0x030 },
    { "Rapid Jab Start", 0x031 },
    { "Rapid Jab Loop", 0x032 },
    { "Rapid Jab End", 0x033 },
    { "Dash Attack", 0x034 },
    { "Side Tilt High", 0x035 },
    { "Side Tilt Midhigh", 0x036 },
    { "Side Tilt Middle", 0x037 },
    { "Side Tilt Midlow", 0x038 },
    { "Side Tilt Low", 0x039 },
    { "Up Tilt", 0x03a },
    { "Down Tilt", 0x03Bb },
    { "Side Smash High", 0x03c },
    { "Side Smash Midhigh", 0x03d },
    { "Side Smash Middle", 0x03e },
    { "Side Smash Midlow", 0x03f },
    { "Side Smash Low", 0x040 },
    { "Up Smash", 0x042 },
    { "Down Smash", 0x043 },
    { "Neutral Aerial", 0x044 },
    { "Foward Aerial", 0x045 },
    { "Back Aerial", 0x046 },
    { "Up Aerial", 0x047 },
    { "Down Aerial", 0x049 },
    { "Neutral Tech", 0x0c7 },
    { "Forward Tech", 0x0c8 },
    { "Back Tech", 0x0c9 },
    { "Wall Tech", 0x0ca },
    { "Wall Jump Tech", 0x0cb },
    { "Ceiling Tech", 0x0cc },
    { "Ledge Getup Slow", 0x0db },
    { "Ledge Getup Fast", 0x0dc },
    { "Ledge Attack Slow", 0x0dd },
    { "Ledge Attack Fast", 0x0de },
    { "Ledge Roll Slow", 0x0df },
    { "Ledge Roll Fast", 0x0e0 },
    { "Ledge Jump 1 Slow", 0x0e1 },
    { "Ledge Jump 2 Slow", 0x0e2 },
    { "Ledge Jump 1 Fast", 0x0e3 },
    { "Ledge Jump 2 Fast", 0x0e4 },
    { "Left Taunt", 0x0eF },
    { "Right Taunt", 0x0f0 },
    { "Grab", 0x0f2 },
    { "Dash Grab", 0x0f3 },
    { "Forward Throw", 0x0f7 },
    { "Back Throw", 0x0f8 },
    { "Up Throw", 0x0f9 },
    { "Down Throw", 0x0fa }
};

vector<subaction> Captain_Falcon_subaction_list =
{
    { "Falcon Punch (Ground)", 0x12d },
    { "Falcon Punch (Aerial)", 0x12e },
    { "Raptor Boost Start (Ground)", 0x12f },
    { "Raptor Boost (Ground)", 0x130 },
    { "Raptor Boost Start (Aerial)", 0x131 },
    { "Raptor Boost (Aerial)", 0x132 },
    { "Falcon Dive (Ground)",  0x133 },
    { "Falcon Dive (Aerial)", 0x134 },
    { "Falcon Dive Grab", 0x135 },
    { "Falcon Dive Release", 0x136 },
    { "Falcon Kick (Ground)", 0x137 },
    { "Falcon Kick End (Ground)", 0x138 },
    { "Falcon Kick (Aerial)", 0x139 },
    { "Falcon Kick Aerial Landing", 0x13a },
    { "Falcon Kick (Ground End in Air)", 0x13b },
    { "Falcon Kick (Aerial End in Air)", 0x13c }
};

vector<subaction> Donkey_Kong_subaction_list =
{
    { "Cargo Foward Throw", 0x13b },
    { "Cargo Back Throw", 0x13c },
    { "Cargo Up Throw", 0x13d },
    { "Cargo Down Throw", 0x13e },
    { "Giant Punch Start (Ground)", 0x13f },
    { "Giant Punch Loop (Ground)", 0x140 },
    { "Giant Punch Cancel (Ground)", 0x141 },
    { "Giant Punch (Ground)", 0x142 },
    { "Giant Punch (2)(Ground)", 0x143 },
    { "Giant Punch Start (Aerial)", 0x144 },
    { "Giant Punch Loop (Aerial)", 0x145 },
    { "Giant Punch Cancel (Aerial)", 0x146 },
    { "Giant Punch (Aerial)", 0x147 },
    { "Giant Punch (2)(Aerial)", 0x148 },
    { "Headbutt (Ground)", 0x149 },
    { "Headbutt (Aerial)", 0x14a },
    { "Spinning Kong (Ground)", 0x14b },
    { "Spinning Kong (Aerial)", 0x14c },
    { "Hand Slap (Start)", 0x14d },
    { "Hand Slap Loop", 0x14e },
    { "Hand Slap End", 0x14f },
    { "Hand Slap End 2", 0x150 }
};

vector<subaction> Fox_subaction_list =
{
    { "Blaster Start (Ground)", 0x127 },
    { "Blaster Loop (Ground)", 0x128 },
    { "Blaster End (Ground)", 0x129 },
    { "Blaster Start (Aerial)", 0x12a },
    { "Blaster Loop (Aerial)", 0x12b },
    { "Blaster End (Aerial)", 0x12c },
    { "Fox Illusion Start (Ground)", 0x12d },
    { "Fox Illusion (Ground)", 0x12e },
    { "Fox Illusion End (Ground)", 0x12f },
    { "Fox Illusion Start (Aerial)", 0x130 },
    { "Fox Illusion (Aerial)", 0x131 },
    { "Fox Illusion End (Aerial)", 0x132 },
    { "Fire Fox Start (Ground)", 0x133 },
    { "Fire Fox Start (Aerial)", 0x134 },
    { "Fire Fox", 0x135 },
    { "Fire Fox Landing", 0x136 },
    { "Fire Fox Fall", 0x137 },
    { "Fire Fox Bounce", 0x138 },
    { "Reflector Start (Ground)", 0x139 },
    { "Reflector Loop (Ground)", 0x13a },
    { "Reflector Reflect (Ground)", 0x13b },
    { "Reflector End (Ground)", 0x13c },
    { "Reflector Start (Aerial)", 0x13d },
    { "Reflector Loop (Aerial)", 0x13e },
    { "Reflector Reflect (Aerial)", 0x13f },
    { "Reflector End (Aerial)", 0x140 }
};

vector<subaction> Game_and_Watch_subaction_list =
{
    { "Chef (Ground)", 0x127 },
    { "Chef (Aerial)", 0x128 },
    { "Judge 1 (Ground)", 0x129 },
    { "Judge 2 (Ground)", 0x12a },
    { "Judge 3 (Ground)", 0x12b },
    { "Judge 4 (Ground)", 0x12c },
    { "Judge 5 (Ground)", 0x12d },
    { "Judge 6 (Ground)", 0x12e },
    { "Judge 7 (Ground)", 0x12f },
    { "Judge 8 (Ground)", 0x130 },
    { "Judge 9 (Ground)", 0x131 },
    { "Judge 1 (Aerial)", 0x132 },
    { "Judge 2 (Aerial)", 0x133 },
    { "Judge 3 (Aerial)", 0x134 },
    { "Judge 4 (Aerial)", 0x135 },
    { "Judge 5 (Aerial)", 0x136 },
    { "Judge 6 (Aerial)", 0x137 },
    { "Judge 7 (Aerial)", 0x138 },
    { "Judge 8 (Aerial)", 0x139 },
    { "Judge 9 (Aerial)", 0x13a },
    { "Fire (Ground)", 0x13b },
    { "Fire (Aerial)", 0x13c },
    { "Oil Panic (Ground)", 0x13d },
    { "Oil Panic Absorb (Ground)", 0x13e },
    { "Oil Panic Release (Ground)", 0x13f },
    { "Oil Panic (Aerial)", 0x140 },
    { "Oil Panic Absorb (Aerial)", 0x141 },
    { "Oil Panic Release (Aerial)", 0x142 }
};

/*
vector<subaction> Kirby_subaction_list =
{
    { "Inhale", 0x
    { "Inhale Loop", 0x
    { "Inhale End", 0x
    { "Inhale Swallow", 0x
    { "Inhale Spit", 0x
    { "Hammer (Ground)", 0x
    { "Hammer (Aerial)", 0x
    { "Final Cutter Start (Ground)", 0x
    { "Final Cutter (Ground)", 0x
    { "Final Cutter Landing (Ground)", 0x
    { "Final Cutter Start (Aerial)", 0x
    { "Final Cutter (Aerial)", 0x
    { "Final Cutter Landing (Aerial)", 0x
    { "Stone 1 (Ground)", 0x
    { "Stone 2 (Ground)", 0x
    { "Stone 3 (Ground)", 0x
    { "Stone 1 (Aerial)", 0x
    { "Stone 2 (Aerial)", 0x
    { "Stone 3 (Aerial)", 0x
    { "Fireball (Mario) (Ground)", 0x
    { "Fireball (Mario) (Aerial)", 0x
    { "Bow Start (Link) (Ground)", 0x
    { "Bow Loop (Link) (Ground)", 0x
    { "Bow Shoot (Link) (Ground)", 0x
    { "Bow Start (Link) (Aerial)", 0x
    { "Bow Loop (Link) (Aerial)", 0x
    { "Bow Shoot (Link) (Aerial)", 0x
    { "Charge Shot Start (Ground)", 0x
    { "Charge Shot Charging Loop (Ground)", 0x
    { "Charge Shot Cancel (Ground)", 0x
    { "Charge Shot Shoot (Ground)", 0x
    { "Charge Shot Start (Aerial)", 0x
    { "Charge Shot Shoot (Aerial)", 0x
    { "Egg Lay 1 (Ground)", 0x
    { "Egg Lay 2 (Ground)", 0x
    { "Egg Lay 3 (Ground)", 0x
    { "Egg Lay 1 (Aerial)", 0x
    { "Egg Lay 2 (Aerial)", 0x
    { "Egg Lay 3 (Aerial)", 0x
    { "Blaster Start (Fox) (Ground)", 0x
    { "Blaster Loop (Fox) (Ground)", 0x
    { "Blaster End (Fox) (Ground)", 0x
    { "Blaster Start (Fox) (Aerial)", 0x
    { "Blaster Loop (Fox) (Aerial)", 0x
    { "Blaster End (Fox) (Aerial)", 0x
    { "Thunder Jolt (Pikachu) (Ground)", 0x
    { "Thunder Jolt (Pikachu) (Aerial)", 0x
    { "Fireball (Luigi) (Ground)", 0x
    { "Fireball (Luigi) (Aerial)", 0x
    { "Falcon Punch (Ground)", 0x
    { "Falcon Punch (Aerial)", 0x
    { "PK Flash Start (Ground)", 0x
    { "PK Flash Hold 1 (Ground)", 0x
    { "PK Flash Hold 2 (Ground)", 0x
    { "PK Flash End (Ground)", 0x
    { "PK Flash Start (Aerial)", 0x
    { "PK Flash Hold 1 (Aerial)", 0x
    { "PK Flash Hold 2 (Aerial)", 0x
    { "PK Flash End (Aerial)", 0x
    { "Fire Breath Start (Ground)", 0x
    { "Fire Breath Loop (Ground)", 0x
    { "Fire Breath End (Ground)", 0x
    { "Fire Breath Start (Aerial)", 0x
    { "Fire Breath Loop (Aerial)", 0x
    { "Fire Breath End (Aerial)", 0x
    { "Toad Counter (Ground)", 0x
    { "Toad Hit (Ground)", 0x
    { "Toad Counter (Aerial)", 0x
    { "Toad Hit (Aerial)", 0x
    { "Ice Shot (Ground)", 0x
    { "Ice Shot (Aerial)", 0x
    { "Giant Punch Start (Ground)", 0x
    { "Giant Punch Loop (Ground)", 0x
    { "Giant Punch Cancel (Ground)", 0x
    { "Giant Punch (Ground)", 0x
    { "Giant Punch (2)(Ground)", 0x
    { "Giant Punch Start (Aerial)", 0x
    { "Giant Punch Loop (Aerial)", 0x
    { "Giant Punch Cancel (Aerial)", 0x
    { "Giant Punch (Aerial)", 0x
    { "Giant Punch (2)(Aerial)", 0x
    { "Nayru's Love (Ground)", 0x
    { "Nayru's Love (Aerial)", 0x
    { "Needle Storm Start (Ground)", 0x
    { "Needle Storm Charging Loop (Ground)", 0x
    { "Needle Storm Cancel (Ground)", 0x
    { "Needle Storm Shoot (Ground)", 0x
    { "Needle Storm Start (Aerial)", 0x
    { "Needle Storm Charging Loop (Aerial)", 0x
    { "Needle Storm Cancel (Aerial)", 0x
    { "Needle Storm Shoot (Aerial)", 0x
    { "Rollout Start Right (Ground)", 0x
    { "Rollout Start Left (Ground)", 0x
    { "Rollout 1 (Ground)", 0x
    { "Rollout 2 (Ground)", 0x
    { "Rollout 3 (Ground)", 0x
    { "Rollout 4 (Ground)", 0x
    { "Rollout End Right (Ground)", 0x
    { "Rollout End Left (Ground)", 0x
    { "Rollout Start Right (Aerial)", 0x
    { "Rollout Start Left (Aerial)", 0x
    { "Rollout 1 (Aerial)", 0x
    { "Rollout 2 (Aerial)", 0x
    { "Rollout 3 (Aerial)", 0x
    { "Rollout 4 (Aerial)", 0x
    { "Rollout End Right (Aerial)", 0x
    { "Rollout End Left (Aerial)", 0x
    { "Rollout 5", 0x
    { "Shield Breaker Start (Ground)", 0x
    { "Shield Breaker Loop (Ground)", 0x
    { "Shield Breaker End 1 (Ground)", 0x
    { "Shield Breaker End 2 (Ground)", 0x
    { "Shield Breaker Start (Aerial)", 0x
    { "Shield Breaker Loop (Aerial)", 0x
    { "Shield Breaker End 1 (Aerial)", 0x
    { "Shield Breaker End 2 (Aerial)", 0x
    { "Shadow Ball Start (Ground)", 0x
    { "Shadow Ball Charging Loop (Ground)", 0x
    { "Shadow Ball Charged Loop (Ground)", 0x
    { "Shadow Ball Cancel (Ground)", 0x
    { "Shadow Ball End (Ground)", 0x
    { "Shadow Ball Start (Aerial)", 0x
    { "Shadow Ball Charging Loop (Aerial)", 0x
    { "Shadow Ball Charged Loop (Aerial)", 0x
    { "Shadow Ball Cancel (Aerial)", 0x
    { "Shadow Ball End (Aerial)", 0x
    { "Chef (Ground)", 0x
    { "Chef (Aerial)", 0x
    { "Megavitamin (Ground)", 0x
    { "Megavitamin (Aerial)", 0x
    { "Bow Start (Young Link) (Ground)", 0x
    { "Bow Loop (Young Link) (Ground)", 0x
    { "Bow Shoot (Young Link) (Ground)", 0x
    { "Bow Start (Young Link) (Aerial)", 0x
    { "Bow Loop (Young Link) (Aerial)", 0x
    { "Bow Shoot (Young Link) (Aerial)", 0x
    { "Blaster Start (Falco) (Ground)", 0x
    { "Blaster Loop (Falco) (Ground)", 0x
    { "Blaster End (Falco) (Ground)", 0x
    { "Blaster Start (Falco) (Aerial)", 0x
    { "Blaster Loop (Falco) (Aerial)", 0x
    { "Blaster End (Falco) (Aerial)", 0x
    { "Thunder Jolt (Pichu) (Ground)", 0x
    { "Thunder Jolt (Pichu) (Aerial)", 0x
    { "Warlock Punch (Ground)", 0x
    { "Warlock Punch (Aerial)", 0x
    { "Flare Blade Start (Ground)", 0x
    { "Flare Blade Loop (Ground)", 0x
    { "Flare Blade End 1 (Ground)", 0x
    { "Flare Blade End 2 (Ground)", 0x
    { "Flare Blade Start (Aerial)", 0x
    { "Flare Blade Loop (Aerial)", 0x
    { "Flare Blade End 1 (Aerial)", 0x
    { "Flare Blade End 2 (Aerial)", 0x
};
*/

/*
vector<subaction> Bowser_subaction_list =
{
    { "Fire Breath Start (Ground)", 0x127-
    { "Fire Breath Loop (Ground)", 0x128-
    { "Fire Breath End (Ground)", 0x129-
    { "Fire Breath Start (Aerial)", 0x12a-
    { "Fire Breath Loop (Aerial)", 0x12b-
    { "Fire Breath End (Aerial)", 0x12c-
    { "Koopa Claw Start (Ground)", 0x12d-
    { "Koopa Claw Hit 1 (Ground)", 0x12e-
    { "Koopa Claw Hit 2 (Ground)", 0x12f-
    { "Koopa Claw Foward Throw (Ground)", 0x130-
    { "Koopa Claw Back Throw (Ground)", 0x131-
    { "Koopa Claw Start (Aerial)", 0x132-
    { "Koopa Claw Hit 1 (Aerial)", 0x133-
    { "Koopa Claw Hit 2 (Aerial)", 0x134-
    { "Koopa Claw Foward Throw (Aerial)", 0x135-
    { "Koopa Claw Back Throw (Aerial)", 0x136-
    { "Whirling Fortress (Ground)", 0x137-
    { "Whirling Fortress (Aerial)", 0x138-
    { "Bowser Bomb (Ground)", 0x139-
    { "Bowser Bomb (Aerial)", 0x13a-
    { "Bowser Bomb Landing", 0x13b-
};
*/

/*
vector<subaction> Link_subaction_list =
{
    { "Side Smash 2", 0x127-
    { "Bow Start (Ground)", 0x128-
    { "Bow Loop (Ground)", 0x129-
    { "Bow Shoot (Ground)", 0x12a-
    { "Bow Start (Aerial)", 0x12b-
    { "Bow Loop (Aerial)", 0x12c-
    { "Bow Shoot (Aerial)", 0x12d-
    { "Boomerang 1 (Ground)", 0x12e-
    { "Boomerang 2 (Ground)", 0x12f-
    { "Boomerang 1 2 (Ground)", 0x130-
    { "Boomerang 1 (Aerial)", 0x131-
    { "Boomerang 2 (Aerial)", 0x132-
    { "Boomerang 1 2 (Aerial)", 0x133-
    { "Hero Spin (Ground)", 0x134-
    { "Hero Spin (Aerial)", 0x135-
    { "Bomb (Ground)", 0x136-
    { "Bomb (Aerial)", 0x137-
    { "Aerial Hook Shot", 0x138-
    { "Aerial Hook Shot Hit", 0x139-
};
*/

/*
vector<subaction> Luigi_subaction_list =
{
    { "Fireball (Ground)", 0x127-
    { "Fireball (Aerial)", 0x128-
    { "Missfire Start (Ground)", 0x129-
    { "Missfire Charge (Ground)", 0x12a-
    { "Missfire 1 (Ground)", 0x12b-
    { "Missfire 2 (Ground)", 0x12c-
    { "Missfire 3 (Ground)", 0x12d-
    { "Missfire End (Ground)", 0x12e-
    { "Missfire Start (Aerial)", 0x12f-
    { "Missfire Charge (Aerial)", 0x130-
    { "Missfire 1 (Aerial)", 0x131-
    { "Missfire 2 (Aerial)", 0x132-
    { "Missfire End (Aerial)", 0x133-
    { "Super Jump Punch (Ground)", 0x134-
    { "Super Jump Punch (Aerial)", 0x135-
    { "Luigi Cyclone (Ground)", 0x136-
    { "Luigi Cyclone (Aerial)", 0x137-
};
*/

/*
vector<subaction> Mario_subaction_list =
{
    { "Fireball (Ground)", 0x127-
    { "Fireball (Aerial)", 0x128-
    { "Cape (Ground)", 0x129-
    { "Cape (Aerial)", 0x12a-
    { "Super Jump Punch (Ground)", 0x12b-
    { "Super Jump Punch (Aerial)", 0x12c-
    { "Mario Tornado (Ground)", 0x12d-
    { "Mario Tornado (Aerial)", 0x12e-
};
*/

/*
vector<subaction> Marth_subaction_list =
{
    { "Shield Breaker Start (Ground)", 0x127-
    { "Shield Breaker Loop (Ground)", 0x128-
    { "Shield Breaker End 1 (Ground)", 0x129-
    { "Shield Breaker End 2 (Ground)", 0x12a-
    { "Shield Breaker Start (Aerial)", 0x12b-
    { "Shield Breaker Loop (Aerial)", 0x12c-
    { "Shield Breaker End 1 (Aerial)", 0x12d-
    { "Shield Breaker End 2 (Aerial)", 0x12e-
    { "Dancing Blade 1 (Ground)", 0x12f-
    { "Dancing Blade 2 (High) (Ground)", 0x130-
    { "Dancing Blade 2 (Middle) (Ground)", 0x131-
    { "Dancing Blade 3 (High) (Ground)", 0x132-
    { "Dancing Blade 3 (Middle) (Ground)", 0x133-
    { "Dancing Blade 3 (Low) (Ground)", 0x134-
    { "Dancing Blade 4 (High) (Ground)", 0x135-
    { "Dancing Blade 4 (Middle) (Ground)", 0x136-
    { "Dancing Blade 4 (Low) (Ground)", 0x137-
    { "Dancing Blade 1 (Aerial)", 0x138-
    { "Dancing Blade 2 (High) (Aerial)", 0x139-
    { "Dancing Blade 2 (Middle) (Aerial)", 0x13a-
    { "Dancing Blade 3 (High) (Aerial)", 0x13b-
    { "Dancing Blade 3 (Middle) (Aerial)", 0x13c-
    { "Dancing Blade 3 (Low) (Aerial)", 0x13d-
    { "Dancing Blade 4 (High) (Aerial)", 0x13e-
    { "Dancing Blade 4 (Middle) (Aerial)", 0x13f-
    { "Dancing Blade 4 (Low) (Aerial)", 0x140-
    { "Dolphin Slash (Ground)", 0x141-
    { "Dolphin Slash (Aerial)", 0x142-
    { "Counter (Ground)", 0x143-
    { "Counter Hit (Ground)", 0x144-
    { "Counter (Aerial)", 0x145-
    { "Counter Hit (Aerial)", 0x146-
};
*/

/*
vector<subaction> Mewtwo_subaction_list =
{
    { "Shadow Ball Start (Ground)", 0x127-
    { "Shadow Ball Charging Loop (Ground)", 0x128-
    { "Shadow Ball Charged Loop (Ground)", 0x129-
    { "Shadow Ball Cancel (Ground)", 0x12a-
    { "Shadow Ball End (Ground)", 0x12b-
    { "Shadow Ball Start (Aerial)", 0x12c-
    { "Shadow Ball Charging Loop (Aerial)", 0x12d-
    { "Shadow Ball Charged Loop (Aerial)", 0x12e-
    { "Shadow Ball Cancel (Aerial)", 0x12f-
    { "Shadow Ball End (Aerial)", 0x130-
    { "Confusion (Ground)", 0x131-
    { "Confusion (Aerial)", 0x132-
    { "Teleport Start (Ground)", 0x133-
    { "Teleport (Ground)", 0x134-
    { "Teleport Lost (Ground)", 0x135-
    { "Teleport Start (Aerial)", 0x136-
    { "Teleport (Aerial)", 0x137-
    { "Disable (Ground)", 0x138-
    { "Disable (Aerial)", 0x139-
};
*/

/*
vector<subaction> Ness_subaction_list =
{
    { "Up Smash 2", 0x127-
    { "Up Smash 3", 0x128-
    { "Down Smash 2", 0x129-
    { "Down Smash 3", 0x12a-
    { "PK Flash Start (Ground)", 0x12b-
    { "PK Flash Hold 1 (Ground)", 0x12c-
    { "PK Flash Hold 2 (Ground)", 0x12d-
    { "PK Flash End (Ground)", 0x12e-
    { "PK Flash Start (Aerial)", 0x12f-
    { "PK Flash Hold 1 (Aerial)", 0x130-
    { "PK Flash Hold 2 (Aerial)", 0x131-
    { "PK Flash End (Aerial)", 0x132-
    { "PK Fire (Ground)", 0x133-
    { "PK Fire (Aerial)", 0x134-
    { "PK Thunder Start (Ground)", 0x135-
    { "PK Thunder Hold (Ground)", 0x136-
    { "PK Thunder End (Ground)", 0x137-
    { "PK Thunder Launch (Ground)", 0x138-
    { "PK Thunder Start (Aerial)", 0x139-
    { "PK Thunder Hold (Aerial)", 0x13a-
    { "PK Thunder End (Aerial)", 0x13b-
    { "PK Thunder Launch (Aerial)", 0x13c
    { "PSI Magnet Start (Ground)", 0x13e-
    { "PSI Magnet Hold (Ground)", 0x13f-
    { "PSI Magnet Absorb (Ground)", 0x140-
    { "PSI Magnet End (Ground)", 0x141-
    { "PSI Magnet Start (Aerial)", 0x142-
    { "PSI Magnet Hold (Aerial)", 0x143-
    { "PSI Magnet Absorb (Aerial)", 0x144-
    { "PSI Magnet End (Aerial)", 0x145-
};
*/

/*
vector<subaction> Peach_subaction_list =
{
    { "Side Smash 1", 0x12a-
    { "Side Smash 2", 0x12b-
    { "Side Smash 3", 0x12c-
    { "Toad Counter (Ground)", 0x12d-
    { "Peach Bomber Start (Ground)", 0x12e-
    { "Peach Bomber End (Ground)", 0x12f-
    { "Peach Bomber Jump", 0x130-
    { "Peach Bomber Start (Aerial)", 0x131-
    { "Peach Bomber End 1 (Aerial)", 0x132-
    { "Peach Bomber End 2 (Aerial)", 0x133-
    { "Peach Parasol Start (Ground)", 0x134-
    { "Peach Parasol End (Ground)", 0x135-
    { "Peach Parasol Start (Aerial)", 0x136-
    { "Peach Parasol End (Aerial)", 0x137-
    { "Vegetable", 0x138-
};
*/

/*
vector<subaction> Pikachu_subaction_list =
{
    { "Thunder Jolt (Ground)", 0x
    { "Thunder Jolt (Aerial)", 0x
    { "Skull Bash Start (Ground)", 0x
    { "Skull Bash Charge (Ground)", 0x
    { "Skull Bash 1 (Ground)", 0x
    { "Skull Bash 2 (Ground)", 0x
    { "Skull Bash End (Ground)", 0x
    { "Skull Bash Start (Aerial)", 0x
    { "Skull Bash Charge (Aerial)", 0x
    { "Skull Bash (Aerial)", 0x
    { "Skull Bash End (Aerial)", 0x
    { "Quick Attack Start 1 (Ground)", 0x
    { "Quick Attack Start 2 (Ground)", 0x
    { "Quick Attack End (Ground)", 0x
    { "Quick Attack Start 1 (Aerial)", 0x
    { "Quick Attack Start 2 (Aerial)", 0x
    { "Quick Attack End (Aerial)", 0x
    { "Thunder Start (Ground)", 0x
    { "Thunder Loop 1 (Ground)", 0x
    { "Thunder Loop 2 (Ground)", 0x
    { "Thunder End (Ground)", 0x
    { "Thunder Start (Aerial)", 0x
    { "Thunder Loop 1 (Aerial)", 0x
    { "Thunder Loop 2 (Aerial)", 0x
    { "Thunder End (Aerial)", 0x
};
*/

/*
vector<subaction> Ice_Climbers_subaction_list =
{
    { "Ice Shot (Ground)", 0x127-
    { "Ice Shot (Aerial)", 0x128-
    { "Squall Hammer 1 (Ground)", 0x129-
    { "Squall Hammer 2 (Ground)", 0x12a-
    { "Squall Hammer 1 (Aerial)", 0x12b-
    { "Squall Hammer 2 (Aerial)", 0x12c-
    { "Belay Start (Ground)", 0x12d-
    { "Belay Throw 1 (Ground)", 0x12e-
    { "Belay Throw 2 (Ground)", 0x12f-
    { "Belay Start (Aerial)", 0x132-
    { "Belay Throw 1 (Aerial)", 0x133-
    { "Belay Throw 2 (Aerial)", 0x134-
    { "Blizzard (Ground)", 0x137-
    { "Blizzard (Aerial)", 0x138-
};
*/

/*
vector<subaction> Jigglypuff_subaction_list =
{
    { "Rollout Start Right (Ground)", 0x
    { "Rollout Start Left (Ground)", 0x
    { "Rollout 1 (Ground)", 0x
    { "Rollout 2 (Ground)", 0x
    { "Rollout 3 (Ground)", 0x
    { "Rollout 4 (Ground)", 0x
    { "Rollout End Right (Ground)", 0x
    { "Rollout End Left (Ground)", 0x
    { "Rollout Start Right (Aerial)", 0x
    { "Rollout Start Left (Aerial)", 0x
    { "Rollout 1 (Aerial)", 0x
    { "Rollout 2 (Aerial)", 0x
    { "Rollout 3 (Aerial)", 0x
    { "Rollout 4 (Aerial)", 0x
    { "Rollout End Right (Aerial)", 0x
    { "Rollout End Left (Aerial)", 0x
    { "Rollout 5", 0x
    { "Pound (Ground)", 0x
    { "Pound (Aerial)", 0x
    { "Sing Left (Ground)", 0x
    { "Sing Left (Aerial)", 0x
    { "Sing Right (Ground)", 0x
    { "Sing Right (Aerial)", 0x
    { "Rest Left (Ground)", 0x
    { "Rest Left (Aerial)", 0x
    { "Rest Right (Ground)", 0x
    { "Rest Right (Aerial)", 0x
};
*/

/*
vector<subaction> Samus_subaction_list =
{
    { "Charge Shot Start (Ground)", 0x
    { "Charge Shot Charging Loop (Ground)", 0x
    { "Charge Shot Cancel (Ground)", 0x
    { "Charge Shot Shoot (Ground)", 0x
    { "Charge Shot Start (Aerial)", 0x
    { "Charge Shot Shoot (Aerial)", 0x
    { "Homing Missile (Ground)", 0x
    { "Super Missile (Ground)", 0x
    { "Homing Missile (Aerial)", 0x
    { "Super Missile (Aerial)", 0x
    { "Screw Attack (Ground)", 0x
    { "Screw Attack (Aerial)", 0x
    { "Bomb (Ground)", 0x
    { "Bomb (Aerial)", 0x
    { "Aerial Grapple", 0x
    { "Aerial Grapple Hit", 0x
};
*/

/*
vector<subaction> Yoshi_subaction_list =
{
    { "Egg Lay 1 (Ground)", 0x
    { "Egg Lay 2 (Ground)", 0x
    { "Egg Lay 3 (Ground)", 0x
    { "Egg Lay 1 (Aerial)", 0x
    { "Egg Lay 2 (Aerial)", 0x
    { "Egg Lay 3 (Aerial)", 0x
    { "Egg Roll Start (Ground)", 0x
    { "Egg Roll Loop 1 (Ground)", 0x
    { "Egg Roll Loop 2 (Ground)", 0x
    { "Egg Roll End (Ground)", 0x
    { "Egg Roll Start (Aerial)", 0x
    { "Egg Roll Loop 1 (Aerial)", 0x
    { "Egg Roll Loop 2 (Aerial)", 0x
    { "Egg Roll End (Aerial)", 0x
    { "Egg Throw (Ground)", 0x
    { "Egg Throw (Aerial)", 0x
    { "Yoshi Bomb (Ground)", 0x
    { "Yoshi Bomb Landing", 0x
    { "Yoshi Bomb (Aerial)", 0x
};
*/

/*
vector<subaction> Zelda_subaction_list =
{
    { "Nayru's Love (Ground)", 0x
    { "Nayru's Love (Aerial)", 0x
    { "Din's Fire Start (Ground)", 0x
    { "Din's Fire Loop (Ground)", 0x
    { "Din's Fire End (Ground)", 0x
    { "Din's Fire Start (Aerial)", 0x
    { "Din's Fire Loop (Aerial)", 0x
    { "Din's Fire End (Aerial)", 0x
    { "Farore's Wind Start (Ground)", 0x
    { "Farore's Wind (Ground)", 0x
    { "Farore's Wind Start (Aerial)", 0x
    { "Farore's Wind (Aerial)", 0x
    { "Transform 1 (Ground)", 0x
    { "Transform 2 (Ground)", 0x
    { "Transform 1 (Aerial)", 0x
    { "Transform 2 (Aerial)", 0x
};
*/

/*
vector<subaction> Sheik_subaction_list =
{
    { "Needle Storm Start (Ground)", 0x
    { "Needle Storm Charging Loop (Ground)", 0x
    { "Needle Storm Cancel (Ground)", 0x
    { "Needle Storm Shoot (Ground)", 0x
    { "Needle Storm Start (Aerial)", 0x
    { "Needle Storm Charging Loop (Aerial)", 0x
    { "Needle Storm Cancel (Aerial)", 0x
    { "Needle Storm Shoot (Aerial)", 0x
    { "Chain Start (Ground)", 0x
    { "Chain End (Ground)", 0x
    { "Chain (Ground)", 0x
    { "Chain Start (Aerial)", 0x
    { "Chain End (Aerial)", 0x
    { "Chain (Aerial)", 0x
    { "Vanish Start (Ground)", 0x
    { "Vanish (Ground)", 0x
    { "Vanish Start (Aerial)", 0x
    { "Vanish (Aerial)", 0x
    { "Transform 1 (Ground)", 0x
    { "Transform 2 (Ground)", 0x
    { "Transform 1 (Aerial)", 0x
    { "Transform 2 (Aerial)", 0x
};
*/

/*
vector<subaction> Falco_subaction_list =
{
    { "Blaster Start (Ground)", 0x
    { "Blaster Loop (Ground)", 0x
    { "Blaster End (Ground)", 0x
    { "Blaster Start (Aerial)", 0x
    { "Blaster Loop (Aerial)", 0x
    { "Blaster End (Aerial)", 0x
    { "Falco Phantasm Start (Ground)", 0x
    { "Falco Phantasm (Ground)", 0x
    { "Falco Phantasm End (Ground)", 0x
    { "Falco Phantasm Start (Aerial)", 0x
    { "Falco Phantasm (Aerial)", 0x
    { "Falco Phantasm End (Aerial)", 0x
    { "Fire Bird Start (Ground)", 0x
    { "Fire Bird Start (Aerial)", 0x
    { "Fire Bird", 0x
    { "Fire Bird Landing", 0x
    { "Fire Bird Fall", 0x
    { "Fire Bird Bounce", 0x
    { "Reflector Start (Ground)", 0x
    { "Reflector Loop (Ground)", 0x
    { "Reflector Reflect (Ground)", 0x
    { "Reflector End (Ground)", 0x
    { "Reflector Start (Aerial)", 0x
    { "Reflector Loop (Aerial)", 0x
    { "Reflector Reflect (Aerial)", 0x
    { "Reflector End (Aerial)", 0x
};
*/

/*
vector<subaction> Young_Link_subaction_list =
{
    { "Side Smash 2", 0x
    { "Bow Start (Ground)", 0x
    { "Bow Loop (Ground)", 0x
    { "Bow Shoot (Ground)", 0x
    { "Bow Start (Aerial)", 0x
    { "Bow Loop (Aerial)", 0x
    { "Bow Shoot (Aerial)", 0x
    { "Boomerang 1 (Ground)", 0x
    { "Boomerang 2 (Ground)", 0x
    { "Boomerang 1 2 (Ground)", 0x
    { "Boomerang 1 (Aerial)", 0x
    { "Boomerang 2 (Aerial)", 0x
    { "Boomerang 1 2 (Aerial)", 0x
    { "Hero Spin (Ground)", 0x
    { "Hero Spin (Aerial)", 0x
    { "Bomb (Ground)", 0x
    { "Bomb (Aerial)", 0x
    { "Aerial Hook Shot", 0x
    { "Aerial Hook Shot Hit", 0x
};
*/

/*
vector<subaction> Dr_Mario_subaction_list =
{
    { "Megavitamin (Ground)", 0x127-
    { "Megavitamin (Aerial)", 0x128-
    { "Super Sheet (Ground)", 0x129-
    { "Super Sheet (Aerial)", 0x12a-
    { "Super Jump Punch (Ground)", 0x12b-
    { "Super Jump Punch (Aerial)", 0x12c-
    { "Dr. Tornado (Ground)", 0x12d-
    { "Dr. Tornado (Aerial)", 0x12e-
};
*/

/*
vector<subaction> Roy_subaction_list =
{
    { "Flare Blade Start (Ground)", 0x
    { "Flare Blade Loop (Ground)", 0x
    { "Flare Blade End 1 (Ground)", 0x
    { "Flare Blade End 2 (Ground)", 0x
    { "Flare Blade Start (Aerial)", 0x
    { "Flare Blade Loop (Aerial)", 0x
    { "Flare Blade End 1 (Aerial)", 0x
    { "Flare Blade End 2 (Aerial)", 0x
    { "Double-Edge Dance 1 (Ground)", 0x
    { "Double-Edge Dance 2 (High) (Ground)", 0x
    { "Double-Edge Dance 2 (Middle) (Ground)", 0x
    { "Double-Edge Dance 3 (High) (Ground)", 0x
    { "Double-Edge Dance 3 (Middle) (Ground)", 0x
    { "Double-Edge Dance 3 (Low) (Ground)", 0x
    { "Double-Edge Dance 4 (High) (Ground)", 0x
    { "Double-Edge Dance 4 (Middle) (Ground)", 0x
    { "Double-Edge Dance 4 (Low) (Ground)", 0x
    { "Double-Edge Dance 1 (Aerial)", 0x
    { "Double-Edge Dance 2 (High) (Aerial)", 0x
    { "Double-Edge Dance 2 (Middle) (Aerial)", 0x
    { "Double-Edge Dance 3 (High) (Aerial)", 0x
    { "Double-Edge Dance 3 (Middle) (Aerial)", 0x
    { "Double-Edge Dance 3 (Low) (Aerial)", 0x
    { "Double-Edge Dance 4 (High) (Aerial)", 0x
    { "Double-Edge Dance 4 (Middle) (Aerial)", 0x
    { "Double-Edge Dance 4 (Low) (Aerial)", 0x
    { "Blazer (Ground)", 0x
    { "Blazer (Aerial)", 0x
    { "Counter (Ground)", 0x
    { "Counter Hit (Ground)", 0x
    { "Counter (Aerial)", 0x
    { "Counter Hit (Aerial)", 0x
};
*/

/*
vector<subaction> Pichu_subaction_list =
{
    { "Thunder Jolt (Ground)", 0x
    { "Thunder Jolt (Aerial)", 0x
    { "Skull Bash Start (Ground)", 0x
    { "Skull Bash Charge (Ground)", 0x
    { "Skull Bash 1 (Ground)", 0x
    { "Skull Bash 2 (Ground)", 0x
    { "Skull Bash End (Ground)", 0x
    { "Skull Bash Start (Aerial)", 0x
    { "Skull Bash Charge (Aerial)", 0x
    { "Skull Bash (Aerial)", 0x
    { "Skull Bash End (Aerial)", 0x
    { "Quick Attack Start 1 (Ground)", 0x
    { "Quick Attack Start 2 (Ground)", 0x
    { "Quick Attack End (Ground)", 0x
    { "Quick Attack Start 1 (Aerial)", 0x
    { "Quick Attack Start 2 (Aerial)", 0x
    { "Quick Attack End (Aerial)", 0x
    { "Thunder Start (Ground)", 0x
    { "Thunder Loop 1 (Ground)", 0x
    { "Thunder Loop 2 (Ground)", 0x
    { "Thunder End (Ground)", 0x
    { "Thunder Start (Aerial)", 0x
    { "Thunder Loop 1 (Aerial)", 0x
    { "Thunder Loop 2 (Aerial)", 0x
    { "Thunder End (Aerial)", 0x
};
*/

vector<subaction> Ganondorf_subaction_list =
{
    { "Warlock Punch (Ground)", 0x12d },
    { "Warlock Punch (Aerial)", 0x12e },
    { "Gerudo Dragon Start (Ground)", 0x12f },
    { "Gerudo Dragon (Ground)", 0x130 },
    { "Gerudo Dragon Start (Aerial)", 0x131 },
    { "Gerudo Dragon (Aerial)", 0x132 },
    { "Dark Dive (Ground)",  0x133 },
    { "Dark Dive (Aerial)", 0x134 },
    { "Dark Dive Grab", 0x135 },
    { "Dark Dive Release", 0x136 },
    { "Wizard's Foot (Ground)", 0x137 },
    { "Wizard's Foot End (Ground)", 0x138 },
    { "Wizard's Foot (Aerial)", 0x139 },
    { "Wizard's Foot Aerial Landing", 0x13a },
    { "Wizard's Foot (Ground End in Air)", 0x13b },
    { "Wizard's Foot (Aerial End in Air)", 0x13c }
};