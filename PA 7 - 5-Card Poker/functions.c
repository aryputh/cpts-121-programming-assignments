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

/*
*	Description: Prints the game menu.
*	Date: 11/12/2023
*
*	Preconditions: None.
*	Postconditions: The game menu is printed out.
*/
void printMenu()
{
	printf("=== Poker (5-card Draw) ===\n");
	printf("1. View game rules.\n");
	printf("2. Play the game.\n");
	printf("3. Quit the program.\n");
}

/*
*	Description: Prints the game rules.
*	Date: 11/22/2023
*
*	Preconditions: None.
*	Postconditions: The game rules are printed out.
*/
void printRules()
{
	printf("=== Poker (5-card Draw) ===\n");
	printf("1. Each player is dealt 5 cards.\n");
	printf("2. Look for special cards (pair, 2 pairs, 3 a kind, 4 a kind, full house, flush, or straight).\n");
	printf("3. You can replace upto 3 cards total.\n");
	printf("4. Try and beat the dealer by getting a better special card group (straight is most points, pair is least).\n\n");
}

/*
*	Description: Prints the hand of someone.
*	Date: 11/22/2023
*
*	Preconditions: None.
*	Postconditions: The cards in the hand are printed out.
*/
void printHand(Hand hand, char *suits[4], char *faces[13])
{
	// Print all 5 cards in the hand
	for (int i = 0; i < 5; i++)
	{
		printf("%d) %5s of %-8s\n", i + 1, faces[hand.currentHand[i].indexFaceValue], suits[hand.currentHand[i].indexSuitValue]);
	}
}

/*
*	Description: Fills the deck with cards in order
*	Date: 11/22/2023
*
*	Preconditions: A valid deck of cards is provided.
*	Postconditions: The deck is fully populated.
*/
void populateHand(Hand *hand)
{
	// Loops through each suit of the deck
	for (int card = 0; card < 5; card++)
	{
		// Fill card slot with default suit and face
		(*hand).currentHand[card].indexFaceValue = -1;
		(*hand).currentHand[card].indexSuitValue = -1;
	}
}

/*
*	Description: Fills the deck with cards in order
*	Date: 11/22/2023
*
*	Preconditions: A valid deck of cards is provided.
*	Postconditions: The deck is fully populated.
*/
void populateDeck(Card deckOfCards[][13])
{
	// Loops through each suit of the deck
	for (int suit = 0; suit < 4; suit++)
	{
		// Loops through each face of the deck
		for (int face = 0; face < 13; face++)
		{
			// Fill card slot with appropriate suit and face
			deckOfCards[suit][face] = (Card){ face, suit };
		}
	}
}

/*
*	Description: Shuffles cards in the deck.
*	Date: 11/22/2023
*
*	Preconditions: A valid deck is provided.
*	Postconditions: Cards are shuffled.
*/
void shuffleDeck(Card deckOfCards[][13])
{
	// Declare required variables
	int randRow = -1, randColumn = -1;
	Card tempCard = deckOfCards[0][0];

	// For all cards, randomly swap with another card
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 12; column++)
		{
			randRow = rand() % 4;
			randColumn = rand() % 13;

			tempCard = deckOfCards[row][column];
			deckOfCards[row][column] = deckOfCards[randRow][randColumn];
			deckOfCards[randRow][randColumn] = tempCard;
		}
	}
}

/*
*	Description: Deals cards in a deck.
*	Date: 11/22/2023
*
*	Preconditions: A valid deck of cards, and player hand are provided.
*	Postconditions: A card is dealed from a deck.
*/
void dealCards(Card deckOfCards[][13], int *nextCardIndex, Hand *hand)
{
	// Declare required variables
	int numCardsDealt = 0;

	// Check all cards in hand
	for (int card = 0; card <= 5; card++)
	{
		// Replace empty card with the next card in deck
		if ((*hand).currentHand[card].indexFaceValue == -1 && (*hand).currentHand[card].indexSuitValue == -1)
		{
			(*hand).currentHand[card] = deckOfCards[(*nextCardIndex + numCardsDealt) / 13][(*nextCardIndex + numCardsDealt) % 13];
			numCardsDealt++;
		}
	}

	//Update nextCardIndex if cards dealt isn't 0
	if (numCardsDealt > 0)
	{
		*nextCardIndex += numCardsDealt;
	}
}

