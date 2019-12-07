# MAKEFILE
gc = g++ -c -std=c++11
go = g++ -o

main: main.o tnode.o
	$(go) main main.o tnode.o

main.o: main.cpp tnode.o
	$(gc) main.cpp

tnode.o: tnode.h tnode.cpp
	$(gc) tnode.cpp

clean:
	rm *.o main
