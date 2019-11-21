/******************************************************************************
** Name:		Evan Speciale
** Date:		July 21, 2019
** Description: Class declaration for Animal class; includes member variables
**				for age, cost, number of babies, constant base food cost, and
**				payoff for all animals. Class methods include default and
**				argument-taking constructors, a check to see if an animal is
**				an adult, and get functions for necessary member variables.
******************************************************************************/
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
protected:
	int age;
	double cost;
	int numberOfBabies;
	const double baseFoodCost = 10.00;
	double payoff;
public:
	Animal();
	Animal(int);
	bool isAdult();
	void ageAdvance();
	int getAge();
	double getCost();
	virtual double getFoodCost(); //virtual function to be overridden by derived class versions
	int getNumberOfBabies();
};
#endif //ANIMAL_HPP