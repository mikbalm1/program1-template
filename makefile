CC=g++
CFLAGS=-Wall -Wextra -DDEBUG -pedantic -g -c -std=c++14

all: program1

program1: Star.o Planet.o Vector.o List.o program1.o
	$(CC) $(CFLAGS) Star.o Planet.o Vector.o List.o program1.o -o program1

run: all
	./program1

Star.o: Star.cpp Star.h
	$(CC) $(CFLAGS) Star.cpp

Planet.o: Planet.cpp Planet.h
	$(CC) $(CFLAGS) Planet.cpp

Vector.o: Vector.cpp Vector.h
	$(CC) $(CFLAGS) Vector.cpp

List.o: List.cpp List.h
	$(CC) $(CFLAGS) List.cpp

program1.o: program1.cpp
	$(CC) $(CFLAGS) program1.cpp

memcheck: all
	valgrind --leak-check=full ./program1

clean:
	rm *.o program1
