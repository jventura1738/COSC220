// Justin Ventura (COSC220-003)
// Project 3 (modified 11/14/19)
// File: interface.cpp (Justin Ventura)

#include "interface.h"
#include "Student.h"
#include <string>
#include <iostream>

void welcomeSDB()
{
	std::cout << "========================================\n";
	std::cout << "|    ♢ Justin's Student Database ♢     |\n";
	std::cout << "|                                      |\n";
	std::cout << "|  1) Add a Student                    |\n";
	std::cout << "|  2) Remove a Student                 |\n";
	std::cout << "|  3) View the Database                |\n";
	std::cout << "|  4) Search Student by  ↳             |\n";
	std::cout << "|  5) Sort Database by   ↳             |\n";
	std::cout << "|  6) Reset Database     ↻             |\n";
	std::cout << "|  7) Quit Application                 |\n";
	std::cout << "|                                      |\n";
	std::cout << "========================================\n";
}

// Get the user's input (Validated)
int getChoice()
{
    int choice;
    std::cout << "---> ";
    std::cin >> choice;

    while (choice > 9 || choice < 1)
    {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Invalid, re-enter ---> ";
        std::cin >> choice;
    }

    while (!std::cin.good())
    {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Invalid, re-enter ---> ";
        std::cin >> choice;
    }

    return choice;
}

void qualifyEntry(Student & student)
{
	std::string temp = student.getName();
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == ' ')
			temp[i] = '_';
	}
	student.setName(temp);
}

void revertEntry(Student & student)
{
	std::string temp = student.getName();
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == '_')
			temp[i] = ' ';
	}
	student.setName(temp);
}

void updateDatabase(Student &student)
{
	qualifyEntry(student);

	std::ifstream infile;
	infile.open("database.txt");

	// If database not empty, newline.
	bool flag = false;
	infile.seekg(0, std::ios::end);  
	if (infile.tellg() != 0)
	{
		flag = true;
		std::cout << "flag\n"; 
	}   

  	infile.close();

	std::ofstream outfile;
	outfile.open("database.txt", std::ios_base::app);

	std::string tempName = student.getName();
	int tempID = student.getID();
	int tempYear = student.getYear();
	float tempGPA = student.getGPA();

	if (flag) outfile << "\n";

	outfile << tempID << " " << tempName << " " 
			<< tempYear << " " << tempGPA;

	revertEntry(student);

	outfile.close();
}

// Clears the Database File.
void clearDatabase()
{
	std::ifstream outfile;
	outfile.open("database.txt");
	outfile.close();
}

// ALLOCATES DYNAMIC MEMORY
void extractData(dList<Student> & list)
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
	if (!list.isEmpty())
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
		std::cout << "=========================================\n";
		std::cout << tempName << tempID << tempYear << tempGPA << "\n";
		std::cout << "=========================================\n";

		Student s(tempName, tempID, tempYear, tempGPA);
		list.append(s);
	}

	// Close the file stream.
	infile.close(); 
}

