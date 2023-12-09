/*
*	Name: Aryan Puthran
*	Date: 11/9/2023
*	Course: CPT_S 121
*	Assignment: Programming Assignment 7
*
*	Description: This program will play a game of 5-card poker. Authors: Deitel & Deitel - C How to Program
*/

// Makes the header file be created once
#pragma once

// Proprocessor directives
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defines structs
typedef struct card
{
	int indexFaceValue;
	int indexSuitValue;
}
Card;

typedef struct hand
{
	Card currentHand[5];
}
Hand;

// Prototype funtions
void printRules();
void printMenu();
void printHand(Hand hand, char* suits[4], char* faces[13]);
void populateHand(Hand *hand);
void populateDeck(Card deckOfCards[][13]);
void shuffleDeck(Card deckOfCards[][13]);
void dealCards(Card deckOfCards[][13], int *nextCardIndex, Hand *hand);
void populateSuitFreq(Hand hand, int freqArray[4]);
void populateValueFreq(Hand hand, int freqArray[4]);
int determineSpecialCards(Hand hand, int freqTableSuits[4], int freqTableFaces[13]);
int findLongestConsecutiveValues(int freqTableFaces[13]);
void dealerHandEvaluate(Hand* dealerHand, int dealerFreqTableSuits[4], int dealerFreqTableFaces[13]);