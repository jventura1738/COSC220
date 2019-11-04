# makefile for lab8
gc = g++ -c -std=c++11
go = g++ -o

# prelab
main1: hanoiMain.o hanoi.o
	$(go) main1 hanoiMain.o hanoi.o

main1.o: hanoiMain.cpp
	$(gc) hanoiMain.cpp

hanoi.o: hanoi.cpp
	$(gc) hanoi.cpp

# lab task 
main2: main2.o isPal.o
	$(go) main2 main2.o isPal.o

main2.o: main2.cpp
	$(gc) main2.cpp

isPal.o: isPal.cpp
	$(gc) isPal.cpp

# clean up
clean:
	rm *.o main1 main2
