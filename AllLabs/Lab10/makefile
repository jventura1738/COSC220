gc = g++ -c -std=c++11
go = g++ -o

main: Pointers.o
	$(go) main Pointers.o

Pointers.o: Pointers.cpp
	$(gc) Pointers.cpp

main2: ThreeDimPt.o ClassArr.o
	$(go) main2 ThreeDimPt.o ClassArr.o

ThreeDimPt.o: ThreeDimPt.cpp
	$(gc) ThreeDimPt.cpp

ClassArr.o: ClassArr.cpp
	$(gc) ClassArr.cpp

clean:
	rm *.o main main2
