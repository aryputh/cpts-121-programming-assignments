/*
*	Name: Aryan Puthran
*	Date: 10/26/2023
*	Course: CPT_S 121
*	Assignment: Programming Assignment 6
*
*	Description: This program will play a game of battleship. There will be a
*		player and a computer. Each will take turns until all ships have sunk
*		for either side. There will be conditionals, 2D arrays, functions, etc.
*		This file will store preprocessor directives, includes, and functions
		prototypes.
*/

// Ensures header file is included only once
#pragma once

// Preprocessor directives
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define ROWS_COLS 10

// Define structs
typedef struct PlayerStat
{
	int hits;
	int misses;
	int shots;
	double hitToMissRatio;
	int isWinner;
} PlayerStat;

// Function prototypes
void DisplayWelcomeScreen();
void DisplayPlacementMenu();
void InitializeGameBoard(char board[][ROWS_COLS]);
int DecideStartingPlayer();
int ChooseRandomCoordinate();
void ManuallyPlaceShipsOnBoard(char board[][ROWS_COLS], int shipLength, char shipLetter);
void RandomlyPlaceShipsOnBoard(char board[][ROWS_COLS], int shipLength, char shipLetter);
int CheckManualPlacementShip(char board[][ROWS_COLS], int shipLength, int direction, int xCoords[], int yCoords[]);
int CheckRandomPlacementShip(char board[][ROWS_COLS], int shipLength, int direction, int x, int y);
int IsWinner(char board[][ROWS_COLS]);
int CheckShotDoneAlready(char board[][ROWS_COLS], int x, int y);
void UpdateBoard(char board[][ROWS_COLS], int x, int y, char* lastHitShip);
int CheckShotCoordinates(char board[][ROWS_COLS], int x, int y);
void DisplayBoard(char board[][ROWS_COLS], int player);
int CheckShipSunkStatus(char board[][ROWS_COLS], char ship_letter);
void LogCurrentMove(int x, int y, int checkShotCoordinates, int checkShipSunkStatus, FILE* output);
void LogPlayerStatistics(PlayerStat player, FILE *output);