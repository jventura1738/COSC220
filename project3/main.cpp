#include "Student.h"
#include "dList.h"
#include "dNode.h"
#include "interface.h"
#include <iostream>
#include <stdlib.h>
#include <limits>

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

		// Add student to database [FUNCTIONAL]
		if (choice == 1)
		{
			dispInterface();
			Student s;
			std::cin.ignore();
			std::cin >> s;
			database->append(s);
			updateDatabase(s);
		}
		// Remove a student.
		else if (choice == 2)
		{
			dispInterface();
			std::cout << "TODO: rm student\n";
		}
		// Print students in order/reverse.
		else if (choice == 3) // [FUNCTIONAL]
		{
			std::cout << "Print database in order or reverse?\n";
			std::cout << "1 for order, 0 for reverse.\n";
			bool order = binaryChoice();
			if (order)
			{
				dispInterface();
				std::cout << "        Student          |    ID    | year | GPA\n";
				database->printOrder();
				std::cout << "==================================================\n";
				std::cout << "Total Students in database: " << database->size();
				std::cout << "\n\nPress <Enter> to continue...";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin.get();
			}
			else
			{
				dispInterface();
				std::cout << "        Student          |    ID    | year | GPA\n";
				database->printReverse();
				std::cout << "==================================================\n";
				std::cout << "Total Students in database: " << database->size();
				std::cout << "\n\nPress <Enter> to continue...";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin.get();
			}
		}
		// Search Student by ...
		else if (choice == 4)
		{
			dispInterface();
			std::cout << "Search student by name (1) or ID (0)?\n";
			bool choice = binaryChoice();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			if (choice) // Search by name
			{
				std::string nameKey;
				std::cout << "Enter name of student: ";
				getline(std::cin, nameKey);
				dispInterface();
				searchByName(nameKey, database->getHeader());
				std::cout << "\nPress <Enter> to continue...";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else		// Search by ID
			{
				int keyID;
				std::cout << "Enter ID of student: ";
				std::cin >> keyID;
				dispInterface();
				//searchByID(keyID, database->getHeader());
			}
		}
		else if (choice == 5)
		{
			dispInterface();
			std::cout << "TODO: sort students.\n";
		}
		// Reset database.txt [FUNCTIONAL]
		else if (choice == 6)
		{
			bool confirm = confirmReset();
			if (confirm)
			{
				clearDatabase();
				delete database;
				database = new dList<Student>;
				std::cout << "Database clear.";
				std::cout << "\nPress <Enter> to continue...";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin.get();
			}
			else
			{
				std::cout << "Reset cancelled.";
				std::cout << "\nPress <Enter> to continue...";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin.get();
			}
		}
		else if (choice == 7) // [FUNCTIONAL]
		{
			std::cout << "Thank you for using Justin's Student DB Software!\n";
			run_program = false;
		}

	} while (run_program);

	delete database;

	return 0;
}
