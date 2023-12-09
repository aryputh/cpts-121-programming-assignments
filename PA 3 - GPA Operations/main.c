/*
*	Name: Aryan Puthran
*	Date: 9/17/2023
*	Course: CPT_S 121
*	Assignment: Programming Assignment 3
*
*	Description: This program will take the stats of 5 students
*		in a file and perform calculations on them. After this happens,
*		they will be outputted into another file.
*/

#include "functions.h"

int main()
{
	// Declares required variables, seperates declarations by group
	int studentId1 = 0, studentId2 = 0, studentId3 = 0, studentId4 = 0, studentId5 = 0;
	double studentGpa1 = 0.0, studentGpa2 = 0.0, studentGpa3 = 0.0, studentGpa4 = 0.0, studentGpa5 = 0.0;
	int studentStanding1 = 0, studentStanding2 = 0, studentStanding3 = 0, studentStanding4 = 0, studentStanding5 = 0;
	double studentAge1 = 0.0, studentAge2 = 0.0, studentAge3 = 0.0, studentAge4 = 0.0, studentAge5 = 0.0;
	double sumGpa = 0.0, sumStanding = 0.0, sumAges = 0.0, avgGpa = 0.0, avgStanding = 0.0, avgAges = 0.0;
	double studentDev1 = 0.0, studentDev2 = 0.0, studentDev3 = 0.0, studentDev4 = 0.0, studentDev5 = 0.0;
	double studentVariance = 0.0, studentStandardDev = 0.0, lowestGpa = 0.0, highestGpa = 0.0;

	// Opens an input file for reading and an ouput file for writing
	FILE* infile = fopen("input.dat", "r");
	FILE* outfile = fopen("output.dat", "w");

	// Reads 5 records from the input file
	studentId1 = read_integer(infile);
	studentGpa1 = read_double(infile);
	studentStanding1 = read_integer(infile);
	studentAge1 = read_double(infile);

	studentId2 = read_integer(infile);
	studentGpa2 = read_double(infile);
	studentStanding2 = read_integer(infile);
	studentAge2 = read_double(infile);

	studentId3 = read_integer(infile);
	studentGpa3 = read_double(infile);
	studentStanding3 = read_integer(infile);
	studentAge3 = read_double(infile);

	studentId4 = read_integer(infile);
	studentGpa4 = read_double(infile);
	studentStanding4 = read_integer(infile);
	studentAge4 = read_double(infile);

	studentId5 = read_integer(infile);
	studentGpa5 = read_double(infile);
	studentStanding5 = read_integer(infile);
	studentAge5 = read_double(infile);

	// Calculates sum of GPAs, class standings and ages
	sumGpa = calculate_sum(studentGpa1, studentGpa2, studentGpa3, studentGpa4, studentGpa5);
	sumStanding = calculate_sum(studentStanding1, studentStanding2, studentStanding3, studentStanding4,
		studentStanding5);
	sumAges = calculate_sum(studentAge1, studentAge2, studentAge3, studentAge4, studentAge5);

	// Calculates the mean of GPAs, class standing, ages, writing to the output file
	avgGpa = calculate_mean(sumGpa, 5);
	print_double(outfile, avgGpa);

	avgStanding = calculate_mean(sumStanding, 5);
	print_double(outfile, avgStanding);

	avgAges = calculate_mean(sumAges, 5);
	print_double(outfile, avgAges);

	// Calculates the deviation of GPAs from the mean
	studentDev1 = calculate_deviation(studentGpa1, avgGpa);
	studentDev2 = calculate_deviation(studentGpa2, avgGpa);
	studentDev3 = calculate_deviation(studentGpa3, avgGpa);
	studentDev4 = calculate_deviation(studentGpa4, avgGpa);
	studentDev5 = calculate_deviation(studentGpa5, avgGpa);

	// Calculates the variance of the GPAs
	studentVariance = calculate_variance(studentDev1, studentDev2, studentDev3, studentDev4, studentDev5, 5);

	// Calculates the standard deviation of the GPAs, writing to the output file
	studentStandardDev = calculate_standard_deviation(studentVariance);
	print_double(outfile, studentStandardDev);

	// Determines the lowest GPA, writing to output file
	lowestGpa = find_min(studentGpa1, studentGpa2, studentGpa3, studentGpa4, studentGpa5);
	print_double(outfile, lowestGpa);

	// Determines the maximum GPA, writing to output file
	highestGpa = find_max(studentGpa1, studentGpa2, studentGpa3, studentGpa4, studentGpa5);
	print_double(outfile, highestGpa);

	// Close the input and output files
	fclose(infile);
	fclose(outfile);
}