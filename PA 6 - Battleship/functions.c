/*
*	Name: Aryan Puthran
*	Date: 10/26/2023
*	Course: CPT_S 121
*	Assignment: Programming Assignment 6
*
*	Description: This program will play a game of battleship. There will be a
*		player and a computer. Each will take turns until all ships have sunk
*		for either side. There will be conditionals, 2D arrays, functions, etc.
*		This file will contain all the functions required in the game.
*/

#include "functions.h"

/*
*	Description: Displays a welcome message and the rules of the game.
*	Date: 10/26/2023
*
*	Preconditions: None.
*	Postconditions: The welcome screen is printed to the screen.
*/
void DisplayWelcomeScreen()
{
	printf("=== Battleship ===\n\n");
	printf("Rules:\n");
	printf("1. You are Player 1, the computer is Player 2.\n");
	printf("2. Both players place their ships without revealing their locations.\n");
	printf("3. Ships cannot stack or go off the board.\n");
	printf("4. A random person starts the game, trying to guess coordinates to hit.\n");
	printf("5. Hit ships are noted by '#' while missed ships are noted be 'x'.\n");
	printf("6. You must try and sink your opponent's ships.\n");
	printf("7. The first to sink their opponent's ships wins the game.\n\n");
}

/*
*	Description: Displays a menu for ship placements.
*	Date: 10/26/2023
*
*	Preconditions: None.
*	Postconditions: The menu is printed to the screen.
*/
void DisplayPlacementMenu()
{
	printf("=== Battleship ===\n\n");
	printf("Placement:\n");
	printf("1. Enter positions manually.\n");
	printf("2. Enter positions automatically.\n");
}

/*
*	Description: Sets each cell in a game board to hyphens.
*	Date: 10/26/2023
*
*	Preconditions: board is a valid 2D array, and has a length and width of
*		ROWS_COLS.
*	Postconditions: board is full of tildes.
*/
void InitializeGameBoard(char board[][ROWS_COLS])
{
	// Traverse every element
	for (int i = 0; i < ROWS_COLS; i++)
	{
		for (int j = 0; j < ROWS_COLS; j++)
		{
			// Set element to a hyphen
			board[i][j] = '~';
		}
	}
}

/*
*	Description: Randomly selects who plays the first round.
*	Date: 10/26/2023
*
*	Preconditions: None.
*	Postconditions: A random player number [1, 2] is returned.
*/
int DecideStartingPlayer()
{
	// Generate a random number between 1 and 2
	return rand() % 2 + 1;
}

/*
*	Description: Randomly selects a coordinate.
*	Date: 10/26/2023
*
*	Preconditions: None.
*	Postconditions: A random coord number [0, 9] is returned.
*/
int ChooseRandomCoordinate()
{
	// Generate a random number between 0 and 9
	return rand() % (ROWS_COLS - 1);
}

/*
*	Description: Allows the user to place their 5 ships on their board in this order:
*		Carrier, Battleship, Cruiser, Submarine, than Destroyer.
*	Date: 11/2/2023
*
*	Preconditions: board is initialized and has a size of ROWS_COLS.
*	Postconditions: board is filled with all 5 ships.
*/
void ManuallyPlaceShipsOnBoard(char board[][ROWS_COLS], int shipLength, char shipLetter)
{
	int direction = 0, areValidPositions = -1, startingCoordX = -1, startingCoordY = -1;
	int xCoords[5] = { 0 };
	int yCoords[5] = { 0 };

	// Prompt user to decide a direction
	printf("\nChoose the direction to place your ship on (0 = Down, 1 = Right):\n");
	do
	{
		scanf("%d", &direction);
	}
	while (!(direction == 0 || direction == 1));

	// Validated and get coordinates
	do
	{
		// Prompt the user
		printf("\nChoose %d coordinates to place your ship on (x y):\n", shipLength);
		
		// Scan numbers for ship positions
		for (int k = 0; k < shipLength; k++)
		{
			scanf("%d%d", &xCoords[k], &yCoords[k]);
		}

		// Set first selected coords
		startingCoordX = yCoords[0];
		startingCoordY = xCoords[0];

		areValidPositions = CheckManualPlacementShip(board, shipLength, direction, xCoords, yCoords);
	}
	while (areValidPositions != 1);
	
	// Place ships once positions are checked
	for (int i = 0; i < shipLength; i++)
	{
		if (direction == 0)
		{
			board[startingCoordX + i][startingCoordY] = shipLetter;
		}
		else
		{
			board[startingCoordX][startingCoordY + i] = shipLetter;
		}
	}

	DisplayBoard(board, 1);
}

