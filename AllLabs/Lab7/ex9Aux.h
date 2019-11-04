// Justin Ventura
// LAB7 FILES   
#ifndef ACCUMULATOR_H
#define ACCUMULATOR_H

template <typename T>
class accumulator
{
public:
	accumulator (const T& value=T()); //constrctor
	T getTotal() const;           //return total
	void addValue(const T& value);	// add (+) value to total

private:
	T total; //total accumulated by the object
};

#include "ex9Aux.cpp"
#endif
