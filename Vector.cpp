#include <iostream>
#include <cstdlib>
#include "Star.h"
#include "Planet.h"
#include "Vector.h"
#include "List.h"

Vector::Vector() {
    
	this -> vectSize = 0;
    this -> vector = new Planet * [0];
}

Vector::~Vector() {
	
	for (unsigned i = 0; i < size(); i++) {
		delete vector[i];
	}
	delete [] vector;
}

void Vector::insert(int index, Planet * p) {
	
	Planet ** new_vector = NULL;
	if((unsigned) index > size()) {
		new_vector = new Planet * [index + 1];
	
		for(unsigned i = 0; i < size(); i++) {
			new_vector[i] = vector[i];
		}
		for(unsigned i = size(); i < (unsigned)index; i++) {
			new_vector[i] = NULL;
		}
		new_vector[index] = p;
		vectSize = index + 1;
	}
	
	else {
		new_vector = new Planet * [size() + 1];
		for(unsigned i = 0; i < (unsigned)index; i++) {
			new_vector[i] = vector[i];
		}
		new_vector[index] = p;
		for(unsigned i = index; i < size(); i++) {
			new_vector[i+1] = vector[i];
		}
		vectSize++;
	}
	
	delete [] vector;
	vector = new_vector;
}

Planet * Vector::read(int index) {
    
	if ((unsigned)index >= size()) return NULL;

	return this -> vector[index];
}

bool Vector::remove(int index) {

    if ((unsigned)index > size()) return false;
    Planet ** new_vector = new Planet * [size() - 1];
    unsigned inter = 0;
    for (unsigned i = 0; i < size(); i++) {
        if (i != (unsigned)index) {
            new_vector[inter] = vector[i];
		vector[i] = NULL;
		inter++;            
            
        }
        else {
		delete vector[i];
        }
    }
    delete [] vector;
    vector = new_vector;
	new_vector = NULL;
	vectSize--;
	return true;
}

unsigned Vector::size() {
    
	return this -> vectSize;
}
