/*
*	Name: Aryan Puthran
*	Date: 10/26/2023
*	Course: CPT_S 121
*	Assignment: Programming Assignment 6
*
*	Description: This program will play a game of battleship. There will be a
*		player and a computer. Each will take turns until all ships have sunk
*		for either side. There will be conditionals, 2D arrays, functions, etc.
*		This file will include all the main logic to running the game.
*/

#include "functions.h"

int main()
{
	// Declare required variables
	PlayerStat player1Stats = { 0, 0, 0, 0.0, 0 }, player2Stats = { 0, 0, 0, 0.0, 0 };
	char player1Board[ROWS_COLS][ROWS_COLS] = { 0 }, player2Board[ROWS_COLS][ROWS_COLS] = { 0 };
	FILE *output = fopen("battleship.log", "w");
	int isGameOver = 0, placementSetting = -1, currentPlayer = -1, selectedX = -1, selectedY = -1, winner = -1;
	char lastHitShip = '\0';

	// Allows for a random numbers to be used
	srand((unsigned int)time(NULL));

	// Print welcome screen and intialize boards
	DisplayWelcomeScreen();
	InitializeGameBoard(player1Board);
	InitializeGameBoard(player2Board);

	// Prompt user to hit any key to move on and clear screen
	system("Pause");
	system("cls");

	// Print placement settings menu
	DisplayPlacementMenu();

	// Read and validate input
	do
	{
		scanf("%d", &placementSetting);
	}
	while (!(placementSetting == 1 || placementSetting == 2));

	// Implement placement based on chosen setting
	if (placementSetting == 1)
	{
		// Manual placement
		ManuallyPlaceShipsOnBoard(player1Board, 5, 'c');
		ManuallyPlaceShipsOnBoard(player1Board, 4, 'b');
		ManuallyPlaceShipsOnBoard(player1Board, 3, 'r');
		ManuallyPlaceShipsOnBoard(player1Board, 3, 's');
		ManuallyPlaceShipsOnBoard(player1Board, 2, 'd');
		printf("Your board is ready to go!\n");
	}
	else
	{
		// Automatic placement for player 1
		RandomlyPlaceShipsOnBoard(player1Board, 5, 'c');
		RandomlyPlaceShipsOnBoard(player1Board, 4, 'b');
		RandomlyPlaceShipsOnBoard(player1Board, 3, 'r');
		RandomlyPlaceShipsOnBoard(player1Board, 3, 's');
		RandomlyPlaceShipsOnBoard(player1Board, 2, 'd');
		printf("Your board has been generated!\n");
	}

	// Automatic placement for player 2 and let player 1 know
	RandomlyPlaceShipsOnBoard(player2Board, 5, 'c');
	RandomlyPlaceShipsOnBoard(player2Board, 4, 'b');
	RandomlyPlaceShipsOnBoard(player2Board, 3, 'r');
	RandomlyPlaceShipsOnBoard(player2Board, 3, 's');
	RandomlyPlaceShipsOnBoard(player2Board, 2, 'd');
	printf("Player 2's board has been generated!\n");

	// Determine random starting player and print
	currentPlayer = DecideStartingPlayer();
	printf("Player %d has been randomly chose to start!\n", currentPlayer);

	while (isGameOver != 1)
	{
		// Prompt user to hit any key to move on and clear screen
		system("Pause");
		system("cls");

		// Print out both boards
		DisplayBoard(player1Board, 1);
		DisplayBoard(player2Board, 2);

		// Play the game according to current player
		if (currentPlayer == 1)
		{
			// Prompt for coordinates
			printf("Enter target coordinates (x y):\n");

			// Read and validate input
			do
			{
				scanf("%d", &selectedX);
				scanf("%d", &selectedY);
			}
			while (!(selectedX < 0 || selectedX > ROWS_COLS - 1) && !(selectedY < 0 || selectedY > ROWS_COLS - 1) &&
				CheckShotDoneAlready(player2Board, selectedX, selectedY) == 1);

			// Clear the screen
			system("cls");

			// Update the board
			UpdateBoard(player2Board, selectedX, selectedY, &lastHitShip);

			// Check if coords are a hit or miss and print result
			if (CheckShotCoordinates(player2Board, selectedX, selectedY) == 0)
			{
				printf("(%d %d) is a miss!\n", selectedX, selectedY);
			}
			else
			{
				printf("(%d %d) is a hit!\n", selectedX, selectedY);
			}

			// Notify user if a ship sunk
			if (CheckShipSunkStatus(player2Board, lastHitShip) == 1)
			{
				switch (lastHitShip)
				{
					case 'c':
						printf("You sunk a carrier!\n");
						break;
					case 'b':
						printf("You sunk a battleship!\n");
						break;
					case 'r':
						printf("You sunk a cruiser!\n");
						break;
					case 's':
						printf("You sunk a submarine!\n");
						break;
					case 'd':
						printf("You sunk a destroyer!\n");
						break;
					default:
						break;
				}
			}

			// Print out move into log file
			LogCurrentMove(selectedX, selectedX, CheckShotCoordinates(player2Board, selectedX, selectedX),
				CheckShipSunkStatus(player2Board, lastHitShip), output);

			// Reset variables
			currentPlayer = 2;
			selectedX = -1;
			selectedY = -1;

			// Check if there is a winner to break out of loop
			if (IsWinner(player2Board) == 1)
			{
				isGameOver = 1;
				winner = 1;
			}
			else if (IsWinner(player1Board) == 1)
			{
				isGameOver = 1;
				winner = 2;
			}
		}
		else
		{
			// Select random, unchosen coordinates
			do
			{
				selectedX = ChooseRandomCoordinate();
				selectedY = ChooseRandomCoordinate();
			}
			while (CheckShotDoneAlready(player1Board, selectedX, selectedY) == 1);

			// Print out results of random coordinates
			printf("Player 2 chose (%d %d)!\n", selectedX, selectedY);

			// Update the board
			UpdateBoard(player1Board, selectedX, selectedY, &lastHitShip);

			// Check if coords are a hit or miss and print result
			if (CheckShotCoordinates(player1Board, selectedX, selectedY) == 0)
			{
				printf("(%d %d) is a miss!\n", selectedX, selectedY);
			}
			else
			{
				printf("(%d %d) is a hit!\n", selectedX, selectedY);
			}

			// Notify user if a ship sunk
			if (CheckShipSunkStatus(player2Board, lastHitShip) == 1)
			{
				switch (lastHitShip)
				{
					case 'c':
						printf("The computer sunk a carrier!\n");
						break;
					case 'b':
						printf("The computer sunk a battleship!\n");
						break;
					case 'r':
						printf("The computer sunk a cruiser!\n");
						break;
					case 's':
						printf("The computer sunk a submarine!\n");
						break;
					case 'd':
						printf("The computer sunk a destroyer!\n");
						break;
					default:
						break;
				}
			}

			// Print out move into log file
			LogCurrentMove(selectedX, selectedX, CheckShotCoordinates(player1Board, selectedX, selectedX),
				CheckShipSunkStatus(player1Board, lastHitShip), output);

			// Reset variables
			currentPlayer = 1;
			selectedX = -1;
			selectedY = -1;

			// Check if there is a winner to break out of loop
			if (IsWinner(player1Board) == 1)
			{
				isGameOver = 1;
				winner = 2;
			}
			else if (IsWinner(player2Board) == 1)
			{
				isGameOver = 1;
				winner = 1;
			}
		}
	}

	// Print out structs into log file
	LogPlayerStatistics(player1Stats, output);
	LogPlayerStatistics(player2Stats, output);

	// Clear the screen
	system("cls");

	// Print winner and goodbye message
	printf("=== Battleship ===\n\n");
	printf("Player %d won!\n", winner);
	printf("Thanks for playing!\n");

	return 0;
}