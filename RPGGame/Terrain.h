// RPGGame
// Terrain.h
// Justyn Durnford
// Created on 2020-09-24
// Last updated on 2020-09-29

#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED

#include <array>
#include <string>

class Terrain
{
	unsigned char _id = 0;
	std::string _beginStr;
	std::string _endStr;

	public:

	Terrain() = default;
	Terrain(const Terrain& weather) = default;
	Terrain(Terrain&& weather) = default;

	Terrain(unsigned char id, const char* beginStr, const char* endStr);

	Terrain& operator = (const Terrain& weather) = default;
	Terrain& operator = (Terrain&& weather) = default;

	~Terrain() = default;

	unsigned char id() const;

	std::string beginStr() const;

	std::string endStr() const;
};

extern std::array<Terrain, 5> terrain_arr;

#endif // TERRAIN_H_INCLUDED