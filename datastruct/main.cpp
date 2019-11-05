#include <iostream>
#include "List.h"

int main() {

    List<int>linkedlist;
    int count;

    for (int i = 1; i <= 10; i++) {
        linkedlist.append(i);
    }

    linkedlist.remove_at(1);
    linkedlist.remove_at(3);
    linkedlist.remove_at(7);

    linkedlist.print_list();
    count = linkedlist.list_count();
    std::cout << "List size: " << count << "\n";

    List<int>linkedlist2(linkedlist);
    linkedlist2.print_list();
    
    return 0;

}
