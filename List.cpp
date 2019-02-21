#include <iostream>
#include "List.h"


List::List() {

	this -> size = size;
	head = NULL;
	tail = NULL;
}

List::~List() {
    
}

void List::insert(int index, Planet * p) {
    
}

Planet * List::read(int index) {

	if (index > size()) return NULL;
}

bool List::remove(int index) {
    if (index > size()) return false;
    delete planets[index];
    size--;
    return true;
}

unsigned List::size() {

	return this -> size;
}
