// Justin Ventura (COSC220-003)
// Project 3 (modified 11/21/19)
// File: main.cpp (Justin Ventura)
// NOTE: This file is for the main
// executable for the database.
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
		// Remove a student. [FUNCTIONAL]
		else if (choice == 2)
		{
			dispInterface();
			if (database->isEmpty())
			{
				std::cout << "Database is Empty! Please re-check database.\n";
				std::cout << "[Be sure to sync the database with data struct]\n";
				std::cout << "\n\nPress <Enter> to continue...";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin.get();
				continue;
			}
			int IDremove;
			bool attempt = true;
			bool removed = false;
			std::cout << "        Student          |    ID    | year | GPA\n";
			database->printOrder();
			std::cout << "==================================================\n";
			while (attempt)
			{
				std::cout << "Enter exact ID of student to be removed: ";
				std::cout << "---> ";
				std::cin >> IDremove;
				while (!std::cin.good())
				{
					std::cin.clear();
			        std::cin.ignore(INT32_MAX, '\n');
			        std::cout << "Invalid, re-enter ---> ";
			        std::cin >> IDremove;
				}
				dNode<Student> *temp = database->getHeader();
				dNode<Student> *curr = temp->next;

				while (curr != temp)
				{
					if (curr->data.getID() == IDremove)
					{
						database->removeNode(curr);
						std::cout << "Student with ID: " << IDremove << " removed.\n";
						std::cout << "\nPress <Enter> to continue...";
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cin.get();
						attempt = false;
						removed = true;
						syncDatabase(temp);
						break;
					}
					curr = curr->next;
				}
				if (!removed)
				{
					std::cout << "Student not found.\n";
					std::cout << "Try again? (1) yes (0) no: ";
					attempt = binaryChoice();
				}
			}
		}
		// Print students in order/reverse.
		else if (choice == 3) // [FUNCTIONAL]
		{
			dispInterface();
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
				//reverseList(database->getHeader());
				std::cout << "        Student          |    ID    | year | GPA\n";
				database->printReverse();
				std::cout << "==================================================\n";
				std::cout << "Total Students in database: " << database->size();
				std::cout << "\n\nPress <Enter> to continue...";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin.get();
			}
		}
		// Search Student by ... [FUNCTIONAL]
		else if (choice == 4)
		{
			dispInterface();
			if (database->getHeader()->next == database->getHeader())
			{
				std::cout << "Database is Empty! Please re-check database.\n";
				std::cout << "[Be sure to sync the database with data struct]\n";
				std::cout << "\nPress <Enter> to continue...";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin.get();
				continue;
			}
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
				std::cin.get();
			}
			else		// Search by ID
			{
				int keyID;
				std::cout << "Enter ID of student: ";
				std::cin >> keyID;
				dispInterface();
				searchByID(keyID, database->getHeader());
				std::cout << "\nPress <Enter> to continue...";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin.get();
			}
		}
		// Sort Database by ... [FUNCTIONAL]
		else if (choice == 5)
		{
			if (database->getHeader()->next == database->getHeader())
			{
				std::cout << "Database is Empty! Please re-check database.\n";
				std::cout << "[Be sure to sync the database with data struct]\n";
				std::cout << "\nPress <Enter> to continue...";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin.get();
				continue;
			}
			dispInterface();
			std::cout << "Sort database by (0) name (1) ID\n";
			bool choice = binaryChoice();
			database->unchain();
			dNode<Student> *temp = database->getHeader();
			if (choice)		// Sort by ID
			{
				mergeSortID(temp);
				dNode<Student> * curr = database->getHeader();
				while (curr->prev)
					curr = curr->prev;
				database->setHeader(curr);
				database->chain();
				dispInterface();
				std::cout << "======= Database successfully sorted by ID =======\n";
				std::cout << "        Student          |    ID    | year | GPA  \n";
				database->printOrder();
				std::cout << "==================================================\n";
				std::cout << "\nPress <Enter> to continue...";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin.get();
			}
			else			// Sort by Name
			{
				//temp = temp->next;
				//temp->prev = nullptr;
				mergeSortName(temp);
				dNode<Student> * curr = database->getHeader();
				while (curr->prev)
					curr = curr->prev;
				database->setHeader(curr);
				database->chain();
				dispInterface();
				std::cout << "====== Database successfully sorted by Name ======\n";
				std::cout << "        Student          |    ID    | year | GPA  \n";
				database->printOrder();
				std::cout << "==================================================\n";
				std::cout << "\nPress <Enter> to continue...";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin.get();
			}
			syncDatabase(database->getHeader());
		}
		// Reset database.txt [FUNCTIONAL]
		else if (choice == 6)
		{
			if (database->getHeader()->next == database->getHeader())
			{
				std::cout << "Database is Empty! Please re-check database.\n";
				std::cout << "[Be sure to sync the database with data struct]\n";
				std::cout << "\nPress <Enter> to continue...";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin.get();
				continue;
			}
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
