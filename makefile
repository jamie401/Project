INC_DIR = include

all:  utList

utList: main.o
ifeq (${OS}, Windows_NT)
	g++ -o hw4 main.o -lgtest
else
	g++ -o hw4 main.o -lgtest -lpthread
endif

main.o: main.cpp utList.h number.h atom.h term.h variable.h
	g++ -std=gnu++0x -c main.cpp


clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o utList hw4
endif
