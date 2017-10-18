INC_DIR = include

all:  utVariable

utVariable: main.o
ifeq (${OS}, Windows_NT)
	g++ -o hw3 main.o -lgtest
else
	g++ -o hw3 main.o -lgtest -lpthread
endif

main.o: main.cpp utVariable.h number.h atom.h term.h variable.h
	g++ -std=gnu++0x -c main.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o utTerm
endif
