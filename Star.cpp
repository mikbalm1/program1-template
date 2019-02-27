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

    for (int i = 0; i < getCurrentNumPlanets(); i++) {
        delete planets[i];
    }
	delete [] planets;
}

int Star::addPlanet() {
    
	Planet ** newPlanets = new Planet * [getCurrentNumPlanets() + 1];
	for (int i = 0; i < getCurrentNumPlanets(); i++) {

		newPlanets[i] = planets[i];
		planets[i] = NULL;	
	}
	Planet * currentPlanet = new Planet(rand() % 3001);
	newPlanets[getCurrentNumPlanets()] = currentPlanet;
	delete [] planets;
	planets = newPlanets;
	currentPlanet = NULL;
	current_planets++;
	next_id++;
	return next_id - 1;
}

bool Star::removePlanet(int id) {

	if (getPlanet(id) != NULL) {
		Planet ** newPlanets = new Planet * [getCurrentNumPlanets() - 1 ];
		int inter = 0, i = 0;
		for (i = 0; i < getCurrentNumPlanets(); i++) {
			if (planets[i] -> getID() != id) {
				newPlanets[i + inter] = planets[i];
			}
			else {
				inter = -1;
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

    Planet * furthestPlanet = planets[0];
	for (int i = 1; i < getCurrentNumPlanets(); i++) {
        if (planets[i]->getDistance() > furthestPlanet->getDistance()) {
            furthestPlanet = planets[i];
            }
    	}
	return furthestPlanet;
}

Planet * Star::getPlanet(int id) {

	for (int i = 0; i < getCurrentNumPlanets(); i++) {
		if (planets[i] -> getID() == id) return planets[i];
	}
	return NULL;
}

void Star::orbit() {

    for (int i = 0; i < getCurrentNumPlanets(); i++) {
        planets[i] -> orbit();
    }
}

void Star::printStarInfo() {

	std::cout << "The star has " << getCurrentNumPlanets() << " planets." << std::endl;

	std::cout << "Planets:" << std::endl;

	for (int i = 0; i < getCurrentNumPlanets() ; i++) {

		std::cout << "\tPlanet " << planets[i] -> getType() << planets[i] -> getID() <<" is " << planets[i] -> getDistance() << " miles away at position " << planets[i] -> getPos() << " around the star." << std::endl;
	}
}

Starlist::Starlist() {
	this -> list;
}
Starlist::~Starlist() {
	delete list;
}
long Starlist::addPlanet(){
	
}
bool Starlist::removePlanet(int) {
	
}
Planet * Starlist::getPlanet(int) {
	
}
void Starlist::orbit() {
	
}
void Starlist::printStarInfo() {
	
}
unsigned Starlist::getCurrentNumPlanets() {
	return list.size();
}

Starvector::Starvector() {
	this -> vec;
}
Starvector::~Starvector() {
	delete [] vec;
}
long Starvector::addPlanet() {
	Planet new_planet = new Planet();
	vec.insert(1, new_planet);
	return new_planet.getID();
}
bool Starvector::removePlanet(int planet_id) {
	if(getPlanet(planet_id) == NULL) return false;
	for(int i = 0; i < vec.size(); i++) {
		if(vec[i].getID() == planet_id) {
			return vec.remove(planet_id); //
		}
	}
	return false;

}
Planet * Starvector::getPlanet(int planet_id) {
	Planet * searched_planet = NULL;
	for(int i = 0; i < vec.size(); i++) {
		if(vec[i].getID() == planet_id) {
			searched_planet = vec[i];
		}
	}
	return searched_planet;
}
void Starvector::orbit() {
	for (int i = 0; i < size(); i++) {
		vec[i]->orbit();
	}
	return;
}
void Starvector::printStarInfo() {
	
}
unsigned Starvector::getCurrentNumPlanets() {
	return vec.size();
}
