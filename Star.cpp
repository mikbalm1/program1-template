#include <iostream>
#include <cstdlib>
#include "Star.h"
#include "Planet.h"
#include "Vector.h"
#include "List.h"

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
		current_planets--;
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
	this -> list = NULL;
}
Starlist::~Starlist() {
	delete list;
}
long Starlist::addPlanet(){
	Planet * new_planet = new Planet(rand() % 3001);
	list -> insert(list->size(), new_planet);
	return new_planet -> getID();
}
bool Starlist::removePlanet(int id) {
	return list -> read(id);
}
Planet * Starlist::getPlanet(int id) {
	return list -> read(id);
}
void Starlist::orbit() {
	for (unsigned i = 0; i < list -> size(); i++) {
		list -> read(i) -> orbit();
	}
}
void Starlist::printStarInfo() {
	for (int i = 0; (unsigned)i < list->size(); i++) {
		std::cout << "Planet " << i << " is " << (list->read(i))->getDistance() << " million miles away at pos "
		<< (list->read(i))->getPos() << " around the star" << std::endl;
	}
}
unsigned Starlist::getCurrentNumPlanets(){
	return list -> size();
}

Starvector::Starvector() {
	this -> vec = NULL;
}
Starvector::~Starvector() {
	delete vec;
}
long Starvector::addPlanet() {
	Planet * new_planet = new Planet(rand() % 3001);
	vec->insert(vec->size(), new_planet);
	return new_planet->getID();
}
bool Starvector::removePlanet(int planet_id) {
	
	for (unsigned i = 0; i < vec->size(); i++) {
		Planet * new_planet = vec->read(i);
		if ((long) new_planet == planet_id) {
			return vec->remove(i);
		}
	}
	return false;

}
Planet * Starvector::getPlanet(int planet_id) {
	for (unsigned i = 0; i < vec->size(); i++) {
		Planet * new_planet = vec->read(i);
		if ((long) new_planet == planet_id) return new_planet;
	}
	return vec->read(planet_id);

}
void Starvector::orbit() {
	for (unsigned i = 0; i < vec->size(); i++) {
		vec->read(i)->orbit();
	}
}
void Starvector::printStarInfo() {
	for (unsigned i = 0; i < vec->size(); i++) {
		std::cout << "Planet " << i << " is " << (vec->read(i))->getDistance() << " million miles away at pos "
		<< (vec->read(i))->getPos() << " around the star" << std::endl;
	}
}
unsigned Starvector::getCurrentNumPlanets(){
	return vec -> size();
}
