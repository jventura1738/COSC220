prog: foo.o bar.o prog.o
	g++ -o prog foo.o bar.o prog.o

prog.o: prog.cpp foo.h
	g++ -c prog.cpp

foo.o: foo.cpp foo.h bar.h
	g++ -c foo.cpp

bar.o: bar.cpp
	g++ -c bar.cpp

clean:
	rm *.o prog