/*
*	Description: Populates a frequency table based on suits.
*	Date: 11/17/2023
*
*	Preconditions: A valid deck is provided.
*	Postconditions: Frequency table is filled.
*/
void populateSuitFreq(Hand hand, int freqArray[4])
{
	// Read all 5 cards
	for (int i = 0; i < 5; i++)
	{
		// Keep choosing slot until empty one is found
		freqArray[hand.currentHand[i].indexSuitValue]++;
	}
}

/*
*	Description: Populates a frequency table based on values.
*	Date: 11/17/2023
*
*	Preconditions: A valid deck is provided.
*	Postconditions: Frequency table is filled.
*/
void populateValueFreq(Hand hand, int freqArray[4])
{
	// Read all 5 cards
	for (int i = 0; i < 5; i++)
	{
		// Keep choosing slot until empty one is found
		freqArray[hand.currentHand[i].indexFaceValue]++;
	}
}

/*
*	Description: Determines any special card values and returns number based on
*		special case (0 = pair, 1 = 2 pair, 2 = 3 a kind, 3 = 4 a kind, 4 = full house, 5 = flush, 6 = straight).
*		Returns -1 if no special cases are found.
*	Date: 11/22/2023
*
*	Preconditions: A valid hand is provided.
*	Postconditions: The correct status code is returned.
*/
int determineSpecialCards(Hand hand, int freqTableSuits[4], int freqTableFaces[13])
{
	// Check for a straight (5 consecutive faced cards)
	if (findLongestConsecutiveValues(freqTableFaces) == 5)
	{
		return 6;
	}

	// Check for a flush (5 cards of same suit)
	if (freqTableSuits[0] == 5 || freqTableSuits[1] == 5 || freqTableSuits[2] == 5 || freqTableSuits[3] == 5)
	{
		return 5;
	}

	// Check for a full house (3 a kind and a pair)
	if (freqTableFaces[0] == 3 || freqTableFaces[1] == 3 || freqTableFaces[2] == 3 || freqTableFaces[3] == 3 ||
		freqTableFaces[4] == 3 || freqTableFaces[5] == 3 || freqTableFaces[6] == 3 || freqTableFaces[7] == 3 ||
		freqTableFaces[8] == 3 || freqTableFaces[9] == 3 || freqTableFaces[10] == 3 || freqTableFaces[11] == 3 ||
		freqTableFaces[12] == 3)
	{
		if (freqTableFaces[0] == 2 || freqTableFaces[1] == 2 || freqTableFaces[2] == 2 || freqTableFaces[3] == 2 ||
			freqTableFaces[4] == 2 || freqTableFaces[5] == 2 || freqTableFaces[6] == 2 || freqTableFaces[7] == 2 ||
			freqTableFaces[8] == 2 || freqTableFaces[9] == 2 || freqTableFaces[10] == 2 || freqTableFaces[11] == 2 ||
			freqTableFaces[12] == 2)
		{
			return 4;
		}
	}

	// Check for 4 a kind (4 a kind)
	if (freqTableFaces[0] == 4 || freqTableFaces[1] == 4 || freqTableFaces[2] == 4 || freqTableFaces[3] == 4 ||
		freqTableFaces[4] == 4 || freqTableFaces[5] == 4 || freqTableFaces[6] == 4 || freqTableFaces[7] == 4 ||
		freqTableFaces[8] == 4 || freqTableFaces[9] == 4 || freqTableFaces[10] == 4 || freqTableFaces[11] == 4 ||
		freqTableFaces[12] == 4)
	{
		return 3;
	}

	// Check for 3 a kind (3 a kind)
	if (freqTableFaces[0] == 3 || freqTableFaces[1] == 3 || freqTableFaces[2] == 3 || freqTableFaces[3] == 3 ||
		freqTableFaces[4] == 3 || freqTableFaces[5] == 3 || freqTableFaces[6] == 3 || freqTableFaces[7] == 3 ||
		freqTableFaces[8] == 3 || freqTableFaces[9] == 3 || freqTableFaces[10] == 3 || freqTableFaces[11] == 3 ||
		freqTableFaces[12] == 3)
	{
		return 2;
	}

	// Check for 2 pair (2 pairs)
	if (freqTableFaces[0] == 2 || freqTableFaces[1] == 2 || freqTableFaces[2] == 2 || freqTableFaces[3] == 2 ||
		freqTableFaces[4] == 2 || freqTableFaces[5] == 2 || freqTableFaces[6] == 2)
	{
		if (freqTableFaces[7] == 2 || freqTableFaces[8] == 2 || freqTableFaces[9] == 2 || freqTableFaces[10] == 2 ||
			freqTableFaces[11] == 2 || freqTableFaces[12] == 2)
		{
			return 1;
		}
	}

	// Check for a pair (2 a kind)
	if (freqTableFaces[0] == 2 || freqTableFaces[1] == 2 || freqTableFaces[2] == 2 || freqTableFaces[3] == 2 ||
		freqTableFaces[4] == 2 || freqTableFaces[5] == 2 || freqTableFaces[6] == 2 || freqTableFaces[7] == 2 ||
		freqTableFaces[8] == 2 || freqTableFaces[9] == 2 || freqTableFaces[10] == 2 || freqTableFaces[11] == 2 ||
		freqTableFaces[12] == 2)
	{
		return 0;
	}

	// If no special cards apply, return -1
	return -1;
}

