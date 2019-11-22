# MAKEFILE FOR PROJECT 3: STUDENT DATABASE.
# COSC220-003 Dr. Enyue Lu (Justin Ventura)
# Created by Justin Ventura, on 11/22/19.

# COMMANDS: 'make' for main.exe; ./main.exe to run.
#           'make all' does same as above command.
#           'make memcheck' for memory leak checks.
#           'make clean' to remove all .o & main.exe.
#     NOTE: valgrind does not work well with MacOS.

# Makefile variables
gc = g++ -c -std=c++11 # COMPILE
go = g++ -o 		   # LINKING

#
all: main.exe

# Makes Main Executable File via Linking Object Files.
main.exe: main.o Student.o interface.o
	$(go) main.exe main.o Student.o interface.o

# Creates Main Object File via Compilation.
main.o: main.cpp Student.h
	$(gc) main.cpp

# Creates Student Object File via Compilation.
Student.o: Student.h
	$(gc) Student.cpp

# Creates an Interface Object File.
interface.o: interface.cpp
	$(gc) interface.cpp

# Command for Memory Checks
memcheck:
	valgrind --leak-check=yes ./main.exe

# Command to Clean Folder of Object & Exe Files.
clean:
	rm *.o main.exe
