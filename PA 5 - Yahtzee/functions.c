/*
*	Name: Aryan Puthran
*	Date: 10/14/2023
*	Course: CPT_S 121
*	Assignment: Programming Assignment 5
*
*	Description: This program will run the popular
*		game, Yahtzee. This is where all the functions
*		will be kept.
*/

#include "functions.h"

/*
*	Description: Prints the game menu with options to play,
*		view rules, or exit.
*	Date: 10/14/2023
*
*	Preconditions: None
*	Postconditions: The menu is printed out.
*/
void printGameMenu()
{
	// Print out menu
	printf("\nWelcome to Yahtzee! What would you like to do?\n");
	printf("1. Print the rules.\n");
	printf("2. Start a game!\n");
	printf("3. Exit.\n");
}

/*
*	Description: Prints out the game rules.
*	Date: 10/14/2023
*
*	Preconditions: None.
*	Postconditions: The game rules are printed out.
*/
void printGameRules()
{
	// Print out rules
	printf("\n- You must outduel the other player by scoring the most points.\n");
	printf("- Points are obtained by rolling 5 die across 13 rounds.\n");
	printf("- During each round, you get to roll upto 3 times to get a combination.\n");
	printf("- You can only get a combination once, so choose wisely!\n");
	printf("- You must get the most points to win!\n");
}

/*
*	Description: Sets each space to a random die roll number.
*	Date: 10/14/2023
*
*	Preconditions: dieRoll has 5 elements.
*	Postconditions: dieRoll is adjusted as intended.
*/
void rollDice(int diceRoll[])
{
	// Iterate and set to a random die number
	for (int i = 0; i < 5; i++)
	{
		diceRoll[i] = rand() % 6 + 1;
	}
}

/*
*	Description: Prints out the specified numbers in the chosen array.
*	Date: 10/14/2023
*
*	Preconditions: numValues less than number of elements in array.
*	Postconditions: Specified number of values are printed out.
*/
void printArrayValues(int array[], int numValues)
{
	// Iternate and print out numbers
	for (int i = 0; i < numValues; i++)
	{
		printf("%d. %d\n", i + 1, array[i]);
	}
}

/*
*	Description: Prints out combinations.
*	Date: 10/18/2023
*
*	Preconditions: usedCombos is has 13 elements.
*	Postconditions: The unused combinations are printed out.
*/
void printRollCombinations(int usedCombos[])
{
	// Create an array full of possible combos
	char *combos[13] = { "1. Sum of 1's (Upper)\n", "2. Sum of 2's (Upper)\n", "3. Sum of 3's (Upper)\n",
					"4. Sum of 4's (Upper)\n", "5. Sum of 5's (Upper)\n", "6. Sum of 6's (Upper)\n",
					"7. 3-of-a-kind (Lower)\n", "8. 4-of-a-kind (Lower)\n", "9. Full house (1 pair + 3-of-a-kind) (Lower)\n",
					"10. Small straight (Sequence of 4 dice) (Lower)\n", "11. Large straight (Sequence of 5 dice) (Lower)\n",
					"12. Yahtzee (5-of-a-kind) (Lower)\n", "13. Chance (Wild card) (Lower)\n" };

	// Print out combinations based on used status
	printf("\nYahtzee Combinations:\n");
	
	for (int i = 0; i < 13; i++)
	{
		if (usedCombos[i] == 0)
		{
			printf("%s", combos[i]);
		}
	}
}

/*
*	Description: Rerolls a single die.
*	Date: 10/15/2023
*
*	Preconditions: None.
*	Postconditions: Return a random die value.
*/
int rerollDie()
{
	// Return a random die number
	return rand() % 6 + 1;
}

/*
*	Description: Checks if the given combo has not been used.
*		Returns 1 if used, 0 else. 
*	Date: 10/15/2023
*
*	Preconditions: usedCombos has 13 elements.
*	Postconditions: Returns 1 or 0 accurately.
*/
int isCombinationUsed(int chosenCombination, int usedCombos[])
{
	// Check if combo has been used and return 1
	if (usedCombos[chosenCombination - 1] == 1)
	{
		return 1;
	}

	// Otherwise, return 0
	return 0;
}

