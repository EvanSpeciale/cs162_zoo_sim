/******************************************************************************
** Name:		Evan Speciale
** Date:		July 21, 2019
** Description: Implementation of Tiger class.
******************************************************************************/
#include "Animal.hpp"
#include "Tiger.hpp"


//default constructor calls Animal default construtctor and initializes the remaining
//member variables.
Tiger::Tiger() : Animal()
{
	cost = 10000.00;
	numberOfBabies = 1;
	foodCost = baseFoodCost * 5;
	payoff = cost * 0.20;
}

//this constructor accepts an int, calls the Animal constructor with this int as an
//argument and initializes the remaining variables
Tiger::Tiger(int daysOld) : Animal(daysOld)
{
	cost = 10000.00;
	numberOfBabies = 1;
	foodCost = baseFoodCost * 5;
	payoff = cost * 0.20;
}

//get function overrides the Animal version of the same name.
double Tiger::getFoodCost()
{
	return foodCost;
}

