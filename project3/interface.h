// Justin Ventura (COSC220-003)
// Project 3 (modified 11/22/19)
// File: interface.h (Justin Ventura)
// NOTE: This file contains all helper
// and interface methods used in project
// Created: 11/13/19.
#include "dList.h"
#include "dNode.h"
#include "Student.h"
#include <fstream>
#include <stdlib.h>
#include <string>

// Welcome Screen Method.
void welcomeSDB();

// Justin Interface.
void dispInterface();

// Convert string case to be all lower.
std::string lowercase(std::string s);

// Search Student by Name.
void searchByName(std::string key, dNode<Student> * header);

// Search Student by ID.
void searchByID(int key, dNode<Student> * header);

// BINARY CHOICE (0 or 1).
// Returns one of two options.
bool binaryChoice();

// GET CHOICE (recieves input as for int).
// Returns input integer.
int getChoice();

// CONFIRM RESET (prevents accidental deletion).
// Returns bool.
bool confirmReset();

// Temporary Format for Student Names.
// Pass by reference. To be undone with revert.
void qualifyEntry(Student & student);

// Reverts the Qualify Function.
void revertEntry(Student & student);

// Clear database.txt.
void clearDatabase();

// Add student details to a database.
// Pass by reference.
void updateDatabase(Student & student);

// Synchronize List and Database.
// Use this whenever List order changes.
void syncDatabase(dNode<Student> * header);

// Extract Database data.
// List should be empty.
void extractData(dList<Student> * list);

// Reverse Doubly Linked List (UNCHAIN IT FIRST)
void reverseList(dNode<Student> * header);

//===================DATABASE MERGE SORT=======================

// Splits doubly linked list into 2 half sizes.
dNode<Student> * split(dNode<Student> *head);

// Merge two Linked lists. [ID]
dNode<Student> * mergeID(dNode<Student> *first, dNode<Student> *second);

// Merge Sort Doubly Linked List by ID.
dNode<Student> * mergeSortID(dNode<Student> *head);

// Merge two Linked lists. [Name]
dNode<Student> * mergeName(dNode<Student> *first, dNode<Student> *second);

// Merge Sort Doubly Linked List by Name.
dNode<Student> * mergeSortName(dNode<Student> *head);
