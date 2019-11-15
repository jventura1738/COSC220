;// Justin Ventura (COSC220-003)
// Project 3 (modified 11/14/19)
// File: interface.h (Justin Ventura)
#include "dList.h"
#include "Student.h"
#include <fstream>
#include <stdlib.h>

// Welcome Screen Method
void welcomeSDB();

// Justin Interface
void dispInterface();

// GET CHOICE (recieves input as for int)
// Returns input integer
int getChoice();

// Temporary Format for Student Names.
// Pass by reference. To be undone with revert.
void qualifyEntry(Student * student);

// Reverts the Qualify Function.
void revertEntry(Student * student);

// Clear database.txt.
void clearDatabase(); 

// Add student details to a database.
// Pass by reference.
void updateDatabase(Student * student);

// Extract Database data.
// List should be empty.
void extractData(dList<Student> * list);
