/*
*	Name: Aryan Puthran
*	Date: 9/11/2023
*	Course: CPT_S 121
*	Assignment: Programming Assignment 2, equations.c
*
*	Description: This program will solve equations for the user. This file contains
*		the functions that do the actual calculations.
*/

#include "equations.h"

/*
*	Inputs: double mass, double acceleration
*	Outputs: double
* 
*	Calculates and returns the force, given mass and acceleration.
*/
double calculate_newtons_2nd_law(double mass, double acceleration)
{
	// Calculate and return the results
	return mass * acceleration;
}

/*
*	Inputs: double radius, double height
*	Outputs: double
* 
*	Calculates and returns the volume of a cylinder, given radius and height.
*/
double calculate_volume_cylinder(double radius, double height)
{
	// Calculate and return the results
	return PI * pow(radius, 2) * height;
}

/*
*	Inputs: char plaintext_character
*	Outputs: char
* 
*	Calculates and returns the encoded character, given a plaintext character.
*/
char perform_character_encoding(char plaintext_character)
{
	// Calculate and return the results
	return (plaintext_character - 'a') + 'A';
}

/*
*	Input: double distance, double mass1, double mass2
*	Outputs: double
* 
*	Calculates and returns the gravitational force of 2 masses, given mass1,
*		mass2, and distance.
*/
double calculate_gravity_objects(double distance, double mass1, double mass2)
{
	// Calculate and return the results
	return G * mass1 * mass2 / pow(distance, 2);
}

/*
*	Inputs: double r1, double r2, double voltageIn
*	Outputs: double
* 
*	Calculates and returns the resistive divider, given r1, r2, and voltageIn.
*/
double calculate_resistive_divider(double r1, double r2, double voltageIn)
{
	// Calculate and return the results
	return r2 / (r1 + r2) * voltageIn;
}

/*
*	Inputs: double x1, double x2, double y1, double y2
*	Outputs: double
* 
*	Calculates and returns the between 2 points, given x1, x2, y1, and y2.
*/
double calculate_distance_points(double x1, double x2, double y1, double y2)
{
	// Calculate and return the results
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

/*
*	Inputs: double x, double z, double a
*	Outputs: double
* 
*	Calculates and returns y-value of using the general formula, given x,
*		z and a.
*/
double calculate_general_formula(double x, double z, int a)
{
	// Calculate and return the results
	return ((double)(73 / 12) - x * z + a / (a % 2));
}