#ifndef PLANET_H
#define PLANET_H


class Planet{

	private:

		long id;
		int pos;
		int distance;
		char type;

	public:

		Planet(int);
        int orbit();
		long getID() { return this->id; }
        int getDistance() { return this -> distance; }
        int getPos() { return this -> pos; }
		char getType() { return this -> type; }
};


#endif
