;// Justin Ventura (COSC220-003)
// Project 3 (modified 11/14/19)
// File: interface.h (Justin Ventura)
#include "dList.h"
#include "Student.h"
#include <fstream>

// Welcome Screen Method
void welcome();

// Temporary Format for Student Names.
// Pass by value to not modify the actual student.
void qualifyEntry(Student & student);

void revertEntry(Student & student);

// Clear database.txt.
void clearDatabase(); 

// Add student details to a database.
// Pass by reference.
void updateDatabase(Student &student);

// Extract Database data.
// List should be empty.
void extractData(dList<Student> & list);

