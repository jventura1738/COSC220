# COSC220 Project 3: Student Database

Project by Justin Ventura.

## Specifications

This project is a .txt file based student database which allows the user to keep track of students in a class, department, or whatever scope necessary.  The students are managed using a doubly linked list (DLL), but are saved to a file for storage.  The program updates the file whenever the database and DLL are out of sync.  Meant to be a group project but I did it solo instead.  

The search function autofills names so if you type 'j', all names starting with 'j' will be displayed.  The database also immediately updates after any modification of the DLL of student data.

Instructions on how to run this application are located in the makefile.

## Funcionalities: 

- Add or Remove a Student.
- Display the Database in normal/reverse order.
- Search Student by ID or Name.
- Sort Students by ID or Name (merge sort).
- Reset the database.