/*
*	Description: Randomly places 5 ships on a game board.
*	Date: 10/30/2023
*
*	Preconditions: board is initialized and has a size of ROWS_COLS.
*	Postconditions: board is randomly filled with all 5 ships.
*/
void RandomlyPlaceShipsOnBoard(char board[][ROWS_COLS], int shipLength, char shipLetter)
{
	int direction = 0, startingCoordX = -1, startingCoordY = -1, isValidPosition = -1;

	// Choose a random direction, 0 is down, 1 is right
	direction = rand() % 2;

	// Choose random coords and check if it's valid.
	if (direction == 0)
	{
		do
		{
			startingCoordX = ChooseRandomCoordinate();
			startingCoordY = ChooseRandomCoordinate() - shipLength + 1;
			isValidPosition = CheckRandomPlacementShip(board, shipLength, direction, startingCoordX, startingCoordY);
		}
		while (startingCoordY < 0 || isValidPosition != 1);
	}
	else
	{
		do
		{
			startingCoordX = ChooseRandomCoordinate() - shipLength + 1;
			startingCoordY = ChooseRandomCoordinate();
			isValidPosition = CheckRandomPlacementShip(board, shipLength, direction, startingCoordX, startingCoordY);
		}
		while (startingCoordX < 0 || isValidPosition != 1);
	}

	// Place ships once positions are checked
	for (int i = 0; i < shipLength; i++)
	{
		if (direction == 0)
		{
			board[startingCoordX][startingCoordY + i] = shipLetter;
		}
		else
		{
			board[startingCoordX + i][startingCoordY] = shipLetter;
		}
	}
}

/*
*	Description: Checks placement of random ship positions.
*	Date: 10/30/2023
*
*	Preconditions: board is initialized and has a size of ROWS_COLS.
*	Postconditions: Returns 1 if position is valid and 0 otherwise.
*/
int CheckRandomPlacementShip(char board[][ROWS_COLS], int shipLength, int direction, int x, int y)
{
	int result = 1;

	// Check that pieces don't overlap 
	for (int i = 0; i < shipLength; i++)
	{
		if (direction == 0)
		{
			if (board[x][y + i] != '~')
			{
				result = 0;
			}
		}
		else
		{
			if (board[x + i][y] != '~')
			{
				result = 0;
			}
		}
	}

	return result;
}

