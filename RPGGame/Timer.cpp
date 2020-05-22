// RPGGame
// Timer.cpp
// Justyn Durnford
// Created on 4/2/2020
// Last updated on 5/22/2020

#include "Timer.hpp"

#include <chrono>
using std::chrono::milliseconds;
using std::chrono::time_point;
using std::chrono::system_clock;
using std::chrono::duration;

#include <thread>
using std::this_thread::sleep_for;

Timer::Timer() {}

Timer::~Timer() { /* Destructor */ }

void Timer::start()
{
	_start = system_clock::now();
	_is_stopped = false;
}

void Timer::stop()
{
	_end = system_clock::now();
	_is_stopped = true;
}

float Timer::secondsPassed() const
{
	duration<double> time_elapsed;

	if (_is_stopped)
		time_elapsed = _end - _start;

	else
		time_elapsed = system_clock::now() - _start;

	return time_elapsed.count();
}

float Timer::millisecondsPassed() const
{
	duration<double> time_elapsed;

	if (_is_stopped)
		time_elapsed = _end - _start;

	else
		time_elapsed = system_clock::now() - _start;

	return time_elapsed.count() * 1000;
}

void wait(unsigned int time)
{
	sleep_for(milliseconds(time));
}