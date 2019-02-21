#ifndef LIST_H
#define LIST_H

class List {

	private:

		Node * head;
		Node * tail;

	public:

		List();
		~List();
		void insert(int index, Planet * p);
		Planet * read(int index);
		bool remove(int index);
		unsigned size();
}

#endif 
