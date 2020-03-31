// main_file.cpp
// Justyn Durnford
// Created on 3/23/2020
// Last updated on 3/23/2020

#include <random>
using std::random_device;

#include <vector>
using std::vector;
using std::size_t;

#include <iostream>
using std::cout;
using std::endl;

random_device rDev;

unsigned long xorshf96()
{
    static unsigned long x = 123456789, y = 362436069, z = 521288629;
    unsigned long t;

    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;

    t = x;
    x = y;
    y = z;
    z = t ^ x ^ y ^ rDev();

    return z;
}

int main()
{
	return 0;
}