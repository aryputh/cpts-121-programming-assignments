/*
*	Name: Aryan Puthran
*	Date: 9/27/2023
*	Course: CPT_S 121
*	Assignment: Programming Assignment 4
*
*	Description: This program will run a game of craps, and ask for input/output accordingly.
*		This game will use random numbers, function decomposition, and more. This file
*		houses the main function, the heart of the program.
*/

#include "functions.h"

int main(void)
{
	// Declare required variables
	int die1 = 0, die2 = 0, diceSum = 0, point = 0, numRolls = 0, winLoseNeither = -1;
	int isGameOver = 0, wantsToReplay = 0;
	double initialBankBalance = 0.0, bankBalance = 0.0, wager = 0.0;

	// Keeps replaying the game until you choose not to
	do
	{
		// Reset game over status and print game rules
		isGameOver = 0;
		wantsToReplay = 0;
		print_game_rules();

		// Get bank balance and wager amount, perform validation
		initialBankBalance = get_bank_balance();
		bankBalance = initialBankBalance;
		do
		{
			wager = get_wager_amount();
		}
		while (check_wager_amount(wager, bankBalance) == 0);

		// Initial roll, print and find sum
		roll_die(&die1, &die2);
		numRolls++;

		printf("You rolled a %d and a %d.\n", die1, die2);
		diceSum = calculate_sum_dice(die1, die2);
		winLoseNeither = is_win_loss_or_point(diceSum);

		// Check if player wins, loses, or gets points on the initial roll
		if (winLoseNeither == 1)
		{
			// Player wins
			printf("You won the game (sum is 7 or 11)!\n");
			isGameOver = 1;

			// Adjust bank balance and print it
			bankBalance = adjust_bank_balance(bankBalance, wager, 1);
			printf("Your new bank balance is $%.2f!\n", bankBalance);

			// Check if player wants to replay
			printf("Would you like to replay again? (y = 1, n = 0)\n");
			scanf("%d", &wantsToReplay);
		}
		else if (winLoseNeither == 0)
		{
			// Player loses
			printf("You lost the game (sum is 2, 3, or 12).\n");
			isGameOver = 1;

			// Adjust bank balance and print it
			bankBalance = adjust_bank_balance(bankBalance, wager, 0);
			printf("Your new bank balance is $%.2f.\n", bankBalance);

			// Check if player wants to replay
			printf("Would you like to replay again? (y = 1, n = 0)\n");
			scanf("%d", &wantsToReplay);
		}
		else
		{
			// Player makes their point
			point = diceSum;
			printf("You made your point! You must match %d in later rolls.\n", point);

			// A chatter message
			chatter_messages(numRolls, winLoseNeither, initialBankBalance, bankBalance);

			// Adjust bank balance and print it
			bankBalance = adjust_bank_balance(bankBalance, wager, 1);
			printf("Your new bank balance is $%.2f!\n", bankBalance);

			// Get wager amount and validate it
			do
			{
				wager = get_wager_amount();
			}
			while (check_wager_amount(wager, bankBalance) == 0);

			// Keep playing until you win, lose, or neither.
			while (isGameOver == 0)
			{
				// Another roll, print and find sum
				roll_die(&die1, &die2);
				numRolls++;

				printf("You rolled a %d and a %d.\n", die1, die2);
				diceSum = calculate_sum_dice(die1, die2);
				winLoseNeither = is_point_loss_or_neither(diceSum, point);

				if (winLoseNeither == 1)
				{
					// Player wins
					printf("You won the game (sum is point)!\n");
					isGameOver = 1;

					// Adjust bank balance and print it
					bankBalance = adjust_bank_balance(bankBalance, wager, 1);
					printf("Your new bank balance is $%.2f!\n", bankBalance);

					// Check if player wants to replay
					printf("Would you like to replay again? (y = 1, n = 0)\n");
					scanf("%d", &wantsToReplay);
				}
				else if (winLoseNeither == 0)
				{
					// Player loses
					printf("You lost the game (sum is 7).\n");
					isGameOver = 1;

					// Adjust bank balance and print it
					bankBalance = adjust_bank_balance(bankBalance, wager, 0);
					printf("Your new bank balance is $%.2f.\n", bankBalance);

					// Check if player wants to replay
					printf("Would you like to replay again? (y = 1, n = 0)\n");
					scanf("%d", &wantsToReplay);
				}
				else
				{
					// If the player hasn't won or lost
					// Adjust bank balance and print it
					bankBalance = adjust_bank_balance(bankBalance, wager, 1);
					printf("Your new bank balance is $%.2f!\n", bankBalance);

					// A chatter message
					chatter_messages(numRolls, winLoseNeither, initialBankBalance, bankBalance);

					// Get wager amount and validate it
					do
					{
						wager = get_wager_amount();
					}
					while (check_wager_amount(wager, bankBalance) == 0);
				}
			}
		}
	}
	while (wantsToReplay == 1);

	return 0;
}