#include <iostream>
#include <cstdlib>
#include "Star.h"
#include "Planet.h"


Planet::Planet(int distance) {

	long temp_id = long(this);
	this -> id = temp_id;
	this -> distance = distance;
	this -> pos = (rand() % 360);
	//distance = (rand() % 3001);
	char type_arr[3] = {'h', 'r', 'g'};
	this -> type = type_arr[rand() % 3];
	

}

int Planet::orbit() {
	
	pos = (pos + 1) % 360;
	return this -> pos;
}
