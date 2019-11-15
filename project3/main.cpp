#include "Student.h"
#include "dList.h"
#include "dNode.h"
#include "interface.h"
#include <iostream>

int main ()
{

	
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
	
	return 0;
}
