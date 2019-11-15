#include "Student.h"
#include "dList.h"
#include "dNode.h"
#include "interface.h"
#include <iostream>
#include <stdlib.h>

int main ()
{
	dList<Student> *database = new dList<Student>;
	extractData(database);
	std::cout << database->size() << "\n";
	bool run_program = true;
	do
	{
		welcomeSDB();
		int choice = getChoice();

		// Add student to database.
		if (choice == 1)
		{
			dispInterface();
			Student *s = new Student;
			std::cin.ignore();
			std::cin >> *s;
			database->append(s);
			updateDatabase(s);
		}
		// Remove a student.
		else if (choice == 2)
		{
			dispInterface();
			std::cout << "TODO: rm student\n";
		}
		// Print students in order.
		else if (choice == 3)
		{
			dispInterface();
			std::cout << "";
			database->printOrder();
			std::cout << "\nPress <Enter> to continue...";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();
		}
		// Search Student by ...
		else if (choice == 4)
		{
			dispInterface();
			std::cout << "TODO: search student.\n";
		}
		else if (choice == 5)
		{
			dispInterface();
			std::cout << "TODO: sort students.\n";
		}
		else if (choice == 6)
		{
			clearDatabase();
			delete database;
			database = new dList<Student>;
		}
		else run_program = false;

	} while (run_program);
	
	delete database;

	//Student s1("Justin Ventura", 3071913, 2, 4.0);
	//Student s2("Jacob Duncan", 3071914, 2, 4.0);
	//database.prepend(s1);
	//updateDatabase(s1);
	//database.append(s2);
	// updateDatabase(s2);

	return 0;
}
