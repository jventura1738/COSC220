# MAKEFILE FOR PROJECT 3: STUDENT DATABASE.
# COSC220-003 Dr. Enyue Lu (Justin Ventura)
# Created by Justin Ventura, on 11/11/19.

# COMMANDS: 'make' for main.exe; ./main.exe to run.
#           'make memcheck' for memory leak checks.
#           'make clean' to remove all .o & main.exe.
#     NOTE: valgrind does not work well with MacOS.

# Makefile variables
gc = g++ -c -std=c++11 # COMPILE
go = g++ -o 		   # LINKING

# Makes Main Executable File via Linking Object Files.
main: main.o Student.o #inputValidate.o
	$(go) main main.o Student.o #inputValidate.o

# Creates Main Object File via Compilation.
main.o: main.cpp Student.h
	$(gc) main.cpp

# Creates Student Object File via Compilation.
Student.o: Student.h
	$(gc) Student.cpp

# Creates inputValidate Object File via Compilation.
#inputValidate.o: inputValidate.cpp
#	$(gc) inputValidate.cpp

# Command for Memory Checks
memcheck:
	valgrind --leak-check=yes ./main

# Command to Clean Folder of Object & Exe Files.
clean:
	rm *.o main
