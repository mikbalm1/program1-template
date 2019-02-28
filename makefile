CC=g++

CFLAGS=-Wall -Wextra -DDEBUG -g -c -std=c++14

all: program1

program1: Star.o Planet.o List.o Vector.o program1.o
	$(CC) Star.o Planet.o List.o Vector.o program1.o -o program1  

Star.o: Star.cpp 
	$(CC) $(CFLAGS) Star.cpp

Planet.o: Planet.cpp
	$(CC) $(CFLAGS) Planet.cpp

List.o: List.cpp
	$(CC) $(CFLAGS) List.cpp

Vector.o: Vector.cpp
	$(CC) $(CFLAGS) Vector.cpp

program1.o: program1.cpp
	$(CC) $(CFLAGS) program1.cpp 

memcheck: all
	valgrind --leak-check=full ./program1

clean: 	
	rm *o program1

run: all
	./program1
