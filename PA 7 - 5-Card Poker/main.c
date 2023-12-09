/*
*	Name: Aryan Puthran
*	Date: 11/9/2023
*	Course: CPT_S 121
*	Assignment: Programming Assignment 7
*
*	Description: This program will play a game of 5-card poker. Authors: Deitel & Deitel - C How to Program
*/

// Include header file
#include "functions.h"

int main(void)
{
	// Declare required variables
	const char* suits[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	const char* faces[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
		"Jack", "Queen", "King" };
	int playerFreqTableSuits[4] = { 0 }, playerFreqTableFaces[13] = { 0 }, dealerFreqTableSuits[4] = { 0 }, dealerFreqTableFaces[13] = { 0 };
	int menuChoice = 0, nextCardIndex = 0, playerScore = 0, dealerScore = 0, numCardsReplace = 0, cardToReplace = 0;
	Card deck[4][13] = { 0 };
	Hand playerHand = { 0 }, dealerHand = { 0 };

	// Generate random numbers
	srand((unsigned)time(NULL));

	while (menuChoice != 3)
	{
		// Prompt user for menu option and validate
		do
		{
			printMenu();
			scanf("%d", &menuChoice);
		}
		while (!(menuChoice == 1 || menuChoice == 2 || menuChoice == 3));

		// Decide what to do based on menu choice
		if (menuChoice == 1)
		{
			// Clear the console and print out the game rules
			system("cls");
			printRules();
		}
		else if (menuChoice == 2)
		{
			// Reset declared variables
			menuChoice = 0;
			nextCardIndex = 0;
			playerScore = 0;
			dealerScore = 0;
			numCardsReplace = 0;
			cardToReplace = 0;

			// Populate hands
			populateHand(&playerHand);
			populateHand(&dealerHand);

			// Populate deck of cards and shuffle them
			populateDeck(deck);
			shuffleDeck(deck);

			// Give player and dealer 5 cards to start
			dealCards(deck, &nextCardIndex, &playerHand);
			dealCards(deck, &nextCardIndex, &dealerHand);

			// Fill frequency tables for dealer
			populateSuitFreq(dealerHand, dealerFreqTableSuits);
			populateValueFreq(dealerHand, dealerFreqTableFaces);

			// Check dealer's cards
			dealerHandEvaluate(&dealerHand, dealerFreqTableSuits, dealerFreqTableFaces);

			// Refill player's hand
			dealCards(deck, &nextCardIndex, &dealerHand);

			// Evaluate dealer's cards
			dealerScore = determineSpecialCards(dealerHand, dealerFreqTableSuits, dealerFreqTableFaces);

			// Notify player dealer chose their cards
			printf("\nThe dealer has finalized their cards!\n\n");

			// Display player's cards
			printHand(playerHand, suits, faces);

			// Ask player how many cards to replace and validate
			printf("\nHow many cards do you want to replace? (0 - 3)\n");

			do
			{
				scanf("%d", &numCardsReplace);
			}
			while (!(numCardsReplace >= 0 && numCardsReplace <= 3));

			// Ask player to choose cards to replace and validate
			for (int i = 0; i < numCardsReplace; i++)
			{
				printf("\nSelect a card to replace? (1 - 5)\n");

				do
				{
					scanf("%d", &cardToReplace);
				}
				while (!(cardToReplace >= 1 && cardToReplace <= 5));

				// Discard selected card
				playerHand.currentHand[cardToReplace - 1].indexFaceValue = -1;
				playerHand.currentHand[cardToReplace - 1].indexSuitValue = -1;
			}

			// Refill player's hand
			dealCards(deck, &nextCardIndex, &playerHand);

			// Refill frequency tables for player
			populateSuitFreq(playerHand, playerFreqTableSuits);
			populateValueFreq(playerHand, playerFreqTableFaces);

			// Evaluate player's cards
			playerScore = determineSpecialCards(playerHand, playerFreqTableSuits, playerFreqTableFaces);

			// Display player's cards
			printf("\n");
			printHand(playerHand, suits, faces);
			printf("\n");

			// Pause the game for player to read
			system("pause");

			// Clear the screen and print final details
			system("cls");
			printf("=== Poker (5-card Draw) ===\n");

			// Determine winner and display the winner
			if (playerScore > dealerScore)
			{
				printf("You won the game!\n\n");
			}
			else if (playerScore < dealerScore)
			{
				printf("The dealer won the game!\n\n");
			}
			else
			{
				printf("It's a tie!\n\n");
			}

			// Print special cards for player and dealer
			switch (playerScore)
			{
				case -1:
					printf("You didn't have any special cases.\n");
					break;
				case 0:
					printf("You had a pair.\n");
					break;
				case 1:
					printf("You had 2 pairs.\n");
					break;
				case 2:
					printf("You had 3 a kind.\n");
					break;
				case 3:
					printf("You had 4 a kind.\n");
					break;
				case 4:
					printf("You had a full house.\n");
					break;
				case 5:
					printf("You had a flush.\n");
					break;
				case 6:
					printf("You had a straight.\n");
					break;
				default:
					printf("Something went wrong (player).\n");
					break;
			}

			switch (dealerScore)
			{
				case -1:
					printf("The dealer didn't have any special cases.\n");
					break;
				case 0:
					printf("The dealer had a pair.\n");
					break;
				case 1:
					printf("The dealer had 2 pairs.\n");
					break;
				case 2:
					printf("The dealer had 3 a kind.\n");
					break;
				case 3:
					printf("The dealer had 4 a kind.\n");
					break;
				case 4:
					printf("The dealer had a full house.\n");
					break;
				case 5:
					printf("The dealer had a flush.\n");
					break;
				case 6:
					printf("The dealer had a straight.\n");
					break;
				default:
					printf("Something went wrong (dealer).\n");
					break;
			}
		}
		else
		{
			// Clear the console and print a goodbye message
			system("cls");
			printf("=== Poker (5-card Draw) ===\n");
			printf("Thanks for playing!\n");
		}
	}

	return 0;
}