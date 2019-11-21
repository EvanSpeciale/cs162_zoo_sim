/******************************************************************************
** Name:		Evan Speciale
** Date:		July 21, 2019
** Description: Implementation of Zoo class
******************************************************************************/
#include "Zoo.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "Animal.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
using std::cin;
using std::cout;
using std::endl;
using std::copy;

//default zoo constructor initializes animal array sizes, creates the array of
//pointer objects for each animal type, and initializes bank balance, animal count,
//and zoo age.
Zoo::Zoo()
{

	tigers = new Animal*[tigerArraySize];		//creates arrays of poitners to
	penguins = new Animal*[penguinArraySize];	//animal objects and fills the
	turtles = new Animal*[turtleArraySize];		//arrays with nullptrs

	for (int i = 0; i < 10; i++)
	{
		tigers[i] = nullptr;
		penguins[i] = nullptr;
		turtles[i] = nullptr;
	}

	bankBalance = 100000.00;
	
	animalCount = 0;
	zooAge = 0;
}

//destructor deletes each pointer obect in each animal array, then deletes the arrays
Zoo::~Zoo()
{
	for (int i = 0; i < tigerArraySize; i++)
	{
		delete tigers[i];
		tigers[i] = nullptr;
	}
	for (int i = 0; i < penguinArraySize; i++)
	{
		delete penguins[i];
		penguins[i] = nullptr;
	}
	for (int i = 0; i < turtleArraySize; i++)
	{
		delete turtles[i];
		turtles[i] = nullptr;
	}

	delete[] tigers;
	delete[] penguins;
	delete[] turtles;
	tigers = nullptr;
	penguins = nullptr;
	turtles = nullptr;
}

