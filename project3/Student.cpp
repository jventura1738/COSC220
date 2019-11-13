// Justin Ventura (COSC220-003)
// Project 3 (modified 11/12/19)
// File: Student.cpp (Justin Ventura)
#include "Student.h"
#include <iostream>
#include <iomanip>

// Implementation of Copy Constructor
Student::Student(const Student& obj)
{
	std::cout << "Student Constructed (COPY).\n";
	this->Name = obj.Name;
	this->ID = obj.ID;
	this->Year = obj.Year;
	this->GPA = obj.GPA;
}

// Implementation of Overloaded operator=
void Student::operator=(const Student& obj)
{
	std::cout << "Student Constructed (AO).\n";
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
	ostr << " " << std::left << std::setw(3) << obj.Year << "| ";
	ostr << std::left << std::setw(3) << std::setprecision(2) << std::fixed << obj.GPA;
	return ostr;
}

// Implementation of Overloaded operator>> (friend)
std::istream& operator>> (std::istream& istr, Student& obj)
{
	return istr;
}

// Implementation of Overloaded operator== (friend)
bool operator==(const Student& lhs, const Student& rhs)
{
	return true;
}