/*
*	Description: Checks position of manually placed ships.
*	Date: 11/2/2023
*
*	Preconditions: board is initialized and has a size of ROWS_COLS.
*	Postconditions: Returns 1 if position is valid and 0 otherwise.
*/
int CheckManualPlacementShip(char board[][ROWS_COLS], int shipLength, int direction, int xCoords[], int yCoords[])
{
	int result = 1, consecutiveCoords = 0, maxConsecutiveCoords = 0;
	int coordXInv[ROWS_COLS] = { 0 }, coordYInv[ROWS_COLS] = { 0 };

	// Check for negative/already chosen coords
	for (int i = 0; i < shipLength; i++)
	{
		// Check for valid x coords
		if (xCoords[i] < 0 || xCoords[i] > ROWS_COLS - 1)
		{
			return 0;
		}

		// Check for valid y coords
		if (yCoords[i] < 0 || yCoords[i] > ROWS_COLS - 1)
		{
			return 0;
		}

		// Check for unused coords
		if (board[xCoords[i]][yCoords[i]] != '~')
		{
			return 0;
		}
	}

	// Populate the frequency tables
	for (int i = 0; i < shipLength; i++)
	{
		coordXInv[xCoords[i]]++;
		coordYInv[yCoords[i]]++;
	}

	// Check number of x or y coords to make sure they match
	if (direction == 0)
	{
		if (coordXInv[0] == shipLength || coordXInv[1] == shipLength || coordXInv[2] == shipLength || coordXInv[3] == shipLength ||
			coordXInv[4] == shipLength || coordXInv[5] == shipLength || coordXInv[6] == shipLength || coordXInv[7] == shipLength ||
			coordXInv[8] == shipLength || coordXInv[9] == shipLength)
		{
			// Find greatest number of sequential items
			for (int i = 0; i < ROWS_COLS; i++)
			{
				if (coordYInv[i] == 1)
				{
					consecutiveCoords++;
				}

				if (consecutiveCoords > maxConsecutiveCoords)
				{
					maxConsecutiveCoords = consecutiveCoords;
				}
			}
		}
	}
	else
	{
		if (coordYInv[0] == shipLength || coordYInv[1] == shipLength || coordYInv[2] == shipLength || coordYInv[3] == shipLength ||
			coordYInv[4] == shipLength || coordYInv[5] == shipLength || coordYInv[6] == shipLength || coordYInv[7] == shipLength ||
			coordYInv[8] == shipLength || coordYInv[9] == shipLength)
		{
			// Find greatest number of sequential items
			for (int i = 0; i < ROWS_COLS; i++)
			{
				if (coordXInv[i] == 1)
				{
					consecutiveCoords++;
				}

				if (consecutiveCoords > maxConsecutiveCoords)
				{
					maxConsecutiveCoords = consecutiveCoords;
				}
			}
		}
	}

	// Check coords to make sure they are sequential
	if (maxConsecutiveCoords != shipLength)
	{
		result = 0;
	}

	return result;
}

/*
*	Description: Determines if a winner exists, and who it is.
*	Date:
*
*	Preconditions: board is initialized with size of ROWS_COLS.
*	Postconditions: 0 is printed if tie/no winners, 1 if player 1 wins, and
*		2 if player 2 wins.
*/
int IsWinner(char board[][ROWS_COLS])
{
	int isWinner = 1;

	// Traverses every element
	for (int i = 0; i < ROWS_COLS; i++)
	{
		for (int j = 0; j < ROWS_COLS; j++)
		{
			// Checks if the board contains unsunk ships
			if (board[i][j] == 'c' || board[i][j] == 'b' || board[i][j] == 'r' || board[i][j] == 's' || board[i][j] == 'd')
			{
				isWinner = 0;
			}
		}
	}

	return isWinner;
}

