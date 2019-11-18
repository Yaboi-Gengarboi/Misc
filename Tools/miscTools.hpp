/*
miscTools.hpp
Justyn P. Durnford
Created on 11/18/2019
*/

#ifndef MISCTOOLS_HPP
#define MISCTOOLS_HPP

#include <vector>
using std::vector;

template <typename Type>
void printVec(const vector<Type>& vec);

template <typename Type>
void deallocate(const Type* pointer);

#endif