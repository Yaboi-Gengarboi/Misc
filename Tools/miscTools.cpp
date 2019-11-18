/*
miscTools.cpp
Justyn P. Durnford
Created on 11/18/2019
*/

#include "miscTools.hpp"

template <typename Type>
void printVec(const vector<Type>& vec)
{
	for (const auto& t : vec)
		cout << t << " ";
	cout << endl;
}

template <typename Type>
void deallocate(const Type* pointer)
{
	delete pointer;
}