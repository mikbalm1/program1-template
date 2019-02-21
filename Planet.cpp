#include "Planet.h"
//#include "Stdlib.h"
#include "iostream"


Planet::Planet(int distance) {
	
	this -> distance = distance;
	distance = (rand() % 3001);
	
	char type_arr[3] = {'h', 'r', 'g'};
	this->type = type_arr[rand() % 3];
    	
	this -> pos = pos;
	pos = (rand() % 360);
}


int Planet::orbit() {
	
	pos = (pos + 1) % 360;

	return pos;
}


