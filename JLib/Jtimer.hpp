// Jtimer.hpp
// Justyn Durnford
// Created on 4/2/2020
// Last updated on 5/11/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#ifndef JTIMER_HPP
#define JTIMER_HPP

#include <string>
#include <chrono>

class Jtimer
{
	std::chrono::time_point<std::chrono::system_clock> _start;
	std::chrono::time_point<std::chrono::system_clock> _end;
	bool _is_stopped = false;

	public:

	// Constructor
	Jtimer();

	// Destructor
	~Jtimer();

	// Sets the value of _start
	void start();

	// Sets the value of _end
	void stop();

	// Returns the amount of seconds that have passed
	double secondsPassed() const;

	// Returns the amount of milliseconds that have passed
	double millisecondsPassed() const;

	std::string toString() const;
};

#endif // JTIMER_HPP