/*
*	Description: Counts how many of each die value there is.
*	Date: 10/15/2023
*
*	Preconditions: Both passed in arrays are valid. diceRoll has 5 elements.
*	Postconditions: An inventory of each die number.
*/
void populateDiceInventory(int diceRollInv[], int diceRoll[])
{
	// Count number of faces of each value
	for (int i = 0; i < 5; i++)
	{
		diceRollInv[diceRoll[i] - 1]++;
	}
}

/*
*	Description: Adds all the die faces together.
*	Date: 10/15/2023
*
*	Preconditions: diceRoll has 5 elements.
*	Postconditions: The sum is returned.
*/
int sumDieValues(int diceRoll[])
{
	// Declare required variables
	int sum = 0;

	// Iterate and add value to sum
	for (int i = 0; i < 5; i++)
	{
		sum += diceRoll[i];
	}

	// Return the sum
	return sum;
}

/*
*	Description: Calculates points based on the chosen combination
*		and if it's valid.
*	Date: 10/15/2023
*
*	Preconditions: chosenCombination is in range [1, 13] and
		diceRoll is valid.
*	Postconditions: The number of points is returned.
*/
int addPointsBasedOnCombo(int chosenCombination, int diceRollInv[], int sumDice)
{
	// Find point value based on validation and inventory
	switch (chosenCombination)
	{
	case 1: // Sum of 1's

		return 1 * diceRollInv[0];
		break;

	case 2: // Sum of 2's

		return 2 * diceRollInv[1];
		break;

	case 3: // Sum of 3's

		return 3 * diceRollInv[2];
		break;

	case 4: // Sum of 4's

		return 4 * diceRollInv[3];
		break;

	case 5: // Sum of 5's

		return 5 * diceRollInv[4];
		break;

	case 6: // Sum of 6's

		return 6 * diceRollInv[5];
		break;

	case 7: // 3-of-a-kind

		if (diceRollInv[0] >= 3 || diceRollInv[1] >= 3 || diceRollInv[2] >= 3 || diceRollInv[3] >= 3 ||
			diceRollInv[4] >= 3 || diceRollInv[5] >= 3)
		{
			return sumDice;
		}
		break;

	case 8: // 4-of-a-kind

		if (diceRollInv[0] >= 4 || diceRollInv[1] >= 4 || diceRollInv[2] >= 4 || diceRollInv[3] >= 4 ||
			diceRollInv[4] >= 4 || diceRollInv[5] >= 4)
		{
			return sumDice;
		}
		break;

	case 9: // Full house

		if (diceRollInv[0] == 2 || diceRollInv[1] == 2 || diceRollInv[2] == 2 || diceRollInv[3] == 2 ||
			diceRollInv[4] == 2 || diceRollInv[5] == 2)
		{
			if (diceRollInv[0] == 3 || diceRollInv[1] == 3 || diceRollInv[2] == 3 || diceRollInv[3] == 3 ||
				diceRollInv[4] == 3 || diceRollInv[5] == 3)
			{
				return 25;
			}
		}
		break;

	case 10: // Small straight

		if ((diceRollInv[0] == 1 && diceRollInv[1] == 1 && diceRollInv[2] == 1 && diceRollInv[3] == 1) ||
			(diceRollInv[1] == 1 && diceRollInv[2] == 1 && diceRollInv[3] == 1 && diceRollInv[4] == 1) ||
			(diceRollInv[2] == 1 && diceRollInv[3] == 1 && diceRollInv[4] == 1 && diceRollInv[5] == 1))
		{
			return 30;
		}
		break;

	case 11: // Large straight

		if ((diceRollInv[0] == 1 && diceRollInv[1] == 1 && diceRollInv[2] == 1 && diceRollInv[3] == 1 && diceRollInv[4] == 1) ||
			(diceRollInv[1] == 1 && diceRollInv[2] == 1 && diceRollInv[3] == 1 && diceRollInv[4] == 1 && diceRollInv[5] == 1))
		{
			return 40;
		}
		break;

	case 12: // Yahtzee

		if (diceRollInv[0] == 5 || diceRollInv[1] == 5 || diceRollInv[2] == 5 || diceRollInv[3] == 5 ||
			diceRollInv[4] == 5 || diceRollInv[5] == 5)
		{
			return 50;
		}
		break;

	case 13: // Chance

		return sumDice;
		break;

	default:

		printf("\nAn error occured while determining a score value.\n");
		break;

	}

	// Return 0 points if combo is invalid
	return 0;
}