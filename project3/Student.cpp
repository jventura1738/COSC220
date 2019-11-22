// Justin Ventura (COSC220-003)
// Project 3 (modified 11/12/19)
// File: Student.cpp (Justin Ventura)
// Student Class Implementation File.
// Created: 11/12/19.
#include "Student.h"
#include <iostream>
#include <iomanip>
#include <string>

// Implementation of Copy Constructor
Student::Student(Student & obj)
{
	//std::cout << "Student Constructed (COPY).\n";
	this->Name = obj.Name;
	this->ID = obj.ID;
	this->Year = obj.Year;
	this->GPA = obj.GPA;
}

// Implementation of Overloaded operator=
void Student::operator=(Student& obj)
{
	//std::cout << "Student Constructed (AO).\n";
	this->Name = obj.Name;
	this->ID = obj.ID;
	this->Year = obj.Year;
	this->GPA = obj.GPA;
}

// Implementation of Overloaded operator<< (friend)
std::ostream& operator<<(std::ostream& ostr, const Student& obj)
{
	ostr << std::left << std::setw(25) << obj.Name << "| ";
	ostr << std::left << std::setw(9) << obj.ID << "| ";
	ostr << " " << std::left << std::setw(4) << obj.Year << "| ";
	ostr << std::left << std::setw(3) << std::setprecision(2)
	     << std::fixed << obj.GPA << "\n";
	return ostr;
}

// Implementation of Overloaded operator>> (friend)
void operator>> (std::istream& istr, Student& obj)
{
	// Student name obtained from user
	std::cout << "Enter student name [25 char max]: ";
	do
	{
 		getline(std::cin, obj.Name);
 		if (obj.Name.size() > 25 || obj.Name.size() < 1)
 			std::cout << "Incorrect name length. Re-enter: ";
	} while (obj.Name.size() > 25 || obj.Name.size() < 1);
	std::cout << "Entered name: " << obj.Name << "\n";

	// Student ID obtained from user
	std::cout << "Enter student ID [9 digit max]: ";
	do
	{
		std::cin >> obj.ID;
		if (obj.ID > 99999999)
			std::cout << "Incorrect ID length. Re-enter: ";
	} while (obj.ID > 99999999);
	std::cout << "Entered ID: " << obj.ID << "\n";

	// School Year obtained from user
	std::cout << "Enter student year [integer]: ";
	do
	{
		std::cin >> obj.Year;
		if (obj.Year > 10)
			std::cout << "Incorrect Year. Re-enter: ";
	} while (obj.Year > 10);
	std::cout << "Entered year: " << obj.Year << "\n";

	// GPA obtained from user
	std::cout << "Enter student GPA [out of 4.00]: ";
	do
	{
		std::cin >> obj.GPA;
		if (obj.GPA > 4.00 || obj.GPA < 0.00)
			std::cout << "Invalid GPA.  Re-enter: ";
	} while (obj.GPA > 4.00 || obj.GPA < 0.00);
	std::cout << "Entered GPA: " << obj.GPA << "\n";
}

// Implementation of Overloaded operator== (friend)
bool operator==(const Student& lhs, const Student& rhs)
{
	if (lhs.Name.compare(rhs.Name) == 0)

		if (lhs.ID == rhs.ID)

			if (lhs.Year == rhs.Year)

				if (lhs.GPA == rhs.GPA)

					return true;

	return false;
}
