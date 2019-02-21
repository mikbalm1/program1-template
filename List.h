#ifndef LIST_H
#define LIST_H

class List {

	private:

		Node * head;
		Node * tail;

	public:

		List();
		~List();
		void insert(int, Planet);
		Planet * read(int);
		bool remove(int);
		unsigned size();
}

#endif 
