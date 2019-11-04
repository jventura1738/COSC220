// Justin Ventura COSC220-003
// LAB8: hanoi.cpp
#include "hanoi.h"

void hanoi(unsigned n, char start, char aux, char end)
{
    if (n == 1) std::cout << "Move disk " << n << " from " << start << " to " << end << "\n";
    else
    {
        hanoi(n - 1, start, end, aux);
        std::cout << "Move disk " << n << " from " << start << " to " << end << "\n";
        hanoi(n - 1, aux, start, end);
    }
}


/*  void hanoi (n, A, B, C)
 *  if n = 1, move n from A to C
 *  else
 *  hanoi(n - 1, A, C, B)
 *  move n from A to C
 *  hanoi(n - 1, B, A, C)
 */
