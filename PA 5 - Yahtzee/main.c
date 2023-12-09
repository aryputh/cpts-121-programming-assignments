/*
*	Name: Aryan Puthran
*	Date: 10/14/2023
*	Course: CPT_S 121
*	Assignment: Programming Assignment 5
*
*	Description: This program will run the popular
*		game, Yahtzee. This is where the logic is used.
*/

#include "functions.h"

int main()
{
	// Declare required variables
	int menuChoice = 0, wantsToReplay = 1, currentNumRolls = 0, currentCombination = 0, dieToReroll = 0, diceSum = 0, currentPlayer = 1;
	int player1PointsUpper = 0, player1PointsLower = 0, player2PointsUpper = 0, player2PointsLower = 0, roundNumber = 1;
	int diceRoll[5] = { 0 }, usedCombosPlayer1[13] = { 0 }, usedCombosPlayer2[13] = { 0 }, diceRollInv[6] = { 0 };
	char rerollResponse = '\0';

	// Call srand so numbers are random
	srand((unsigned int)time(NULL));

	do
	{
		// Print out the menu for the user
		printGameMenu();

		// Get user input and validate it
		do
		{
			// Get the user's menu choice
			scanf("%d", &menuChoice);
		}
		while (!(menuChoice == 1 || menuChoice == 2 || menuChoice == 3));

		// Perform the correct action based on given number
		if (menuChoice == 1)
		{
			// Clear screen
			system("cls");

			// Print out the game rules and reset choice
			printGameRules();
			menuChoice = 0;
		}
		else if (menuChoice == 2)
		{
			// Loops the game for all 14 rounds
			do
			{
				// Play the game and reset choice
				printf("\nPress any key to roll your first 5 dice!\n");
				system("pause");

				// Roll dice, print, and then increment num of rolls
				rollDice(diceRoll);
				printArrayValues(diceRoll, 5);
				currentNumRolls++;

				// Print out roll combinations
				if (currentPlayer == 1)
				{
					printRollCombinations(usedCombosPlayer1);
				}
				else
				{
					printRollCombinations(usedCombosPlayer2);
				}

				// Rerolls if the player wants and if they can
				do
				{
					// Ask user if they want to reroll
					printf("\nWant to use this roll for choosing a combination? (%d rerolls left)\n", 3 - currentNumRolls);
					printf("Y: Yes, please.\n");
					printf("N: No, thanks.\n");

					// Scans if player wants to reroll and validates
					do
					{
						scanf(" %c", &rerollResponse);
					}
					while (!(rerollResponse == 'Y' || rerollResponse == 'N'));

					// Rerolls dice if wanted
					if (rerollResponse == 'N')
					{
						// Prompts user for die to reroll
						printf("\n1 - 5: What die would you like to reroll?\n");

						// Scans what die player wants to reroll and validate it
						do
						{
							scanf("%d", &dieToReroll);
						}
						while (dieToReroll < 1 || dieToReroll > 5);

						// Print a spacer
						printf("\n");

						// Rerolls the specified die and reset values
						diceRoll[dieToReroll - 1] = rerollDie();
						printArrayValues(diceRoll, 5);
						currentNumRolls++;
						rerollResponse = '\0';
						dieToReroll = 0;

						// Print out roll combinations
						if (currentPlayer == 1)
						{
							printRollCombinations(usedCombosPlayer1);
						}
						else
						{
							printRollCombinations(usedCombosPlayer2);
						}
					}
				}
				while (currentNumRolls < 3 && rerollResponse != 'Y');

				// Reset number of rolls and response
				currentNumRolls = 0;
				rerollResponse = '\0';

				// Populate dice inventory with correct numbers and sum dice
				populateDiceInventory(diceRollInv, diceRoll);
				diceSum = sumDieValues(diceRoll);

				// Prompt user for combination to use
				printf("\nWhich combination would you like to choose?\n");

				if (currentPlayer == 1)
				{
					// Scans what combo player wants and validate it
					do
					{
						scanf("%d", &currentCombination);
					}
					while ((currentCombination < 1 || currentCombination > 13) || (isCombinationUsed(currentCombination, usedCombosPlayer1) == 1));

					// Mark combination as used
					usedCombosPlayer1[currentCombination - 1] = 1;
				}
				else
				{
					// Scans what combo player wants and validate it
					do
					{
						scanf("%d", &currentCombination);
					}
					while ((currentCombination < 1 || currentCombination > 13) || (isCombinationUsed(currentCombination, usedCombosPlayer2) == 1));

					// Mark combination as used
					usedCombosPlayer2[currentCombination - 1] = 1;
				}

				// Clear the screen
				system("cls");

				// Assign points based on combo and validation, then reset combo chosen
				if (currentPlayer == 1)
				{
					// If the combination is in the upper or lower section
					if (currentCombination < 7)
					{
						player1PointsUpper += addPointsBasedOnCombo(currentCombination, diceRollInv, diceSum);
					}
					else
					{
						player1PointsLower += addPointsBasedOnCombo(currentCombination, diceRollInv, diceSum);
					}
				}
				else
				{
					// If the combination is in the upper or lower section
					if (currentCombination < 7)
					{
						player2PointsUpper += addPointsBasedOnCombo(currentCombination, diceRollInv, diceSum);
					}
					else
					{
						player2PointsLower += addPointsBasedOnCombo(currentCombination, diceRollInv, diceSum);
					}
				}

				currentCombination = 0;

				// Change current player and print new round instructions
				if (currentPlayer == 1)
				{
					currentPlayer = 2;
					printf("\nPlayer 1's score: %d\n", player1PointsLower + player1PointsUpper);
					printf("\nPlayer 2's turn!\n");
				}
				else
				{
					currentPlayer = 1;
					roundNumber++;
					printf("\nPlayer 2's score: %d\n", player2PointsLower + player2PointsUpper);
					printf("\nNew round starting! (Round %d/14)\n", roundNumber);

					// Wait for any key press
					system("pause");

					printf("\nPlayer 1's turn!\n");
				}
			}
			while (roundNumber < 15);

			// Add score bonus if condition is met
			if (player1PointsUpper >= 63)
			{
				player1PointsUpper += 35;
			}
			
			if (player2PointsUpper >= 63)
			{
				player2PointsUpper += 35;
			}

			// Print scores for each player
			printf("\nPlayer 1's score: %d\n", player1PointsLower + player1PointsUpper);
			printf("\nPlayer 2's score: %d\n", player2PointsLower + player2PointsUpper);
			
			// Print the winner out
			if (player1PointsLower + player1PointsUpper > player2PointsLower + player2PointsUpper)
			{
				printf("\nPlayer 1 won!\n");
			}
			else if (player1PointsLower + player1PointsUpper < player2PointsLower + player2PointsUpper)
			{
				printf("\nPlayer 2 won!\n");
			}
			else
			{
				printf("\nIt's a tie!\n");
			}

			menuChoice = 0;
		}
		else
		{
			// Clears screen, print goodbye message and exit game
			system("cls");
			printf("Thanks for playing!\n");
			wantsToReplay = 0;
			menuChoice = 0;
		}
	}
	while (wantsToReplay == 1);

	return 0;
}