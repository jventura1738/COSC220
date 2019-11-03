gc = g++ -c -std=c++11
go = g++ -o

main: main.o timer.o
	$(go) main main.o timer.o

main.o: main.cpp Sorts.h
	$(gc) main.cpp

test: test.o timer.o
	$(go) test test.o timer.o

test.o: test.cpp Sorts.h
	$(gc) test.cpp

timer.o: timer.cpp timer.h
	$(gc) timer.cpp

clean:
	rm *.o test
