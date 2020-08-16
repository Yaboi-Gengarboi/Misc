// RPGGame
// MiscInfo.cpp
// Justyn Durnford
// Created on 8/16/2020
// Last updated on 8/16/2020

#include "MiscInfo.h"

unsigned short protection_chance[10] =
{
	0,
	500,
	750,
	875,
	937,
	968,
	983,
	990,
	993,
	995
};

unsigned short get_protection_chance(unsigned char time)
{
	if (time > 10)
		return protection_chance[10];

	return protection_chance[time];
}