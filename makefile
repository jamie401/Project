all: exception #expression

exception: mainException.o atom.o list.o struct.o
ifeq (${OS}, Windows_NT)
	g++ -o hw8 mainException.o atom.o list.o struct.o -lgtest
else
	g++ -o hw8 mainException.o atom.o list.o struct.o -lgtest -lpthread
endif

# expression: mainExpression.o atom.o list.o struct.o
# ifeq (${OS}, Windows_NT)
# 	g++ -o hw8 mainExpression.o atom.o list.o struct.o -lgtest
# else
# 	g++ -o hw8 mainExpression.o atom.o list.o struct.o -lgtest -lpthread
# endif


atom.o: atom.cpp atom.h variable.h
	g++ -std=gnu++0x -c atom.cpp
list.o:list.cpp list.h
	g++ -std=gnu++0x -c list.cpp
struct.o:struct.cpp struct.h
	g++ -std=gnu++0x -c struct.cpp
mainException.o: mainException.cpp exception.h variable.h global.h parser.h scanner.h
	g++ -std=gnu++0x -c mainException.cpp
# mainExpression.o: mainExpression.cpp expression.h variable.h global.h parser.h scanner.h
# 	g++ -std=gnu++0x -c mainExpression.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o exception expression hw8
endif
