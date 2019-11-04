// Justin Ventura COSC220-003
// LAB9: lab9aux.h

#ifndef LAB9AUX_H
#define LAB9AUX_H

#include <vector>
#include <algorithm>
#include <iostream>

template <typename T>
void removeDup(std::vector<T> & v);

template <typename T>
void removeDup2(std::vector<T> & v);

template <typename T>
void removeDup3(std::vector<T> & v);

template <typename T>
unsigned seqVectSearch(const std::vector<T> & v, unsigned first,
		       unsigned last, const T& target);

template <typename T>
void writeVector(const std::vector<T> & v);

#include "lab9aux.cpp"

#endif