//Zoo opening function prompts the user with the program and zoo information, then asks
//the user to buy 1 or 2 of each animal.
void Zoo::openZoo()
{
	int animalCount;
	cout << "Welcome to Zoo Simulator 2k19" << endl
		<< "-----------------------------" << endl << endl;
	cout << "You have $" << bankBalance << endl << endl;
	cout << "Before the Zoo opens:" << endl << endl;
	
	//input validation loop for user's choice to buy 1 or 2 tigers
	do
	{
		cin.clear();
		cout << "How many Tigers ($10,000 each) would you like to buy? [1-2]" << endl;
		cin >> animalCount;
		cout << endl;
		if (animalCount != 1 && animalCount != 2)
		{
			cout << "Please enter 1 or 2" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	} while (animalCount != 1 && animalCount != 2);
	tigerCount += animalCount;
	
	//creates Tiger objects and has a pointer in the tigers array point to each one
	for (int i = 0; i < tigerCount; i++)
	{
		tigers[i] = new Tiger(1);
		bankBalance -= tigers[i]->getCost();
	}

	//input validation loop for user's choice to buy 1 or 2 penguins
	do
	{
		animalCount = -1;
		cin.clear();
		cout << "How many Penguins ($1,000 each) would you like to buy? [1-2]" << endl;
		cin >> animalCount;
		cout << endl;
		if (animalCount != 1 && animalCount != 2)
		{
			cout << "Please enter 1 or 2" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	} while (animalCount != 1 && animalCount != 2);
	penguinCount += animalCount;
	
	//creates penguin objects and has a pointer in the penguins array point to each one
	for (int i = 0; i < penguinCount; i++)
	{
		penguins[i] = new Penguin(1);
		bankBalance -= penguins[i]->getCost();
	}

	//input validation loop for user's choice to buy 1 or 2 penguins
	do
	{
		animalCount = -1;
		cin.clear();
		cout << "How many Turtles ($100 each) would you like to buy? [1-2]" << endl;
		cin >> animalCount;
		cout << endl;
		if (animalCount != 1 && animalCount != 2)
		{
			cout << "Please enter 1 or 2" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	} while (animalCount != 1 && animalCount != 2);
	turtleCount += animalCount;
	
	//creates turtle objects and has a pointer in the turtles array point to each one
	for (int i = 0; i < turtleCount; i++)
	{
		turtles[i] = new Turtle(1);
		bankBalance -= turtles[i]->getCost();
	}

}

//goes through new-day operations for the zoo, printing the zoo's current stats, resetting
//payoff variables, and updating animal count and zoo age. This function calls to other zoo
//member functions which increment the age of all animals, subtract feed costs for all
//animals from the balance, and create a random event.
void Zoo::newDay()
{
	animalCount = tigerCount + penguinCount + turtleCount;
	dayPayoff = 0;
	bonusPayoff = 0;
	zooAge++;
	
	cout << "--------------------" << endl << "Day " << zooAge << ":" << endl
		<< "--------------------" << endl << endl;

	cout << "Current Balance: $" << bankBalance << endl << endl;
	cout << "Total Animals:\t" << animalCount << endl;
	cout << "Tigers:\t\t" << tigerCount << endl;
	cout << "Penguins:\t" << penguinCount << endl;
	cout << "Turtles:\t" << turtleCount << endl << endl;

	this->ageAndFeedAnimals();
	this->randomEvent();
}

//goes through end-of-day operations for the zoo, printing the total daily payoff and the
//updated balance. Offers the user the option to buy an adult animal of their choice. Checks
//to see if the zoo is out of money; if so, the program ends. Else, the function prompts
//the user to continue to the next day or quit.
bool Zoo::endOfDay()
{
	bool loop = true;	//as long as this bool is true, the main newDay and endOfDay loop in
						//main will keep running. If it is false, the program exits the loop

	//calculates daily payoff
	double tigerPayoff = tigerCount * (2000.00);
	double penguinPayoff = penguinCount * (100.00);
	double turtlePayoff = turtleCount * (5.00);
	double totalPayoff = tigerPayoff + penguinPayoff + turtlePayoff + bonusPayoff;

	//updates user with new balance calculation
	cout << "Here's what your animals earned today:" << endl
		<< "--------------------------------------" << endl
		<< "Tigers:\t\t$" << tigerPayoff << endl
		<< "Penguins:\t$" << penguinPayoff << endl
		<< "Turtles:\t$" << turtlePayoff << endl
		<< "Bonus:\t\t$" << bonusPayoff << endl << endl
		<< "For a total of $" << totalPayoff << "!!" << endl << endl;

	cout << "Balance as of Yesterday:\t$" << bankBalance << endl;
	cout << "Total earned today:\t\t$" << totalPayoff << endl;
	cout << "-------------------------------------------------" << endl;
	bankBalance += totalPayoff;
	cout << "New Balance:\t\t\t$" << bankBalance << endl << endl;

	char yesno;
	int animalChoice;
	int continueChoice;

	//prompts the user to choose if they want to buy an adult animal
	do
	{
		cin.clear();
		cout << "Would you like to buy an adult animal for your zoo? [Y/N]" << endl;
		cin >> yesno;
		if (yesno != 'y' && yesno != 'Y' && yesno != 'n' && yesno != 'N')
		{
			cout << "Please enter Y or N" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		} 
	} while (yesno != 'y' && yesno != 'Y' && yesno != 'n' && yesno != 'N');

	//if yes, prompts the user to choose which type of animal it wants to buy.
	//Then, calls to the buy function for the selected animal type and updates
	//balance
	if (yesno == 'y' || yesno == 'Y')
	{
		do
		{
			cin.clear();
			cout << "What kind of adult animal would you like to buy?" << endl
				<< "1 - Tiger - $10,000" << endl
				<< "2 - Penguin - $1,000" << endl
				<< "3 - Turtle - $100" << endl;
			cout << "Enter Selection: ";
			cin >> animalChoice;
			if (animalChoice != 1 && animalChoice != 2 && animalChoice != 3)
			{
				cout << "Please enter a valid choice [1-3]" << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
			cout << endl;
		} while (animalChoice != 1 && animalChoice != 2 && animalChoice != 3);

		switch (animalChoice)
		{
		case 1:
		{
			cout << "You got a new tiger!" << endl << endl;
			this->buyTiger();
			break;
		}
		case 2:
		{
			cout << "You got a new penguin!" << endl << endl;
			this->buyPenguin();
			break;
		}
		case 3:
		{
			cout << "You got a new turtle!" << endl << endl;
			this->buyTurtle();
			break;
		}
		}

		cout << "New Balance:\t$" << bankBalance << endl << endl;
	}

	//if the zoo is out of money, sets loop bool to false and exits the program
	if (bankBalance <= 0)
	{
		loop = false;
		cout << "You ran out of money and your zoo closed!" << endl;
	}
	
	//else prompts the user to continue to the next day or quit
	else
	{
		do
		{
			cin.clear();
			cout << "Would you like to move on to the next day? Or Quit?" << endl
				<< "1 - Next Day" << endl
				<< "2 - Quit Game" << endl;
			cout << "Enter Selection: ";
			cin >> continueChoice;
			if (continueChoice != 1 && continueChoice != 2)
			{
				cout << "Please enter a valid choice [1-2]" << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
			cout << endl;
		} while (continueChoice != 1 && continueChoice != 2);
	}

	switch (continueChoice)
	{
	case 1:
	{
		loop = true;
		break;
	}
	case 2:
		cout << "Goodbye!" << endl;
		loop = false;
		break;
	}
	
	return loop;
}

//generates a random number between 1 and 4 and executes the corresponding event function
void Zoo::randomEvent()
{
	int event;
	event = (int)(1 + rand() % 4);
	
	switch (event)
	{
	case 1:
	{
		//Animal gets sick
		this->sickAnimal();
		break;
	}
	case 2:
	{
		//Boost in zoo attendance
		this->attendanceBoom();
		break;
	}
	case 3:
	{
		//Baby animal is born
		this->babyAnimal();
		break;
	}
	case 4:
	{
		//nothing happens
		cout << "Nothing out of the ordinary happens!" << endl << endl;
		break;
	}
	}
}

//goes through each animal in each animal array, increases their age and subtracts feeding
//cost from balance
void Zoo::ageAndFeedAnimals()
{
	for (int i = 0; i < tigerCount; i++)
	{
		tigers[i]->ageAdvance();
		bankBalance -= tigers[i]->getFoodCost();
	}

	for (int i = 0; i < penguinCount; i++)
	{
		penguins[i]->ageAdvance();
		bankBalance -= penguins[i]->getFoodCost();
	}

	for (int i = 0; i < turtleCount; i++)
	{
		turtles[i]->ageAdvance();
		bankBalance -= turtles[i]->getFoodCost();
	}
}

//these buyAnimal functions increase the animal count, check if the array size
//needs to double, then creates a new adult animal and points the next empty
//pointer in the animal array to the new animal object
void Zoo::buyTiger()
{
	tempTigerCount = tigerCount + 1;
	this->arrayOverflowCheck();
	tigerCount = tempTigerCount;
	tigers[tigerCount - 1] = new Tiger(3);
	bankBalance -= tigers[0]->getCost();
}

void Zoo::buyPenguin()
{
	tempPenguinCount = penguinCount+1;
	this->arrayOverflowCheck();
	penguinCount = tempPenguinCount;
	penguins[penguinCount - 1] = new Penguin(3);
	bankBalance -= penguins[0]->getCost();
}

void Zoo::buyTurtle()
{
	tempTurtleCount = turtleCount + 1;
	this->arrayOverflowCheck();
	turtleCount = tempTurtleCount;
	turtles[turtleCount - 1] = new Turtle(3);
	bankBalance -= turtles[0]->getCost();
}

//checks if the number of each animal is greater than the size of the animal
//type's array. If so, creates a new array double the size, copies each element
//from the old array into the new array, then deletes the elements from the old
//array and assigns the new array to the old array.
void Zoo::arrayOverflowCheck()
{
	if (tempTigerCount > tigerArraySize)
	{
		tigerArraySize *= 2;
		Animal** tigersTemp = new Animal * [tigerArraySize];
		for (int i = 0; i < tigerCount; i++)
		{
			tigersTemp[i] = tigers[i];
			delete tigers[i];
			tigers[i] = nullptr;
		}
		//delete[] tigers;
		tigers = nullptr;
		tigers = tigersTemp;
	}

	if (tempPenguinCount > penguinArraySize)
	{
		penguinArraySize *= 2;
		Animal** penguinsTemp = new Animal * [penguinArraySize];
		for (int i = 0; i < penguinCount; i++)
		{
			penguinsTemp[i] = penguins[i];
			delete penguins[i];
			penguins[i] = nullptr;
		}
		//delete[] penguins;
		penguins = nullptr;
		penguins = penguinsTemp;
	}

	if (tempTurtleCount > turtleArraySize)
	{
		turtleArraySize *= 2;
		Animal** turtlesTemp = new Animal * [turtleArraySize];
		for (int i = 0; i < turtleCount; i++)
		{
			turtlesTemp[i] = turtles[i];
			delete turtles[i];
			turtles[i] = nullptr;
		}
		for (int i = 0; i < turtleCount; i++)
		//delete[] turtles;
		turtles = nullptr;
		turtles = turtlesTemp;
	}
}

//generates a random number between 1 and the total number of animals. The
//range of random numbers is proportionally divided among the three animal
//types (e.g. 1-4 is tigers, 5-10 is penguins, and 11-20 is turtles). The
//random number is then adjusted to choose the appropriate animal from the
//animal's array. The animal is deleted, the animals later in the array are
//shifted back in the array to fill the gap, and the animal type count is
//decremented.
void Zoo::sickAnimal()
{
	cout << "Oh no! One of your animals is sick and has to be" << endl
		<< "treated at a farm upstate :(" << endl << endl;
	int randomAnimal = (int)(1 + rand() % animalCount);

	if (randomAnimal >= 1 && randomAnimal <= tigerCount)
	{
		cout << "Say goodbye to your tiger friend!" << endl;
		delete tigers[randomAnimal - 1];						//deletes the randomly chosen animal
		tigers[randomAnimal - 1] = nullptr;
		for (int i = randomAnimal; i < tigerCount; i++)			//shifts every animal above the deleted one
		{														//down one spot in the array to fill the
			tigers[i - 1] = tigers[i];							//the gap.
		}
		delete tigers[tigerCount - 1];							//deletes the last tiger in the array since
		tigers[tigerCount - 1] = nullptr;						//it was copied to the spot below it.
		tigerCount--;											//decrements animal counter
	}
	else if (randomAnimal > tigerCount &&
		randomAnimal <= (tigerCount + penguinCount))
	{
		cout << "Say goodbye to your penguin friend!" << endl;
		randomAnimal -= tigerCount;
		delete penguins[randomAnimal - 1];
		penguins[randomAnimal - 1] = nullptr;
		for (int i = randomAnimal; i < penguinCount; i++)
		{
			penguins[i - 1] = penguins[i];
		}
		delete penguins[penguinCount - 1];
		penguins[penguinCount - 1] = nullptr;
		penguinCount--;

	}
	else
	{
		cout << "Say goodbye to your turtle friend!" << endl;
		randomAnimal -= (tigerCount + penguinCount);
		delete turtles[randomAnimal - 1];
		turtles[randomAnimal - 1] = nullptr;
		for (int i = randomAnimal; i < turtleCount; i++)
		{
			turtles[i - 1] = turtles[i];
		}
		delete turtles[turtleCount - 1];
		turtles[turtleCount - 1] = nullptr;
		turtleCount--;
	}

	cout << endl;
}

//generates a random double between 250 and 500 and multiplies it by the number
//of tigers in the zoo to calculate the total bonuspayoff
void Zoo::attendanceBoom()
{
	cout << "A high school marching band festival is in town and" << endl
		<< "Zoo attendance is booming! Guests love the tigers!" << endl << endl;
	double tigerBonus;
	tigerBonus = (double)rand() / (RAND_MAX) * (250) + 250;
	bonusPayoff += tigerBonus*tigerCount;

	cout << "Each tiger gets a bonus payoff of $" << tigerBonus << endl
		<< " for a total of $" << tigerBonus * tigerCount << "!!" << endl <<endl;
}

//First, this function checks if any animals are adults. If not, the function
//ends and tells the user no animals are old enough to have a baby. If there is
//at least one adult, the function then randomly selects an animal (in the same
//fashion as the sickAnimal function) and checks if it is an adult. If not, it
//randomly selects more animals until one is an adult. Once it hits an adult
//animal, a new animal of the same type is added to the zoo.
void Zoo::babyAnimal()
{
	bool ageCheck = false;
	int babyType;
	bool anyAdult = false;
	
	//these for loops go through all animals in each array, and if at least one
	//is an adult, the anyAdult bool is set to true and the function can get an
	//animal to have a baby
	for (int i = 0; i < tigerCount; i++)
	{
		if (tigers[i]->isAdult())
		{
			anyAdult = true;
		}
	}
	for (int i = 0; i < penguinCount; i++)
	{
		if (penguins[i]->isAdult())
		{
			anyAdult = true;
		}
	}
	for (int i = 0; i < turtleCount; i++)
	{
		if (turtles[i]->isAdult())
		{
			anyAdult = true;
		}
	}

	//if there is at least one adult, an animal is randomly chosen until an
	//adult is chosen
	if (anyAdult)
	{
		do
		{
			int randomAnimal = (int)(1 + rand() % animalCount);

			if (randomAnimal >= 1 && randomAnimal <= tigerCount)
			{
				ageCheck = tigers[randomAnimal - 1]->isAdult();
				babyType = 1;
			}
			else if (randomAnimal > tigerCount &&
				randomAnimal <= (tigerCount + penguinCount))
			{
				randomAnimal -= tigerCount;
				ageCheck = penguins[randomAnimal - 1]->isAdult();
				babyType = 2;
			}
			else
			{
				randomAnimal -= (tigerCount + penguinCount);
				ageCheck = turtles[randomAnimal - 1]->isAdult();
				babyType = 3;
			}
		} while (!ageCheck);

		//creates a new animal of the same type as the one chosen (age 0) and
		//adds it to the relevant animal array
		switch (babyType)
		{
		case 1:
		{
			cout << "Congratulations! One of your tigers had "
				<< tigers[0]->getNumberOfBabies() << " babies!" << endl;
			int oldCount = tigerCount;
			tempTigerCount = tigerCount + tigers[0]->getNumberOfBabies();
			this->arrayOverflowCheck();
			tigerCount = tempTigerCount;
			for (int i = oldCount; i < tigerCount; i++)
			{
				tigers[i] = new Tiger(0);
			}
			break;
		}
		case 2:
		{
			cout << "Congratulations! One of your penguins had "
				<< penguins[0]->getNumberOfBabies() << " babies!" << endl;
			int oldCount = penguinCount;
			tempPenguinCount = penguinCount + penguins[0]->getNumberOfBabies();
			this->arrayOverflowCheck();
			penguinCount = tempPenguinCount;
			for (int i = oldCount; i < penguinCount; i++)
			{
				penguins[i] = new Penguin(0);
			}
			break;
		}
		case 3:
		{
			cout << "Congratulations! One of your turtles had "
				<< turtles[0]->getNumberOfBabies() << " babies!" << endl;
			int oldCount = turtleCount;
			tempTurtleCount = turtleCount + turtles[0]->getNumberOfBabies();
			this->arrayOverflowCheck();
			turtleCount = tempTurtleCount;
			for (int i = oldCount; i < turtleCount; i++)
			{
				turtles[i] = new Turtle(0);
			}
			break;
		}
		}
	}
	
	//if no animal is an adult, prints this message and exits the function
	else
	{
		cout << "None of your animals are old enough to have a baby!" << endl;
	}
	
	cout << endl;
}
