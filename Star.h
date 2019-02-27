#ifndef STAR_H
#define STAR_H
#include "Planet.h"
#include "List.h"
#include "Vector.h"

class Star{

	private:

		int current_planets;
		int next_id;

	public:

		Planet ** planets;
		Star();
		~Star();
		int addPlanet();
		bool removePlanet(int);
		Planet * getFurthest();
		Planet * getPlanet(int);
		void orbit();
		void printStarInfo();
		int getCurrentNumPlanets() { return current_planets; }
};

class Starlist{

	private:
	List * list = new List();
	public:
	Starlist();
	~Starlist();
	long addPlanet();
	bool removePlanet(int);
	Planet * getPlanet(int);
	void orbit();
	void printStarInfo();
	unsigned getCurrentNumPlanets();
};

class Starvector{

	private:
	Vector * vec = new Vector();
	public:
	Starvector();
	~Starvector();
	long addPlanet();
	bool removePlanet(int);
	Planet * getPlanet(int);
	void orbit();
	void printStarInfo();
	unsigned getCurrentNumPlanets();
};

#endif
