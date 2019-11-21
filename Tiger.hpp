/******************************************************************************
** Name:		Evan Speciale
** Date:		July 21, 2019
** Description: Declaration of Tiger class, derived from Animal base class.
**				Includes new food cost variable, two constructors, and one get
**				function which overrides the base class method of the same name.
******************************************************************************/
#ifndef TIGER_HPP
#define TIGER_HPP
#include "Animal.hpp"

class Tiger : public Animal
{
private:
	double foodCost;
public:
	Tiger();
	Tiger(int);
	double getFoodCost();	//overrides Animal method of the same name

};

#endif //TIGER_HPP