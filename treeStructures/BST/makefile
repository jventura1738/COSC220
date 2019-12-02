# MAKEFILE
gc = g++ -c -std=c++11
go = g++ -o

main: main.o
	$(go) main main.o

main.o: main.cpp
	$(gc) main.cpp

clean:
	rm *.o main
