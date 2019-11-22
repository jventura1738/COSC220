// Justin Ventura (COSC220-003)
// Project 3 (modified 11/21/19)
// File: interface.cpp (Justin Ventura)
// All of the work for the interface is
// in here.

#include "interface.h"
#include "Student.h"
#include <string>
#include <iostream>
#include <stdlib.h>
//#include <bits/stdc++.h>

void welcomeSDB()
{
	std::cout << std::string(55, '\n');
	std::cout << "==================================================\n";
	std::cout << "|        💽 Justin's Student Database 💽         |\n";
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
	std::cout << "|         💽 Justin's Student Database 💽        |\n";
	std::cout << "==================================================\n";
}

// Convert string case to be all lower.
std::string lowercase(std::string s)
{
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
	return s;
}

// Search Student by Name.
void searchByName(std::string key, dNode<Student> * header)
{
	int matchCount = 0, i, j;
	bool match = false, iterate = true;
	std::cout << "        Student          |    ID    | year | GPA\n";
	dNode<Student> * curr = header->next;

	while (curr != header)
	{
		i = 0; // for DATABASE index
		j = 0; // for KEY index
		match = false;
		int counter = 0;

		key = lowercase(key);
		std::string dataname = lowercase(curr->data.getName());

		// Loop through to check for a match.
		while (i < curr->data.getName().size())
		{
			if (dataname[i] == key[j])
			{
				match = true;
			}
			else
			{
				match = false;
				j = 0;
			}
			if (match && j + 1 == key.size())
				break;
			if (match && j < key.size())
				match = false;
			i++;
			j++;
			counter++;
		}

		// this code was able to be fixed unlike my heart.
		// 08/12/19 </3 @amy collins :(

		// Print the match.
		if (match)
		{
			matchCount++;
			std::cout << curr->data;
			match = false;
		}

		curr = curr->next;
	}

	if (matchCount == 0)
		std::cout << "\nNO MATCHES FOUND.\n";
	else
		std::cout << "\nTotal matches found: " << matchCount << "\n";

	std::cout << "Searched for: " << key << "\n";
}

// Search Student by ID.
void searchByID(int key, dNode<Student> * header)
{
	int matchCount = 0;
	std::cout << "        Student          |    ID    | year | GPA\n";
	dNode<Student> * curr = header->next;

	while (curr != header)
	{
		if (curr->data.getID() == key)
		{
			matchCount++;
			std::cout << curr->data;
		}
		curr = curr->next;
	}
	if (matchCount == 0)
	{
		std::cout << "\nNO MATCHES FOUND.\n";
		return;
	}
	else
		std::cout << "\nTotal matches found: " << matchCount << "\n";
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
        std::cin.ignore(INT32_MAX, '\n');
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
        std::cin.ignore(INT32_MAX, '\n');
        std::cout << "Invalid, re-enter ---> ";
        std::cin >> choice;
    }

    return choice;
}

bool confirmReset()
{
	int confirm;
	std::cout << "(!!!) Reset Database? Enter -1 to confirm. (!!!)\n";
	std::cout << "[Enter another integer to cancel]\n";
	std::cin >> confirm;
	while (!std::cin.good())
    {
        std::cin.clear();
        std::cin.ignore(INT32_MAX, '\n');
        std::cout << "Invalid, re-enter ---> ";
        std::cin >> confirm;
    }
    if (confirm == -1)
    	return true;
    else
    	return false;
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

// Clears the Database File.
void clearDatabase()
{
	std::ifstream outfile;
	outfile.open("database.txt", std::ofstream::out | std::ofstream::trunc);
	outfile.close();
}

void updateDatabase(Student & student)
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

// Call whenever list strays from database
void syncDatabase(dNode<Student> * header)
{
	// Clear database to refresh
	clearDatabase();
	dNode<Student> * curr = header->next;
	while (curr != header)
	{
		updateDatabase(curr->data);
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
		Student s(tempName, tempID, tempYear, tempGPA);

		// Revert to regular string form and append.
		revertEntry(s);
		list->append(s);
	}

	// Close the file stream.
	infile.close();
}

// Use only if unchained.
void reverseList(dNode<Student> * header)
{
    dNode<Student> * temp = nullptr;
    dNode<Student> * curr = header;

    while (curr)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if(!temp)
        header = temp->prev;
}

//===================DATABASE MERGE SORT=======================

// Split for Mergesort
dNode<Student> *split(dNode<Student> *head)
{
    dNode<Student> *fast = head,*slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    dNode<Student> *temp = slow->next;
    slow->next = nullptr;
    return temp;
}

// Merge ID
dNode<Student> *mergeID(dNode<Student> *first, dNode<Student> *second)
{
    // Check for empty lists
    if (!first)
        return second;

    if (!second)
        return first;

    // Pick the smaller value
    if (first->data.getID() < second->data.getID())
    {
        first->next = mergeID(first->next,second);
        first->next->prev = first;
        first->prev = nullptr;
        return first;
    }
    else
    {
        second->next = mergeID(first,second->next);
        second->next->prev = second;
        second->prev = nullptr;
        return second;
    }
}

// Mergesort ID
dNode<Student> *mergeSortID(dNode<Student> *head)
{
    if (!head || !head->next)
        return head;

    dNode<Student> *second = split(head);

    // Recur for left and right halves
    head = mergeSortID(head);
    second = mergeSortID(second);

    // Merge the two sorted halves
    return mergeID(head,second);
}

// Merge two Linked lists. [Name]
dNode<Student> * mergeName(dNode<Student> *first, dNode<Student> *second)
{
	// Check for empty lists
    if (!first)
        return second;

    if (!second)
        return first;

    // Select Alphabetically Larger
    if (lowercase(first->data.getName()) <= lowercase(second->data.getName()))
    {
        first->next = mergeName(first->next, second);
        first->next->prev = first;
        first->prev = nullptr;
        return first;
    }
    else
    {
        second->next = mergeName(first, second->next);
        second->next->prev = second;
        second->prev = nullptr;
        return second;
    }
}

// Merge Sort Doubly Linked List by Name.
dNode<Student> * mergeSortName(dNode<Student> *head)
{
    if (!head || !head->next)
        return head;
    dNode<Student> *second = split(head);

    // Recur for left and right halves
    head = mergeSortName(head);
    second = mergeSortName(second);

    // Merge the two sorted halves
    return mergeName(head,second);
}
