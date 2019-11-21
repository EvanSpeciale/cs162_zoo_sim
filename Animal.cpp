/******************************************************************************
** Name:		Evan Speciale
** Date:		July 21, 2019
** Description: Implementation of Animal class.
******************************************************************************/
#include <iostream>
#include "Animal.hpp"

//default constructor sets age to 0
Animal::Animal()
{
	age = 0;
}

//this constructor takes an int and sets the animal's age with it
Animal::Animal(int daysOld)
{
	age = daysOld;
}

//returns true if the animal is 3 days old or older. otherwise returns false
bool Animal::isAdult()
{
	bool adult;
	if (age >= 3)
	{
		adult = true;
	}
	else
	{
		adult = false;
	}
	return adult;
}

//Increments the animal's age by 1 day
void Animal::ageAdvance()
{
	age++;
}

int Animal::getAge()
{
	return age;
}

double Animal::getCost()
{
	return cost;
}

double Animal::getFoodCost()
{
	return baseFoodCost;
}

int Animal::getNumberOfBabies()
{
	return numberOfBabies;
}