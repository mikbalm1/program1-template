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
	
	while (current) //!= NULL)
	{
		next = current->next;
		delete current;
		current = next;
	}

	/*Keremlerin metodu
	Node * temp = tail;
	while (tail != NULL) {
		tail = tail->prev;
		if (tail != NULL) tail->next = NULL;
		delete temp;
		temp = tail;
	}*/
}

/*Node * List::newNode(Planet * p) {
	Node * new_node = (node) malloc(sizeof(struct Node));
	new_node->data = p;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}*/

void List::insert(int index, Planet * p) {
	if (p == NULL) {
		return;
	}

	struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->data = p;

	if (head == NULL) {
		new_node->prev = NULL;
		head = new_node;
		listSize++;
		return;
	}
	
	if((unsigned)index > size()) {
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = new_node;
		new_node->prev = tail;
		listSize++;
		return;
	}

	else {
		new_node->next=head;
		for (int i = 0; i <= index; i++){
			new_node = new_node->next;
		}
		listSize++;
	}
	return;

	/*if (index > size()) {
		Node * insertedNode;
		insertedNode->data = p;
		tail->next = insertedNode;
		insertedNode->prev = tail;
	}
	Node * nnode = newNode(p);
	//How do I implement the prev node???
	nnode->next = prev_node->next;
	prev_node->next = nnode;
	nnode->prev = prev_node;
	if (nnode->next != NULL)
		nnode->next->prev = nnode;*/
}

Planet * List::read(int index) {
	if((unsigned)index > size()) return NULL;
	if(index == 0 && head->next == NULL) return  head->data;
	Node * temp;
	temp = head;
	for(int i=0; i <= index; i++) {
		temp = temp -> next;
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
