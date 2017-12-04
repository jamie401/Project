INC_DIR = include

all:  utIterator

utIterator: main.o struct.o iterator.h utIterator.h
ifeq (${OS}, Windows_NT)
	g++ -o hw7 main.o struct.o -lgtest
else
	g++ -o hw7 main.o struct.o -lgtest -lpthread
endif

main.o: main.cpp utIterator.h number.h atom.h term.h variable.h global.h parser.h scanner.h node.h  list.h
	g++ -std=gnu++0x -c main.cpp

struct.o:struct.cpp struct.h
	g++ -std=gnu++0x -c struct.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o utIterator hw7
endif
