// RPGGame
// Weather.h
// Justyn Durnford
// Created on 2020-06-20
// Last updated on 2020-09-24

#ifndef WEATHER_H_INCLUDED
#define WEATHER_H_INCLUDED

#include <array>
#include <string>

class Weather
{
	unsigned char _id;
	std::string _beginStr;
	std::string _endStr;

	public:

	Weather() = default;
	Weather(const Weather& weather) = default;
	Weather(Weather&& weather) = default;

	Weather(unsigned char id, const char* beginStr, const char* endStr);

	Weather& operator = (const Weather& weather) = default;
	Weather& operator = (Weather&& weather) = default;

	~Weather() = default;

	unsigned char id() const;

	std::string beginStr() const;

	std::string endStr() const;
};

extern std::array<Weather, 7> weather_arr;

#endif // WEATHER_H_INCLUDED