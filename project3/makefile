# MAKEFILE FOR PROJECT 3: STUDENT DATABASE.
# COSC220-003 Dr. Enyue Lu (Justin Ventura)
# Created by Justin Ventura, on 11/11/19.

# Makefile variables
gc = g++ -c -std=c++11
go = g++ -o

# Default makefile command
main: main.o Student.o
	$(go) main main.o Student.o

main.o: main.cpp Student.h
	$(gc) main.cpp

Student.o: Student.h
	$(gc) Student.cpp

# Command for Memory Checks
memcheck:
	valgrind --leak-check=yes ./main

# Command to clean folder
clean:
	rm *.o main