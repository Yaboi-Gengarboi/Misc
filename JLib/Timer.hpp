// Timer.hpp
// Justyn Durnford
// Created on 4/2/2020
// Last updated on 6/11/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

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
	double secondsPassed() const;

	// Returns the amount of milliseconds that have passed
	double millisecondsPassed() const;

	void wait(unsigned int time);
};

#endif // TIMER_HPP