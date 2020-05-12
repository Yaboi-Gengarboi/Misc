// HGame
// Misc.hpp
// Justyn Durnford
// Created on 5/5/2020
// Last updated on 5/8/2020

#ifndef MISC_HPP
#define MISC_HPP

#include "Room.hpp"

// #include <memory>
// #include <vector>

unsigned char rand_1_20();

std::shared_ptr<Room> pick_rand_room(const std::vector<std::shared_ptr<Room>>& nextRooms);

#endif // MISC_HPP