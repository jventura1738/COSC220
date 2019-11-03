# makefile for project 1 (Justin Ventura COSC220-03)

CC = g++
OBJS = shape.o rect.o main.o center.o square.o circle.o shapeTryRecenter.o drawShape.o
CPP = shape.cpp rect.cpp main.cpp center.cpp square.cpp circle.cpp shapeTryRecenter.cpp drawShape.cpp

# compile and link: 'make all'

all: $(OBJS)
	$(CC) -c $(CPP)
	$(CC) -o main $(OBJS) 

# clean up object files and main executable: 'make clean'

clean:
	rm *.o main
