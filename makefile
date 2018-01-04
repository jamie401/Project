all: exception

exception: mainException.o atom.o list.o struct.o scanner.h parser.h exception.h
ifeq (${OS}, Windows_NT)
	g++ -o hw8 mainException.o atom.o list.o struct.o -lgtest
else
	g++ -o hw8 mainException.o atom.o list.o struct.o -lgtest -lpthread
endif

atom.o: atom.cpp atom.h variable.h
	g++ -std=gnu++0x -c atom.cpp
list.o:list.cpp list.h
	g++ -std=gnu++0x -c list.cpp
struct.o:struct.cpp struct.h
	g++ -std=gnu++0x -c struct.cpp
mainException.o: mainException.cpp scanner.h  atom.h struct.h variable.h parser.h exception.h expression.h
	g++ -std=gnu++0x -c mainException.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o exception hw8
endif

# all: madRace utAtom utVariable utScanner utIterator
#
# utScanner: mainScanner.o atom.o list.o struct.o scanner.h utScanner.h utParser.h parser.h
# 	g++ -o utScanner mainScanner.o atom.o list.o struct.o -lgtest -lpthread
# mainScanner.o: mainScanner.cpp utScanner.h scanner.h  atom.h struct.h variable.h  utParser.h parser.h utExp.h exception.h expression.h
# 		g++ -std=c++11 -c mainScanner.cpp
