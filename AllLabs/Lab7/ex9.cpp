// Justin Ventura
// LAB7 FILES   
#include "ex9Aux.h"
#include "time24.h"
#include <iostream>

int main()
{
    accumulator<int> obj1(5);
    for(int i = 2; i < 7; i++)
    {
        obj1.addValue(i*5);
    }
    std::cout << obj1.getTotal() << "\n\n";

    accumulator<std::string> obj2("6669001 ");
    obj2.addValue("Moe Lester ");
    obj2.addValue("42069 Mike Hunt's Way ");
    obj2.addValue("Gender Studies");
    std::cout << obj2.getTotal() << "\n\n";

    accumulator<Time24> obj3(Time24(4,30));
    obj3.addValue(Time24(13,15));
    obj3.addValue(Time24(1,45));
    obj3.addValue(Time24(16,0));
    std::cout << obj3.getTotal() << "\n";

    return 0;
}
