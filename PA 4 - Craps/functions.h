/*
*	Name: Aryan Puthran
*	Date: 9/27/2023
*	Course: CPT_S 121
*	Assignment: Programming Assignment 4
*
*	Description: This program will run a game of craps, and ask for input/output accordingly.
*		This game will use random numbers, function decomposition, and more. This file
*		houses all of the function prototypes, imports, and preprocessor directives.
*/

#pragma once

// Fix scanf and printf errors
#define _CRT_SECURE_NO_WARNINGS

// Import required libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_game_rules(void);
double get_bank_balance(void);
double get_wager_amount(void);
int check_wager_amount(double wager, double balance);
void roll_die(int* die1Ptr, int* die2Ptr);
int calculate_sum_dice(int die1_value, int die2_value);
int is_win_loss_or_point(int sum_dice);
int is_point_loss_or_neither(int sum_dice, int point_value);
double adjust_bank_balance(double bank_balance, double
	wager_amount, int add_or_subtract);
void chatter_messages(int number_rolls, int win_loss_neither, double
	initial_bank_balance, double current_bank_balance);