/*
*	Description: Returns the largest number of consecutive faces.
*	Date: 11/22/2023
*
*	Preconditions: A valid frequency table is provided.
*	Postconditions: The correct number of consecutive faces is returned.
*/
int findLongestConsecutiveValues(int freqTableFaces[13])
{
	// Declare required variables
	int currentStreak = 0, maxStreak = 0;

	// Check all numbers in the frequency array
	for (int i = 0; i < 12; i++)
	{
		if (freqTableFaces[i] == 1)
		{
			currentStreak++;

			if (currentStreak > maxStreak)
			{
				maxStreak = currentStreak;
			}
		}
		else
		{
			currentStreak = 0;
		}
	}

	// Return the max streak
	return maxStreak;
}

/*
*	Description: Use basic logic to increase chances of dealer winning.
*	Date: 11/24/2023
*
*	Preconditions: A valid dealer hand, suit frequency table, and face frequency table are provided.
*	Postconditions: The dealer's hand had a chance to get better.
*/
void dealerHandEvaluate(Hand* dealerHand, int dealerFreqTableSuits[4], int dealerFreqTableFaces[13])
{
	// Check for 4 a kind and replace a card to try for straight (5 a kind)
	if (dealerFreqTableFaces[0] == 4 || dealerFreqTableFaces[1] == 4 || dealerFreqTableFaces[2] == 4 || dealerFreqTableFaces[3] == 4 ||
		dealerFreqTableFaces[4] == 4 || dealerFreqTableFaces[5] == 4 || dealerFreqTableFaces[6] == 4 || dealerFreqTableFaces[7] == 4 ||
		dealerFreqTableFaces[8] == 4 || dealerFreqTableFaces[9] == 4 || dealerFreqTableFaces[10] == 4 || dealerFreqTableFaces[11] == 4 ||
		dealerFreqTableFaces[12] == 4)
	{
		if (dealerFreqTableFaces[0] == 1)
		{
			// Discard chosen card
			(*dealerHand).currentHand[0].indexFaceValue = -1;
			(*dealerHand).currentHand[0].indexSuitValue = -1;
		}
		else if (dealerFreqTableFaces[1] == 1)
		{
			// Discard chosen card
			(*dealerHand).currentHand[1].indexFaceValue = -1;
			(*dealerHand).currentHand[1].indexSuitValue = -1;
		}
		else if (dealerFreqTableFaces[2] == 1)
		{
			// Discard chosen card
			(*dealerHand).currentHand[2].indexFaceValue = -1;
			(*dealerHand).currentHand[2].indexSuitValue = -1;
		}
		else if (dealerFreqTableFaces[3] == 1)
		{
			// Discard chosen card
			(*dealerHand).currentHand[3].indexFaceValue = -1;
			(*dealerHand).currentHand[3].indexSuitValue = -1;
		}
		else if (dealerFreqTableFaces[4] == 1)
		{
			// Discard chosen card
			(*dealerHand).currentHand[4].indexFaceValue = -1;
			(*dealerHand).currentHand[4].indexSuitValue = -1;
		}
	}

	// Check for 3 a kind and replace a card to try for 4 a kind
	if (dealerFreqTableFaces[0] == 3 || dealerFreqTableFaces[1] == 3 || dealerFreqTableFaces[2] == 3 || dealerFreqTableFaces[3] == 3 ||
		dealerFreqTableFaces[4] == 3 || dealerFreqTableFaces[5] == 3 || dealerFreqTableFaces[6] == 3 || dealerFreqTableFaces[7] == 3 ||
		dealerFreqTableFaces[8] == 3 || dealerFreqTableFaces[9] == 3 || dealerFreqTableFaces[10] == 3 || dealerFreqTableFaces[11] == 3 ||
		dealerFreqTableFaces[12] == 3)
	{
		if (dealerFreqTableFaces[0] == 1)
		{
			// Discard chosen card
			(*dealerHand).currentHand[0].indexFaceValue = -1;
			(*dealerHand).currentHand[0].indexSuitValue = -1;
		}
		else if (dealerFreqTableFaces[1] == 1)
		{
			// Discard chosen card
			(*dealerHand).currentHand[1].indexFaceValue = -1;
			(*dealerHand).currentHand[1].indexSuitValue = -1;
		}
		else if (dealerFreqTableFaces[2] == 1)
		{
			// Discard chosen card
			(*dealerHand).currentHand[2].indexFaceValue = -1;
			(*dealerHand).currentHand[2].indexSuitValue = -1;
		}
		else if (dealerFreqTableFaces[3] == 1)
		{
			// Discard chosen card
			(*dealerHand).currentHand[3].indexFaceValue = -1;
			(*dealerHand).currentHand[3].indexSuitValue = -1;
		}
		else if (dealerFreqTableFaces[4] == 1)
		{
			// Discard chosen card
			(*dealerHand).currentHand[4].indexFaceValue = -1;
			(*dealerHand).currentHand[4].indexSuitValue = -1;
		}
	}

	// Check for pair and replace a card to try for 3 a kind
	if (dealerFreqTableFaces[0] == 2 || dealerFreqTableFaces[1] == 2 || dealerFreqTableFaces[2] == 2 || dealerFreqTableFaces[3] == 2 ||
		dealerFreqTableFaces[4] == 2 || dealerFreqTableFaces[5] == 2 || dealerFreqTableFaces[6] == 2 || dealerFreqTableFaces[7] == 2 ||
		dealerFreqTableFaces[8] == 2 || dealerFreqTableFaces[9] == 2 || dealerFreqTableFaces[10] == 2 || dealerFreqTableFaces[11] == 2 ||
		dealerFreqTableFaces[12] == 2)
	{
		if (dealerFreqTableFaces[0] == 1)
		{
			// Discard chosen card
			(*dealerHand).currentHand[0].indexFaceValue = -1;
			(*dealerHand).currentHand[0].indexSuitValue = -1;
		}
		else if (dealerFreqTableFaces[1] == 1)
		{
			// Discard chosen card
			(*dealerHand).currentHand[1].indexFaceValue = -1;
			(*dealerHand).currentHand[1].indexSuitValue = -1;
		}
		else if (dealerFreqTableFaces[2] == 1)
		{
			// Discard chosen card
			(*dealerHand).currentHand[2].indexFaceValue = -1;
			(*dealerHand).currentHand[2].indexSuitValue = -1;
		}
		else if (dealerFreqTableFaces[3] == 1)
		{
			// Discard chosen card
			(*dealerHand).currentHand[3].indexFaceValue = -1;
			(*dealerHand).currentHand[3].indexSuitValue = -1;
		}
		else if (dealerFreqTableFaces[4] == 1)
		{
			// Discard chosen card
			(*dealerHand).currentHand[4].indexFaceValue = -1;
			(*dealerHand).currentHand[4].indexSuitValue = -1;
		}
	}
}