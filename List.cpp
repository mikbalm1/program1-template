#include <iostream>
#include <cstdlib>
#include "Star.h"
#include "Planet.h"
#include "Vector.h"
#include "List.h"


List::List() {
	this -> listSize = 0;
	this -> head = NULL;
	this -> tail = NULL;
}

List::~List() {
	Node * current = head;
	Node * next;
	
	while (current) {
		next = current->next;
		delete current;
		current = next;
	}
}

void List::insert(int index, Planet * p) {

	Node * temp1 = new Node();
	temp1->data = p;
	if(head == NULL) {
		head = temp1;
		tail = temp1;
		listSize = 1;
		return;
	}
	
	if(index == 0) {
		temp1->next = head;
		head->prev = temp1;
		head = head->prev;
	}

	else if(size() <= (unsigned)index) {
		temp1->prev = tail;
		tail->next = temp1;
		tail = tail->next;
	}
	
	else {
		Node * temp2 = head;
		for(int i = 0; i < index; i++) {
			temp2 = temp2->next;
		}
		temp1->prev = temp2;
		temp1->next = temp2->next;
	}
	listSize++;
}

Planet * List::read(int index) {
	
	if((unsigned)index >= size()) return NULL;
	Node * temp = head;
	for(int i = 0; i < index; i++) {
		temp = temp->next;
	}
	return temp->data;
}

bool List::remove(int index) {
	if (head == NULL) return false;
    if ((unsigned)index > size()) return false;

	if(index == 0 && head->next == NULL){
		delete head;
		head = NULL;
		listSize--;
		return true;
	}

	else {
		Node * temp;
		temp = head;
		for (unsigned i = 0; i <= size(); i++){
			temp = temp->next;
		}
		delete temp;
		temp = NULL;
		listSize--;
		return true;
	}
}

unsigned List::size() {
	return this -> listSize;
}
