#include <iostream>
#include "Star.h"
#include "Planet.h"
//#include "Stdlib.h"


Star::Star() {
    	
	this -> current_planets = 0;
    	this -> next_id = 0;
	this -> planets = NULL;
}

Star::~Star() {

	for (int i = 0; i < getCurrentNumPlanets(); i++) { delete planets[i]; }

	delete [] planets;
}

int Star::addPlanet() {
    
	Planet ** newPlanets = new Planet * [getCurrentNumPlanets() + 1]; //allocating

	for (int i = 0; i < getCurrentNumPlanets(); i++) { //to copy the pointers for the new array 

		newPlanets[i] = planets[i];
		planets[i] = NULL;	
	}

	Planet * currentPlanet = new Planet(rand() % 3001, next_id);
	newPlanets[getCurrentNumPlanets()] = currentPlanet;

	delete [] planets;
	
	planets = newPlanets;
	currentPlanet = NULL;
	current_planets++; //updating
	next_id++;
	
	return (next_id - 1); 
}

bool Star::removePlanet(int id) {

	if (getPlanet(id) != NULL) {

		Planet ** newPlanets = new Planet * [getCurrentNumPlanets() - 1 ]; //allocating
	
		int internal = 0, i = 0;
		for (i = 0; i < getCurrentNumPlanets(); i++) {

			if (planets[i] -> getID() != id) { newPlanets[i + internal] = planets[i]; }

			else {
				internal = -1;
				delete planets[i];
			}
		}

		delete [] planets;

		planets = newPlanets;
		current_planets--; //updating

		return true;
	}

	return false;
}

Planet * Star::getFurthest() {

    	Planet * maxDistancedPlanet = planets[0];
    	
	for (int i = 1; i < getCurrentNumPlanets(); i++) {
        	
		if ( (planets[i] -> getDistance()) > (maxDistancedPlanet -> getDistance()) ) { maxDistancedPlanet = planets[i]; }
    	}
    
	return maxDistancedPlanet;
}

Planet * Star::getPlanet(int id) {

	for (int i = 0; i < getCurrentNumPlanets(); i++) {

		if (planets[i] -> getID() == id) { return planets[i]; }
	}
	
	return NULL;
}

void Star::orbit() {
    
    	for (int i = 0; i < getCurrentNumPlanets(); i++) { planets[i] -> orbit(); }
}

void Star::printStarInfo() {

	std::cout << "The star has " << getCurrentNumPlanets() << " planets." << std::endl;

	std::cout << "Planets:" << std::endl;

	for (int i = 0; i < getCurrentNumPlanets() ; i++) {

		std::cout << "\tPlanet " << planets[i] -> getType() << planets[i] -> getID() <<" is " << planets[i] -> getDistance() << " miles away at position " << planets[i] -> getPos() << " around the star." << std::endl;
	}
}


