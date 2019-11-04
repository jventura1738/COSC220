// Justin Ventura
// LAB7 FILES   
#include "ex28Aux.h"
#include <iostream>

int main()
{
    int intListA[5]  = {1, 9, 3, 9, 5}, intListB[5];
    int m;
    f(intListA, 5, intListB, m, 9);

    std::cout << "m: " << m << std::endl;
    std::cout << "contents of B: " << std::endl;
    for(int i = 0; i < m; i++)
    {
        std::cout << intListB[i] << " ";
    }
    std::cout << "\n\n";

    std::string strListA[7]={"cat", "rat", "bird", "dog", "rat", "fish", "rat"},     strListB[7];
    int m;
    f(strListA, 7, strListB, m, std::string("rat"));

    std::cout << "m: " << m << std::endl;
    std::cout << "contents of B: " << std::endl;
    for(int i = 0; i < m; i++)
    {
        std::cout << strListB[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
