#include <iostream>
#include "Planet.h"

Vector::Vector(int size) {
    
	this -> size = 0;
    this -> planets = NULL;
}

Vector::~Vector() {
    
	delete [] planets;
}

void Vector::insert(int index, Planet * p) {
    
	if (index < size()) {
        Planet ** new_planets = new Planet * [size() + 1];
        for (int i = 0; i < size(); i++) {
            if (i == index) {
                new_planets[index] = p;
            }
            else {
                new_planets[i] = planets[i];
            }
        }
        delete [] planets;
        planets = new_planets;
    }
    size++;
}

Planet * Vector::read(int index) {
    
	if (index > size()) return NULL;
	return planets[index];
}

bool Vector::remove(int index) {

    if (index > size()) return false;
    Planet ** new_planets = new Planet * [size() - 1];
    int internal = 0;
    for (int i = 0; i < size(); i++) {
        if (i == index) {
            delete planets[index];
            internal = -1;
        }
        else {
            new_planets[i + internal] = planets[i];
        }
    }
    delete [] planets;
    planets = new_planets;
	size--;
	return true;
}

unsigned Vector::size() {
    
	return this -> size;
}
