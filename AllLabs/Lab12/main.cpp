// Justin Ventura
// COSC220-003
#include "List.h"
#include "d_List.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
	/*
	// (1)
	std::cout << "(1) and (2), list array.\n";
	List<int> list;
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		int temp = (rand()%20 + 1);
		std::cout << "Inserting: " << temp << "\n";
		list.insert(temp);
	}
	std::cout << "=======List status=======\n\n";
	std::cout << "# of elements: " << list.listSize();
	std::cout << "\n\nCurrent list elements: \n";
	list.display();
	std::cout << "\n";

	// (3 & 4)
	std::cout << "(3) & (4) adding sequence.\n";
	int arr[5];
	arr[0] = 2;
	arr[1] = 1;
	arr[2] = 3;
	arr[3] = 5;
	arr[4] = 4;
	for (int i = 0; i < 5; i++)
	{
		list.append(arr[i]);
	}
	std::cout << "=======List status=======\n\n";
	std::cout << "# of elements: " << list.listSize();
	std::cout << "\n\nCurrent list elements: \n";
	list.display();
	std::cout << "\n";
	for (int i = 0; i < 5; i++)
	{
		list.prepend(arr[i]);
	}
	std::cout << "=======List status=======\n\n";
	std::cout << "# of elements: " << list.listSize();
	std::cout << "\n\nCurrent list elements: \n";
	list.display();
	std::cout << "\n";

	// (5)
	int key;
	std::cout << "(5) Enter a value to remove: ";
	std::cin >> key;
	list.remove(key);
	std::cout << "=======List status=======\n\n";
	std::cout << "# of elements: " << list.listSize();
	std::cout << "\n\nCurrent list elements: \n";
	list.display();
	std::cout << "\n";

	// (6)
	std::cout << "(6) Enter value to search in list: ";
	std::cin >> key;
	if (list.isInList(key))
	{
		std::cout << "Key is in list.\n";
	}
	else
		std::cout << "Key not in list.\n";

	std::cout << "=======List status=======\n\n";
	std::cout << "# of elements: " << list.listSize();
	std::cout << "\n\nCurrent list elements: \n";
	list.display();
	std::cout << "\n";
	*/

	dList<int> list;

	for (int i = 1; i < 6; i++)
	{
		list.append(i);
	}
	list.prepend(0);
	list.display();

	dNode<int> temp = list.search(2);
	list.putBefore(&temp, 0);

	list.display();

    return 0;
}
