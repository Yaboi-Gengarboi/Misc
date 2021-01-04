// Pair.h
// Justyn Durnford
// Created on 2020-10-07
// Updated on 2020-10-07
// Header file for Pair template class

#ifndef PAIR_H_INCLUDED
#define PAIR_H_INCLUDED

template <typename type_A, typename type_B>
struct Pair
{
	type_A _a;
	type_B _b;

	// Deafult constructor.
	Pair() = default;

	// Copy constructor.
	Pair(const Pair& pair)
	{
		_a = pair._a;
		_b = pair._b;
	}

	// Move constructor.
	Pair(Pair&& pair)
	{
		mswap(pair);
	}

	// 2-parameter constructor.
	Pair(type_A a, type_B b)
	{
		_a = a;
		_b = b;
	}

	// Copy assignment.
	Pair& operator = (const Pair& pair)
	{
		_a = pair._a;
		_b = pair._b;

		return *this;
	}

	// Move assignment.
	Pair& operator = (Pair&& pair)
	{
		mswap(pair);
		return *this;
	}
	
	// Destructor.
	~Pair() = default;

	private:

	void mswap(Pair& other)
	{
		type_A a = _a;
		type_B b = _b;

		_a = other._a;
		_b = other._b;

		other._a = a;
		other._b = b;
	}
};

#endif // PAIR_H_INCLUDED