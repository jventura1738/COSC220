# Justin Ventura
# LAB7 FILES
# makefile works for both tasks

# task1
main: ex28.o
	g++ -o main ex28.o

ex28.o: ex28.cpp ex28Aux.h
	g++ -c ex28.cpp

# task2

main2: ex9.o time24.o
	g++ -o main2 ex9.o time24.o

ex9.o: ex9.cpp time24.cpp ex9Aux.h
	g++ -c ex9.cpp time24.cpp

time24.o: time24.cpp
	g++ -c time24.cpp

# clean up

clean:
	rm *.o main main2
