INC_DIR = include

all:  utTerm

utTerm: main.o
ifeq (${OS}, Windows_NT)
	g++ -o hw2 main.o -lgtest
else
	g++ -o hw2 main.o -lgtest -lpthread
endif
	
main.o: main.cpp utTerm.h $(INC_DIR)/number.h $(INC_DIR)/atom.h $(INC_DIR)/simpleOb.h $(INC_DIR)/variable.h
	g++ -std=gnu++0x -c main.cpp

clean:	
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o utTerm
endif
