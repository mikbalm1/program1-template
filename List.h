#ifndef LIST_H
#define LIST_H
#include "Planet.h"

class List {

	private:

		unsigned listSize;

		struct Node {
			Planet * data;
			Node * next;
			Node * prev;
		};
		Node * head;
		Node * tail;

	public:

		List();
		~List();
		void insert(int, Planet*);
		Planet * read(int);
		bool remove(int);
		unsigned size();
};

#endif 