/*
*	Description: Checks if a shot was already done.
*	Date: 10/26/2023
*
*	Preconditions: board is initialized with size of ROWS_COLS.
*	Postconditions: Returns 1 is corrd has been targeted, 0 otherwise.
*/
int CheckShotDoneAlready(char board[][ROWS_COLS], int x, int y)
{
	if (board[y][x] == '#' || board[y][x] == 'x')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
*	Description: Updates the board every time a shot is taken.
*		A x means a hit and # means a miss.
*	Date: 10/26/2023
*
*	Preconditions: board is initialized with size of ROWS_COLS.
*	Postconditions: board is updated with the correct symbol.
*/
void UpdateBoard(char board[][ROWS_COLS], int x, int y, char *lastHitShip)
{
	if (board[y][x] == '~')
	{
		board[y][x] = 'x';
	}
	else
	{
		*lastHitShip = board[y][x];
		board[y][x] = '#';
	}
}

/*
*	Description: Checks if a shot was a hit or miss.
*	Date: 10/26/2023
*
*	Preconditions: board is initialized with size of ROWS_COLS.
*	Postconditions: Returns 0 if hit blank or missed element, 1 otherwise.
*/
int CheckShotCoordinates(char board[][ROWS_COLS], int x, int y)
{
	if (board[y][x] == 'x' || board[y][x] == '~')
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

/*
*	Description: Displays the game board depending on the player.
*	Date: 10/26/2023
*
*	Preconditions: board is intialized with a size of ROWS_COLS, and the correct
*		player is passed in.
*	Postconditions: The board is displayed correctly according to current player.
*/
void DisplayBoard(char board[][ROWS_COLS], int player)
{
	// Print title of board
	printf("\nPlayer %d's Board:\n", player);

	// Print a space before x coordinates
	printf(" ");

	// Print x coordinates
	for (int k = 0; k < ROWS_COLS; k++)
	{
		// Print each index
		printf(" %d", k);
	}

	// Print a new line
	printf("\n");

	// Print differently depending on player
	if (player == 1)
	{
		// Traverse every element
		for (int i = 0; i < ROWS_COLS; i++)
		{
			// Print x coordinates
			printf("%d ", i);

			for (int j = 0; j < ROWS_COLS; j++)
			{
				// Print each element
				printf("%c ", board[i][j]);
			}

			// Print rows on new lines
			printf("\n");
		}
	}
	else
	{
		// Traverse every element
		for (int i = 0; i < ROWS_COLS; i++)
		{
			// Print x coordinates
			printf("%d ", i);

			for (int j = 0; j < ROWS_COLS; j++)
			{
				// Print only misses and hits
				if (board[i][j] == '#' || board[i][j] == 'x')
				{
					printf("%c ", board[i][j]);
				}
				else
				{
					printf("~ ");
				}
			}

			// Print rows on new lines
			printf("\n");
		}
	}

	// Prints a new line
	printf("\n");
}

/*
*	Description: Checks if a ship has been sunk or not. Returns 1 is yes, 0 if not.
*	Date: 10/26/2023
*
*	Preconditions: Arguments passed in are valid.
*	Postconditions: Returns 0 or 1, depending on the status of the ship.
*/
int CheckShipSunkStatus(char board[][ROWS_COLS], char shipLetter)
{
	// Traverses every element
	for (int i = 0; i < ROWS_COLS; i++)
	{
		for (int j = 0; j < ROWS_COLS; j++)
		{
			// Checks if the selected ship has sunk
			if (board[i][j] == shipLetter)
			{
				return 0;
			}
		}
	}

	return 1;
}

/*
*	Description: Writes the position of the shot taken by the current player to the log.
*		Writes whether or not coordinates were a hit, miss, and if the ship was sunk.
*	Date: 10/26/2023
*
*	Preconditions: Actual arguments provided are valid and initialized.
*	Postconditions: Something is outputted to the file containing accurate stats.
*/
void LogCurrentMove(int x, int y, int checkShotCoordinates, int checkShipSunkStatus, FILE* output)
{
	fprintf(output, "Coordinates: %d %d\n", x, y);
	fprintf(output, "Hit (1) or Miss (0): %d\n", checkShotCoordinates);
	fprintf(output, "Ship Sunk? (1 = Yes) %d\n\n", checkShipSunkStatus);
}

/*
*	Description: Writes the stats on each player to the log.
*	Date: 10/26/2023
*
*	Preconditions: A valid struct is provided
*	Postconditions: Something is outputted to the file.
*/
void LogPlayerStatistics(PlayerStat player, FILE *output)
{
	fprintf(output, "Hits: %d\n", player.hits);
	fprintf(output, "Misses: %d\n", player.misses);
	fprintf(output, "Shots: %d\n", player.shots);
	fprintf(output, "Hit to Miss Ratio: %.2f\n", player.hitToMissRatio);
	fprintf(output, "Is the winner? (1 = Yes) %d\n\n", player.isWinner);
}