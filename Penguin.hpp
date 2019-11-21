/******************************************************************************
** Name:		Evan Speciale
** Date:		July 21, 2019
** Description: Declaration of Penguin class, derived from Animal base class.
**				Includes new food cost variable, two constructors, and one get
**				function which overrides the base class method of the same name.
******************************************************************************/
#ifndef PENGUIN_HPP
#define PENGUIN_HPP
#include "Animal.hpp"

class Penguin : public Animal
{
private:
	double foodCost;
public:
	Penguin();
	Penguin(int);
	double getFoodCost();	//overrides Animal method of the same name

};

#endif //PENGUIN_HPP