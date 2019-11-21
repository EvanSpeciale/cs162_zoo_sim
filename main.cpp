/******************************************************************************
** Name:		Evan Speciale
** Date:		July 21, 2019
** Description: Main function; seed random function with current time, creates
**				a Zoo class object, Prints the Zoo's opening lines and prompts,
**				then goes into a loop for each new day that continues as long
**				as the user doesn't choose to quit the program or run out of
**				money.
******************************************************************************/
#include "Zoo.hpp"
#include <iostream>
#include <ctime>

int main()
{
	srand(time(NULL));
	
	bool loop = true;
	Zoo zoo;
	zoo.openZoo();

	do
	{
		zoo.newDay();
		loop = zoo.endOfDay();
	} while (loop);
	
	return 0;
}