// RPGGame
// Timer.hpp
// Justyn Durnford
// Created on 5/22/2020
// Last updated on 5/22/2020

#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>

class Timer
{
	std::chrono::time_point<std::chrono::system_clock> _start;
	std::chrono::time_point<std::chrono::system_clock> _end;
	bool _is_stopped = false;

	public:

	// Constructor
	Timer();

	// Destructor
	~Timer();

	// Sets the value of _start
	void start();

	// Sets the value of _end
	void stop();

	// Returns the amount of seconds that have passed
	float secondsPassed() const;

	// Returns the amount of milliseconds that have passed
	float millisecondsPassed() const;
};

void wait(unsigned int time);

#endif // TIMER_HPP