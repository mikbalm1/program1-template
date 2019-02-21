#ifndef VECTOR_H
#define VECTOR_H

class Vector{

	private:

	    unsigned size;
	
	public:

	    Planet ** planets;
	    Vector();
	    ~Vector();
	    void insert(int,Planet);
	    Planet * read(int);
	    bool remove(int);
	    unsigned size();
};

#endif
