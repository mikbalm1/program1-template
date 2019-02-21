#ifndef STAR_H
#define STAR_H
#include "Planet.h"

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

#endif
