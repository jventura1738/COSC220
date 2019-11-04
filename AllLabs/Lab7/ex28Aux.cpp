// Justin Ventura
// LAB7 FILES   
#include "ex28Aux.h"

template <typename T>
void f(const T aList[ ], int n, T bList[ ], int& m, const T& target)
{
	int i, j = 0;

	for(i = 0; i < n; i++)
		if (aList[i] != target)
		{
			bList[j] = aList[i];
			j++;
		}

	m = j;
}
