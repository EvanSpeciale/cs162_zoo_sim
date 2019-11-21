/******************************************************************************
** Name:		Evan Speciale
** Date:		July 21, 2019
** Description: Declaration of Turtle class, derived from Animal base class.
**				Includes new food cost variable, two constructors, and one get
**				function which overrides the base class method of the same name.
******************************************************************************/
#ifndef TURTLE_HPP
#define TURTLE_HPP
#include "Animal.hpp"

class Turtle : public Animal
{
private:
	double foodCost;
public:
	Turtle();
	Turtle(int);
	double getFoodCost();	//overrides Animal method of the same name
};

#endif //TURTLE_HPP