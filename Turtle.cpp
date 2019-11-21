/******************************************************************************
** Name:		Evan Speciale
** Date:		July 21, 2019
** Description: Implementation of Turtle class.
******************************************************************************/
#include "Animal.hpp"
#include "Turtle.hpp"


//default constructor calls Animal default construtctor and initializes the remaining
//member variables.
Turtle::Turtle() : Animal()
{
	cost = 100.00;
	numberOfBabies = 10;
	foodCost = baseFoodCost * 0.5;
	payoff = cost * 0.05;
}

//this constructor accepts an int, calls the Animal constructor with this int as an
//argument and initializes the remaining variables
Turtle::Turtle(int daysOld) : Animal(daysOld)
{
	cost = 100.00;
	numberOfBabies = 10;
	foodCost = baseFoodCost * 0.5;
	payoff = cost * 0.05;
}

//get function overrides the Animal version of the same name.
double Turtle::getFoodCost()
{
	return foodCost;
}