// RPGGame
// Trainer.h
// Justyn Durnford
// Created on 6/30/2020
// Last updated on 6/30/2020

#ifndef TRAINER_H
#define TRAINER_H

#include "Player_Pokemon.h"

#include <string>
#include <vector>

//
//
//
class Trainer
{
	std::string _name = "";
	unsigned short _id = 0;
	std::vector<Player_Pokemon> _party;

	public:

	Trainer();

	~Trainer();
};

#endif // TRAINER_H