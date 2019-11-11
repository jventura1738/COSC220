#include "Student.h"
#include <iostream>

int main ()
{
	Student s1;
	s1.setName("Justin Ventura");
	s1.setID(3071913);
	s1.setYear(2);
	s1.setGPA(4.0);
	std::cout << "                         |          |     |\n";
	std::cout << s1 << "\n";
	
	return 0;
}
