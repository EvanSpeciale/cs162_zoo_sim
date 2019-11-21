/******************************************************************************
** Name:		Evan Speciale
** Date:		July 21, 2019
** Description: Declaration of Zoo class, and HOO BOY. Includes member variables
**				for each animal type's array size, an array of pointers to
**				animal objects for each type of animal, a running counter for
**				each animal type, a running counter for ALL animals, the user's
**				bank balance, the zoo's age, and daily payoff.
**				Class methods include default constructor and destructor (which
**				deletes all created Animal objects), functions to open the zoo
**				and run beginning- and end-of-day operations of the Zoo,
**				functions to buy an adult of each animal, a function to generate
**				a random event, and functions to run the course of each random
**				event type.
******************************************************************************/
#ifndef ZOO_HPP
#define ZOO_HPP
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"

class Zoo
{
private:
	int arraySize;
	int tigerArraySize=10;
	int penguinArraySize=10;
	int turtleArraySize=10;
	Animal** tigers;		//array of pointers to Tiger objects
	int tigerCount=0;
	int tempTigerCount=0;
	Animal** penguins;		//array of pointers to Penguin objects
	int penguinCount=0;
	int tempPenguinCount=0;
	Animal** turtles;		//array of pointers to Turtle objects
	int turtleCount=0;
	int tempTurtleCount=0;
	double bankBalance;
	int animalCount=0;
	int zooAge=0;
	double dayPayoff;
	double bonusPayoff;
public:
	Zoo();
	~Zoo();
	void newDay();
	bool endOfDay();
	void buyTiger();
	void buyPenguin();
	void buyTurtle();
	void randomEvent();
	void openZoo();
	void arrayOverflowCheck();
	void ageAndFeedAnimals();
	void sickAnimal();
	void attendanceBoom();
	void babyAnimal();
};

#endif //ZOO_HPP
