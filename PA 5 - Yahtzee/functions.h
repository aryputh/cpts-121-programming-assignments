/*
*	Name: Aryan Puthran
*	Date: 10/14/2023
*	Course: CPT_S 121
*	Assignment: Programming Assignment 5
*
*	Description: This program will run the popular game, Yahtzee. This is
*		where function prototypes, preprocessor directives and defines
*		will be kept.
*/

#pragma once

// Proprocessor directives
#define _CRT_SECURE_NO_WARNINGS

// Includes the required libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void printGameMenu();
void printGameRules();
void rollDice(int dieRoll[]);
void printArrayValues(int array[], int numValues);
void printRollCombinations(int usedCombos[]);
int rerollDie();
int isCombinationUsed(int chosenCombination, int usedCombos[]);
void populateDiceInventory(int diceRollInv[], int diceRoll[]);
int sumDieValues(int diceRoll[]);
int addPointsBasedOnCombo(int chosenCombination, int diceRollInv[], int sumDice);