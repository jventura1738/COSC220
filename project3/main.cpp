#include "Student.h"
#include "dList.h"
#include "dNode.h"
#include "interface.h"
#include <iostream>
#include <stdlib.h>

int main ()
{
	dList<Student> database;
	extractData(database);
	//welcomeSDB();
	//std::cout << database.size() << "\n";
	// Student s1("Justin Ventura", 3071913, 2, 4.0);
	// Student s2("Jacob Duncan", 3071914, 2, 4.0);
	// database.prepend(s1);
	// updateDatabase(s1);
	// database.append(s2);
	// updateDatabase(s2);

	database.printOrder();
	// dNode<Student> *node = database.getHeader();
	// std::cout << node->next->data << "\n";
	
	/*
	Student s1("Justin Ventura", 3071913, 2, 4.00);
	updateDatabase(s1);

	dList<Student> list;
	extractData(list);

	std::ifstream infile;
	infile.open("database.txt");

	std::string temp;

	while (!infile.eof())
	{
		infile >> temp;
		std::cout << temp << " ";
	}
	std::cout << "\n";
	*/
	return 0;
}
