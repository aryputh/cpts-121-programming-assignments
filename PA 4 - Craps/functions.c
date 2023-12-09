/*
*	Name: Aryan Puthran
*	Date: 9/27/2023
*	Course: CPT_S 121
*	Assignment: Programming Assignment 4
*
*	Description: This program will run a game of craps, and ask for input/output accordingly.
*		This game will use random numbers, function decomposition, and more. This file
*		defines all the functions and what they do.
*/

#include "functions.h"

/*
*	Description: Prints out the game rules of "craps".
*	Date: 9/27/2023
*
*	Preconditions: None
*	Postconditions: The game rules are printed out.
*/
void print_game_rules(void)
{
	// Prints the simplified game rules
	printf("1. You roll 2 dice.\n");
	printf("2. If the sum of the 2 dice are 7 or 11, you win!\n");
	printf("3. If the sum of the 2 dice are 2, 3 or 12, you \"crap\".\n");
	printf("4. If the sum of the 2 dice are 4, 5, 6, 8, 9, or 10, it becomes your \"point\"!\n");
	printf("5. You keep rolling until you \"make your point\". If you roll a 7 before that, you lose.\n\n");
}

/*
*	Description: Gets the bank balance to be used for wagering.
*	Date: 9/27/2023
*
*	Preconditions: Bank balance is defined and has a double value.
*	Postconditions: Returns the bank balance.
*/
double get_bank_balance(void)
{
	// Create required variable
	double bank_balance = 0.0;

	// Prompt user and get balance
	printf("What is your starting bank balance?\n");
	scanf("%lf", &bank_balance);

	return bank_balance;
}

/*
*	Description: Prompts the player for a wager and returns that.
*	Date: 9/27/2023
*
*	Preconditions: A double is given as a response.
*	Postconditions: The wager (double) is returned.
*/
double get_wager_amount(void)
{
	// Create required variable
	double wager_amount = 0.0;

	// Prompt user and get wager
	printf("What is your wager amount?\n");
	scanf("%lf", &wager_amount);

	return wager_amount;
}

/*
*	Description: Checks to see if you can wager a certain amount, determined by
*		how much money you have in your account.
*	Date: 9/27/2023
*
*	Preconditions: Provided with two doubles.
*	Postconditions: Returns 1 if you don't wager too much, 0 otherwise.
*/
int check_wager_amount(double wager, double balance)
{
	if (wager >= 0 && wager <= balance)
	{
		return 1;
	}

	return 0;
}

/*
*	Description: Rolls a die, and sets a random number between and including
*		1 and 6 to the die variable.
*	Date: 9/27/2023
*
*	Preconditions: None.
*	Postconditions: *diePtr is a number in the range [1, 6].
*/
void roll_die(int *die1Ptr, int* die2Ptr)
{
	// Makes random start at different points
	srand((unsigned int)time(NULL));

	// Get and set to a random number in the range [1, 6]
	*die1Ptr = (rand() % 6) + 1;
	*die2Ptr = (rand() % 6) + 1;
}

/*
*	Description: Takes 2 die values and sums them up, returning the sum.
*	Date: 9/27/2023
*
*	Preconditions: Valid integers are provided, and are in the range [1, 6]
*		each.
*	Postconditions: A sum in the range [2, 12] is returned.
*/
int calculate_sum_dice(int die1_value, int die2_value)
{
	// Sums and returns the given arguments
	return die1_value + die2_value;
}

/*
*	Description: Determines the result on the first dice roll. 1 is returned
*		if the player wins, 0 is returned if the player "craps", and -1 is
*		returned otherwise.
*	Date: 9/27/2023
*
*	Preconditions: A valid integer in the range [2, 12] is given.
*	Postconditions: One of three states will be returned (-1, 0, 1);
*/
int is_win_loss_or_point(int sum_dice)
{
	// Checks if player won, lost, or becomes a point
	if (sum_dice == 7 || sum_dice == 11)
	{
		return 1;
	}
	else if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12)
	{
		return 0;
	}

	return -1;
}

/*
*	Description: Determines result of rolls after the first roll. If the sum is
*		the point value, 1 is returned. If the sum is 7, 0 is returned, and else
*		-1 is returned.
*	Date: 9/27/2023
*
*	Preconditions: Valid arguments are provided.
*	Postconditions: An int with a valid status value is returned (-1, 0, 1).
*/
int is_point_loss_or_neither(int sum_dice, int point_value)
{
	// Checks if player won, lost, or continue playing 
	if (sum_dice == point_value)
	{
		return 1;
	}
	else if (sum_dice == 7)
	{
		return 0;
	}

	return -1;
}

/*
*	Description: Adds/subtracts the wager amount from the bank balance. If add_or_subtract
*		is 1, wager is added, if it's 0, wager is subtracted.
*	Date: 9/27/2023
*
*	Preconditions: add_or_subtract is either 0 or 1. Other arguments are valid.
*	Postconditions: The adjusted bank balance.
*/
double adjust_bank_balance(double bank_balance, double
	wager_amount, int add_or_subtract)
{
	// If adding, add amount
	if (add_or_subtract == 1)
	{
		return bank_balance += wager_amount;
	}
	
	// Subtract amount if not adding
	return bank_balance -= wager_amount;
}

/*
*	Description: Prints a customized message based on the status of the player.
*	Date: 9/27/2023
*
*	Preconditions: Valid arguments are given.
*	Postconditions: A custom message is displayed to the screen.
*/
void chatter_messages(int number_rolls, int win_loss_neither, double
	initial_bank_balance, double current_bank_balance)
{
	int messageId = rand() % 3 + 1;

	if (messageId == 1)
	{
		printf("You are on a roll! You rolled %d times!\n", number_rolls);
	}
	else if (messageId == 2)
	{
		if (win_loss_neither == -1)
		{
			printf("Keep rolling until yu get your point!\n");
		}
	}
	else
	{
		if (current_bank_balance > initial_bank_balance)
		{
			double money_made = current_bank_balance - initial_bank_balance;
			printf("You've made some money ($%.2f), keep going!\n", money_made);
		}
		else if (current_bank_balance < initial_bank_balance)
		{
			printf("You're losing money, but I can feel you'll be lucky soon!\n");
		}
		else
		{
			printf("You've broke even, roll again and win some money!\n");
		}
	}
}