# Justin Ventura COSC220-003
# Lab9 makefile

gc = g++ -c
go = g++ -o

main: lab9Driver.o
	$(go) main lab9Driver.o

lab9Driver.o: lab9Driver.cpp lab9aux.h
	$(gc) lab9Driver.cpp

clean:
	rm *.o main
