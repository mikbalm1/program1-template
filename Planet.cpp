#include <iostream>
#include <cstdlib>
#include "Star.h"
#include "Planet.h"
#include "Vector.h"
#include "List.h"


Planet::Planet(int distance) {

	this -> distance = distance;
	distance = (rand() % 3001);
	char type_arr[3] = {'h', 'r', 'g'};
	this -> type = type_arr[rand() % 3];
	this -> pos = (rand() % 360);
	id = 123;
	this -> id = id;
}

int Planet::orbit() {
	
	pos = (pos + 1) % 360;
	return pos;
}
