#include <iostream>
#include "Planet.h"

Vector::Vector(int size) {
    
	this -> size = size;
    	this -> planets = NULL;
}

Vector::~Vector() {
    
	delete [] planets;
}

void Vector::insert(int index, Planet * p) {
    
	if (index < size()) {
        	
		Planet ** new_planets;
    	}
    	
	size++;
}

Planet * Vector::read(int index) {
    
	if (index > size()) { return NULL; }
    
	return planets[index];
}

bool Vector::remove(int index) {
    
	if (index < size()) { return false; }
    	
	size--;
    
	return true;
}

unsigned Vector::size() {
    
	return this -> size;
}


