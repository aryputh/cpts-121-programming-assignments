/*
*	Name: Aryan Puthran
*	Date: 9/17/2023
*	Course: CPT_S 121
*	Assignment: Programming Assignment 3
*
*	Description: This program will take the stats of 5 students
*		in a file and perform calculations on them. After this happens,
*		they will be outputted into another file. This file contains
*		all of the required functions.
*/

#include "functions.h"

/*
*	Inputs: FILE*
*	Outputs: double
*
*	Reads a double from the given file and returns it.
*/
double read_double(FILE* infile)
{
	double result = 0.0;

	fscanf(infile, "%lf", &result);

	return result;
}

/*
*	Inputs: FILE*
*	Outputs: int
*
*	Reads an int from the given file and returns it.
*/
int read_integer(FILE* infile)
{
	int result = 0;

	fscanf(infile, "%d", &result);

	return result;
}

/*
*	Inputs: double number1, double number2, double number3, double number4, double number5
*	Outputs: double
*
*	Adds all the numbers up together.
*/
double calculate_sum(double number1, double number2, double number3, double number4,
	double number5)
{
	return number1 + number2 + number3 + number4 + number5;
}

/*
*	Inputs: double sum, int number
*	Outputs: double
*
*	Finds the average of the numbers. Checks for division by 0.
*/
double calculate_mean(double sum, int number)
{
	if (number != 0)
	{
		return sum / number;
	}
	else
	{
		return -1.0;
	}
}

/*
*	Inputs: double number, double mean
*	Outputs: double
*
*	Finds the deviation of the number.
*/
double calculate_deviation(double number, double mean)
{
	return number - mean;
}

/*
*	Inputs: double deviation1, double deviation2, double deviation3, double deviation4,
		double deviation5, int number
*	Outputs: double
*
*	Finds the variance given the deviations and a number.
*/
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4,
	double deviation5, int number)
{
	return ((pow(deviation1, 2) + pow(deviation2, 2) + pow(deviation3, 2) + pow(deviation4, 2) +
		pow(deviation5, 2)) / number);
}

/*
*	Inputs: double variance
*	Outputs: double
*
*	Calculates the standard deviation.
*/
double calculate_standard_deviation(double variance)
{
	return sqrt(variance);
}

/*
*	Inputs: double number1, double number2
*	Outputs: double
*
*	Compares 2 numbers, and returns the largest one.
*/
double compare_nums_max(double number1, double number2)
{
	if (number1 > number2)
	{
		return number1;
	}
	else
	{
		return number2;
	}
}

/*
*	Inputs: double number1, double number2
*	Outputs: double
*
*	Compares 2 numbers, and returns the smallest one.
*/
double compare_nums_min(double number1, double number2)
{
	if (number1 < number2)
	{
		return number1;
	}
	else
	{
		return number2;
	}
}

/*
*	Inputs: double number1, double number2, double number3, double number4, double number5
*	Outputs: double
*
*	Finds the largest number out of the given numbers.
*/
double find_max(double number1, double number2, double number3, double number4, double number5)
{
	return compare_nums_max(compare_nums_max(compare_nums_max(compare_nums_max(number1, number2),
		number3), number4), number5);
}

/*
*	Inputs: double number1, double number2, double number3, double number4, double number5
*	Outputs: double
*
*	Finds the smallest number out of the given numbers.
*/
double find_min(double number1, double number2, double number3, double number4, double number5)
{
	return compare_nums_min(compare_nums_min(compare_nums_min(compare_nums_min(number1, number2),
		number3), number4), number5);
}

/*
*	Inputs: FILE* outfile, double number
*	Outputs: none
*
*	Prints a double value given the file to an output file,
*		to the hundredths place.
*/
void print_double(FILE* outfile, double number)
{
	fprintf(outfile, "%.2f\n", number);
}