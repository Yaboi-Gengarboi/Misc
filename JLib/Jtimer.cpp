// Jtimer.cpp
// Justyn Durnford
// Created on 4/2/2020
// Last updated on 5/11/2020

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://www.wtfpl.net/ for more details.

#include "Jtimer.hpp"

// #include <chrono>
#include <chrono>
using std::chrono::time_point;
using std::chrono::system_clock;
using std::chrono::duration;

Jtimer::Jtimer()
{
	_start = system_clock::now();
}

Jtimer::~Jtimer() { /* Destructor */ }

void Jtimer::start()
{
	_start = system_clock::now();
	_is_stopped = false;
}

void Jtimer::stop()
{
	_end = system_clock::now();
	_is_stopped = true;
}

double Jtimer::secondsPassed() const
{
	duration<double> time_elapsed;

	if (_is_stopped)
		time_elapsed = _end - _start;

	else
		time_elapsed = system_clock::now() - _start;

	return time_elapsed.count();
}

double Jtimer::millisecondsPassed() const
{
	duration<double> time_elapsed;

	if (_is_stopped)
		time_elapsed = _end - _start;

	else
		time_elapsed = system_clock::now() - _start;

	return time_elapsed.count() * 1000;
}