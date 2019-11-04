// Justin Ventura
// LAB7 FILES   
#include "ex9Aux.h"

template <typename T>
accumulator<T>::accumulator (const T& value) //constructor
{
    total = value;
}

template <typename T>
T accumulator<T>::getTotal() const       //return total
{ return total; }

template <typename T>
void accumulator<T>::addValue(const T& value)	// add (+) value to total
{
    total += value;
}
