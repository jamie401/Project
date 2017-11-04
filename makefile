INC_DIR = include

all:  utParser

utParser: main.o
ifeq (${OS}, Windows_NT)
	g++ -o hw5 main.o -lgtest
else
	g++ -o hw5 main.o -lgtest -lpthread
endif

main.o: main.cpp utParser.h number.h atom.h term.h variable.h global.h parser.h scanner.h
	g++ -std=gnu++0x -c main.cpp


clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o utParser hw5
endif
