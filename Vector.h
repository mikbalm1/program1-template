#ifndef VECTOR_H
#define VECTOR_H

class Vector{

	private:

	    unsigned vectSize;
	
	public:

	    Planet ** vector;
	    Vector();
	    ~Vector();
	    void insert(int,Planet*);
	    Planet * read(int);
	    bool remove(int);
	    unsigned size();
};

#endif
