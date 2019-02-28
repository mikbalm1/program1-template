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
    
	/*while ((unsigned) index > size()) {
		
		vectSize++;
	}*/
	
	if ((unsigned) index >= size()) { 
		int an = index - (size() - 1);
		Planet **temp = new Planet *[size() + an];

		
		//copies over every element in vect
		for (int i = 0; i < size(); i++) {
			temp[i] = vector[i];
		}
		//fills new elements in temp with NULL
		for (int j = size(); j < size() + an; j++) {
			temp[j] = NULL;
		}
		//moves "temp" back over to "vect"
		delete[] vector;
		vector = temp;
		vectSize += an;
		//vectSize = vectSize + (index - size() - 1); 
		vector[index] = p;
		return;
	}
	
	//if ((unsigned)index < size()) {
        
	Planet ** new_vector = new Planet * [size() + 1];
        
	for (unsigned i = 0; i < size(); i++) {
            if (i == (unsigned)index) {
                new_vector[i] = p;
            }
            else {
                new_vector[i] = vector[i];
		//vector[i] = NULL;
            }
        }
        delete [] vector;
        vector = new_vector;
    //}

	/*Planet ** new_vector = new Planet * [size() + 1];
	for (unsigned i=0; i<=size(); ++i)
  	{
    if (i < (unsigned) index)  // All the elements before the one that must be inserted
    {
       new_vector[i] = vector[i];
    }
  
    if (i ==  (unsigned) index)  // The right place to insert the new element
    {
      new_vector[i] = p;
    }
 
    if (i >  (unsigned) index)  // Now all the remaining elements
    {
      new_vector[i] = vector[i-1];
    }
  }*/
	vectSize++;
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
