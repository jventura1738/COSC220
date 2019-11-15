// Justin Ventura (COSC220-003)
// Project 3 (modified 11/14/19)
// File: interface.cpp (Justin Ventura)

#include "interface.h"
#include "Student.h"

void welcome()
{
	
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

void clearDatabase()
{
	std::ifstream outfile;
	outfile.open("database.txt");
	outfile.close();
}

void updateDatabase(Student &student)
{
	qualifyEntry(student);

	std::ofstream outfile;
	outfile.open("database.txt", std::ios_base::app);

	std::string tempName = student.getName();
	int tempID = student.getID();
	int tempYear = student.getYear();
	float tempGPA = student.getGPA();

	outfile << tempName << " " << tempID << " " <<
			   tempYear << " " << tempGPA << "\n";

	revertEntry(student);

	outfile.close();
}

//template <typename T>
void extractData(dList<Student> & list)
{
	// If list is not empty give a warning.
	if (!list.isEmpty())
		std::cout << "--Warning, list should be empty.\n";

	// Variables needed to extract data.
	std::ifstream infile;
	infile.open("database.txt");
	std::string tempName;
	int tempID, tempYear;
	float tempGPA;

	// Read in one line at a time, grabbing the
	// data needed for each student.
	while (!infile.eof())
	{
		infile >> tempName >> tempID >> tempYear >> tempGPA;
		Student *tempStudent = new Student(tempName, tempID, tempYear, tempGPA);
		list.append(*tempStudent);
	}

	// Close the file stream.
	infile.close(); 
}

