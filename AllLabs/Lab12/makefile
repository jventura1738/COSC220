# Justin Ventura
# COSC220-003
# makefile for main (Lab12)
GC = g++ -c -std=c++11 -g
GO = g++ -g -o

main: main.o
	$(GO) main main.o

main.o: main.cpp
	$(GC) main.cpp

# memory checks
memcheck:
	valgrind --leak-check=yes ./main

clean:
	rm main *.o
