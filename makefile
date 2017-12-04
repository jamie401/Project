all: utIterator

utIterator: mainIterator.o atom.o list.o struct.o
ifeq (${OS}, Windows_NT)
	g++ -o hw7 mainIterator.o atom.o list.o struct.o -lgtest
else
	g++ -o hw7 mainIterator.o atom.o list.o struct.o -lgtest -lpthread
endif

atom.o: atom.cpp atom.h variable.h
	g++ -std=gnu++0x -c atom.cpp
list.o:list.cpp list.h
	g++ -std=gnu++0x -c list.cpp
struct.o:struct.cpp struct.h
	g++ -std=gnu++0x -c struct.cpp
mainIterator.o: mainIterator.cpp utIterator.h iterator.h variable.h global.h parser.h scanner.h node.h
	g++ -std=gnu++0x -c mainIterator.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o utIterator hw7
endif
