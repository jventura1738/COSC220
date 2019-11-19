// Justin Ventura (COSC220-003)
// Project 3 (modified 11/14/19)
// File: interface.cpp (Justin Ventura)

#include "interface.h"
#include "Student.h"
#include <string>
#include <iostream>
#include <stdlib.h>

void welcomeSDB()
{
	std::cout << std::string(50, '\n');
	std::cout << "==================================================\n";
	std::cout << "|         ♢ Justin's Student Database ♢          |\n";
	std::cout << "|                                                |\n";
	std::cout << "|  1) Add a Student                              |\n";
	std::cout << "|  2) Remove a Student                           |\n";
	std::cout << "|  3) View the Database                          |\n";
	std::cout << "|  4) Search Student by  ↳ ?                     |\n";
	std::cout << "|  5) Sort Database by   ↳ ?                     |\n";
	std::cout << "|  6) Reset Database     ↻                       |\n";
	std::cout << "|  7) Quit Application                           |\n";
	std::cout << "|                                                |\n";
	std::cout << "==================================================\n";
}

void dispInterface()
{
	std::cout << std::string(50, '\n');
	std::cout << "==================================================\n";
	std::cout << "|         ♢ Justin's Student Database ♢          |\n";
	std::cout << "==================================================\n";
}

// Search Student by Name.
void searchByName(std::string key, dNode<Student> * header)
{
	int matchCount = 0, i, j;
	bool match = false;
	std::cout << "        Student          |    ID    | year | GPA\n";
	dNode<Student> * curr = header->next;
	//std::cout << "first " << curr->data.getName()[i] << " - " << key[i] << "\n";
	while (curr != header)
	{
		// TODO: FIX THE SEARCH FOR SECOND WORD
		i = 0; // for DATABASE index
		j = 0; // for KEY index
		//std::cout << curr->data.getName()[i] << " - " << key[i] << "\n";

		// Check for a match in the first word.
		while (curr->data.getName()[i] == key[j])
		{
			//std::cout << curr->data.getName()[i] << " " << key[i] << " " << i << "\n"; 

			// Skip increment if word ends.
			if (curr->data.getName()[i + 1] == ' ')
			{
				if ((i + 1) == key.size())
				{
					match = true;
					matchCount++;
					break;
				}
				else
				{
					while (curr->data.getName()[i] == ' ')
						i++;

					j = 0;
					continue;
				}
			}
			j++;
			i++;
		}

		// Print the match.
		if (match)
		{
			std::cout << curr->data;
			match = false;
		}

		curr = curr->next;
	}
	if (matchCount == 0)
	{
		std::cout << "NO MATCHES FOUND.\n";
		return;
	}
	else
		std::cout << "\nTotal matches found: " << matchCount << "\n";

}

// Search Student by ID.
void searchByID(int key, dNode<Student> * header)
{
	std::cout << "        Student          |    ID    | year | GPA\n";
}

// Gets 0 or 1 for binary choices
bool binaryChoice()
{
	int choice;
    std::cout << "---> ";
    std::cin >> choice;

    while (!std::cin.good() || (choice > 1 || choice < 0))
    {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Invalid, re-enter ---> ";
        std::cin >> choice;
    }

    if (choice == 0)
    	return false;
    else 
    	return true;

}

// Get the user's input (Validated)
int getChoice()
{
    int choice;
    std::cout << "---> ";
    std::cin >> choice;

    while (!std::cin.good() || (choice > 7 || choice < 1))
    {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Invalid, re-enter ---> ";
        std::cin >> choice;
    }

    return choice;
}

bool confirmReset()
{
	int confirm;
	std::cout << "(!!!) Reset Database? Enter -1 to confirm. (!!!)\n";
	std::cin >> confirm;
	while (!std::cin.good())
    {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Invalid, re-enter ---> ";
        std::cin >> confirm;
    }
    if (confirm == -1)
    	return true;
    else
    	return false;
}

void qualifyEntry(Student * student)
{
	std::string temp = student->getName();
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == ' ')
			temp[i] = '_';
	}
	student->setName(temp);
}

void revertEntry(Student * student)
{
	std::string temp = student->getName();
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == '_')
			temp[i] = ' ';
	}
	student->setName(temp);
}

// Clears the Database File.
void clearDatabase()
{
	std::ifstream outfile;
	outfile.open("database.txt", std::ofstream::out | std::ofstream::trunc);
	outfile.close();
}

void updateDatabase(Student * student)
{
	qualifyEntry(student);

	// Check database with ifstream
	std::ifstream infile;
	infile.open("database.txt");

	// If database not empty, newline.
	bool flag = false;
	infile.seekg(0, std::ios::end);  
	if (infile.tellg() != 0)
		flag = true; 

  	infile.close();

  	// Update database with ofstream
	std::ofstream outfile;
	outfile.open("database.txt", std::ios_base::app);

	std::string tempName = student->getName();
	int tempID = student->getID();
	int tempYear = student->getYear();
	float tempGPA = student->getGPA();

	if (flag) outfile << "\n";

	outfile << tempID << " " << tempName << " " 
			<< tempYear << " " << tempGPA;

	revertEntry(student);

	outfile.close();
}

// Call whenever list strays from database
void syncDatabase(dNode<Student> * header)
{
	// Clear database to refresh
	clearDatabase();
	dNode<Student> * curr = header->next;
	while (curr != header)
	{
		updateDatabase(&curr->data);
		curr = curr->next;
	}
}

// Extract Student Data from Database
void extractData(dList<Student> * list)
{
	// Prepare the file stream. If the file
	// is empty, nothing to extract.
	std::ifstream infile;
	infile.open("database.txt");

	// If database empty, return.
	infile.seekg(0, std::ios::end);  
	if (infile.tellg() == 0)   
  		return;

	// If list is not empty give a warning.
	if (!list->isEmpty())
		std::cout << "--Warning, list should be empty.\n";

	// Variables needed to extract data.
	std::string tempName;
	int tempID, tempYear;
	float tempGPA;

	// Read in one line at a time, grabbing the
	// data needed for each student.
	infile.clear();
	infile.seekg(0, std::ios::beg);
	while (!infile.eof())
	{
		infile >> tempID >> tempName >> tempYear >> tempGPA;
		Student *s = new Student(tempName, tempID, tempYear, tempGPA);
		
		// Revert to regular string form and append.
		revertEntry(s);
		list->append(s);
	}

	// Close the file stream.
	infile.close(); 
}
