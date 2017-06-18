CC=g++


CCFLAGS=-c -Wall


release: program


debug: CCFLAGS += -g
debug: program


program: main.o classes.o
	$(CC) main.o classes.o -o program


main.o: main.cpp classes.hpp
	$(CC) $(CCFLAGS) main.cpp


classes.o: classes.cpp classes.hpp
	$(CC) $(CCFLAGS) classes.cpp


clean:
	rm -f *.o
