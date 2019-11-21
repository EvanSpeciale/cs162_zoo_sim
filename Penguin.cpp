/******************************************************************************
** Name:		Evan Speciale
** Date:		July 21, 2019
** Description: Implementation of Penguin class.
******************************************************************************/
#include "Animal.hpp"
#include "Penguin.hpp"


//default constructor calls Animal default construtctor and initializes the remaining
//member variables.
Penguin::Penguin() : Animal()
{
	cost = 1000.00;
	numberOfBabies = 5;
	foodCost = baseFoodCost;
	payoff = cost * 0.10;
}

//this constructor accepts an int, calls the Animal constructor with this int as an
//argument and initializes the remaining variables
Penguin::Penguin(int daysOld) : Animal(daysOld)
{
	cost = 1000.00;
	numberOfBabies = 5;
	foodCost = baseFoodCost;
	payoff = cost * 0.10;
}

//get function overrides the Animal version of the same name.
double Penguin::getFoodCost()
{
	return foodCost;
}
