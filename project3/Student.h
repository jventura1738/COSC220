// Justin Ventura (COSC220-003)
// Project 3 (modified 11/12/19)
// File: Student.h (Justin Ventura)
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

class Student
{
private:
	std::string Name;
	int ID;
	int Year;
	float GPA;

public:
	// -- STUDENT CLASS UTILITIES --

	// Constructor
	Student(std::string n = "N/A", int id = 0, int y = 0, float gpa = 0.0):
			Name(n), ID(id), Year(y), GPA(gpa)
	{ std::cout << "Student Constructed.\n"; }

	// Destructor
	~Student() { std::cout << "Student destroyed.\n"; }

	// Copy Constructor
	Student(Student & obj);

	// Overloaded Assignment Operator
	void operator=(Student& obj);

	// -- METHODS FOR STUDENT CLASS --

	// Name getter
	std::string getName()
	{ return this->Name; }

	// ID getter
	int getID()
	{ return this->ID; }

	// Year getter
	int getYear()
	{ return this->Year; }

	// GPA getter
	float getGPA()
	{ return this->GPA; }

	// Name setter
	void setName(std::string n)
	{ this->Name = n; }

	// ID setter
	void setID(int id)
	{ this->ID = id; }

	// Year setter
	void setYear(int y)
	{ this->Year = y; }

	// GPA setter
	void setGPA(float gpa)
	{ this->GPA = gpa; }

	// Overloaded << operator
	friend std::ostream& operator<<(std::ostream& ostr, const Student& obj);

	// Overloaded >> operator
	friend void operator>> (std::istream& istr, Student& obj);

	// Overload == operator
	friend bool operator==(const Student& lhs, const Student& rhs);
};

#endif
