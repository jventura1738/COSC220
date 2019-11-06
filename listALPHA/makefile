# makefile for datastruct dir main
GC = g++ -c -std=c++11 -g
GO = g++ -g -o

main: main.o
	$(GO) main main.o

main.o: main.cpp
	$(GC) main.cpp

memcheck:
	valgrind --leak-check=yes ./main

clean:
	rm main *.o
