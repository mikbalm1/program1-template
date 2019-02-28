#include <iostream>
#include <cstdlib>
#include "Star.h"
#include "Planet.h"
#include "Vector.h"
#include "List.h"

Vector::Vector() {
    
	this -> vectSize = 0;
    this -> vector = NULL;
}

Vector::~Vector() {
	
	for (unsigned i = 0; i < size(); i++) {
		delete vector[i];
	}
	delete [] vector;
}

void Vector::insert(int index, Planet * p) {
    
	if ((unsigned)index < size()) {
        Planet ** new_vector = new Planet * [size() + 1];
        for (unsigned i = 0; i < size(); i++) {
            if (i == (unsigned)index) {
                new_vector[index] = p;
            }
            else {
                new_vector[i] = vector[i];
            }
        }
        delete [] vector;
        vector = new_vector;
    }
    vectSize++;
}

Planet * Vector::read(int index) {
    
	if ((unsigned)index > size()) return NULL;
	return vector[index];
}

bool Vector::remove(int index) {

    if ((unsigned)index > size()) return false;
    Planet ** new_vector = new Planet * [size() - 1];
    unsigned inter = 0;
    for (unsigned i = 0; i < size(); i++) {
        if (i == (unsigned)index) {
            delete vector[index];
            inter = 1;
        }
        else {
            new_vector[i - inter] = vector[i];
        }
    }
    delete [] vector;
    vector = new_vector;
	vectSize--;
	return true;
}

unsigned Vector::size() {
    
	return this -> vectSize;
}
