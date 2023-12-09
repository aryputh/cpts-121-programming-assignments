/*
*	Name: Aryan Puthran
*	Date: 9/17/2023
*	Course: CPT_S 121
*	Assignment: Programming Assignment 3
*
*	Description: This program will take the stats of 5 students
*		in a file and perform calculations on them. After this happens,
*		they will be outputted into another file. This file contains
*		the required directives and prototypes.
*/

#pragma once

// Ignnore scanf() message
#define _CRT_SECURE_NO_WARNINGS

// Import required libraries
#include <stdio.h>
#include <math.h>

// Define function prototypes
double read_double(FILE* infile);
int read_integer(FILE* infile);
double calculate_sum(double number1, double number2, double number3, double number4, double number5);
double calculate_mean(double sum, int number);
double calculate_deviation(double number, double mean);
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);
double calculate_standard_deviation(double variance);
double compare_nums_max(double number1, double number2);
double compare_nums_min(double number1, double number2);
double find_max(double number1, double number2, double number3, double number4, double number5);
double find_min(double number1, double number2, double number3, double number4, double number5);
void print_double(FILE* outfile, double number);