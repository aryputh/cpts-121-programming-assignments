/*
*	Name: Aryan Puthran
*	Date: 9/11/2023
*	Course: CPT_S 121
*	Assignment: Programming Assignment 2, main.c
*
*	Description: This program will solve equations for the user. It will ask the user for
*		inputs, and display and output accordingly. This program uses multiple files to
*		achieve this.
*/

#include "equations.h"

// The main function, what happens when the program runs
int main(void)
{
	// Newton's 2nd law
	// Declare required variables
	double mass = 0.0, acceleration = 0.0, force = 0.0;

	// Print a prompt and gather user input
	printf("Please enter the mass (float) and acceleration (float) for Newton's 2nd Law:\n");
	scanf("%lf%lf", &mass, &acceleration);

	// Calculate and print out the results using user input
	force = calculate_newtons_2nd_law(mass, acceleration);
	printf("Newton's 2nd Law: force = mass * acceleration\n= %f * %f\n= %.2f\n\n", mass, acceleration, force);


	// Volume of a Cylinder
	// Declare required variables
	double radius = 0.0, height = 0.0, volume_cylinder = 0.0;

	// Print a prompt and gather user input
	printf("Please enter the radius (float) and height (float) for the Volume of a Cylinder:\n");
	scanf("%lf%lf", &radius, &height);

	// Calculate and print out the results using user input
	volume_cylinder = calculate_volume_cylinder(radius, height);
	printf("Volume of Cylinder: volume_cylinder = PI * radius^2 * height\n= PI * %f^2 * %f\n= %.2f\n\n",
		radius, height, volume_cylinder);


	// Character Encoding
	// Declare required variables
	char plaintext_character = 0, encoded_character = 0;

	// Print a prompt and gather user input
	printf("Please enter a character (char) for Character Encoding:\n");
	scanf(" %c", &plaintext_character);

	// Calculate and print out the results using user input
	encoded_character = perform_character_encoding(plaintext_character);
	printf("Encoded Character: encoded_character = (plaintext_character - 'a') + 'A'\n= (%c - 'a') + 'A'\n= %c\n\n",
		plaintext_character, encoded_character);


	// Gravitational Force of 2 Masses
	// Declare required variables
	double gDistance = 0.0, mass1 = 0.0, mass2 = 0.0, gForce = 0.0;

	// Print a prompt and gather user input
	printf("Please enter the gDistance (float), mass1 (float), and mass2 (float) for Gravity:\n");
	scanf("%lf%lf%lf", &gDistance, &mass1, &mass2);

	// Calculate and print out the results using user input
	gForce = calculate_gravity_objects(gDistance, mass, mass2);
	printf("Gravity: force = G * mass1 * mass2 / gDistance^2\n= G * %f * %f / %f^2\n= %.2f\n\n", gDistance, mass1,
		mass2, gForce);


	// Resistive Divider
	// Declare required variables
	double r1 = 0.0, r2 = 0.0, voltageIn = 0.0, vout = 0.0;

	// Print a prompt and gather user input
	printf("Please enter the r1 (float), r2 (float), and voltageIn (float) for Resistive Divider:\n");
	scanf("%lf%lf%lf", &r1, &r2, &voltageIn);

	// Calculate and print out the results using user input
	vout = calculate_resistive_divider(r1, r2, voltageIn);
	printf("Resistive Divider: vout = r2 / (r1 + r2) * voltageIn\n= %f / (%f + %f) * %f\n= %.2f\n\n", r2, r1, r2, voltageIn,
		vout);


	// Distance Formula
	// Declare required variables
	double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0, distanceResult = 0.0;

	// Print a prompt and gather user input
	printf("Please enter the x1 (float), y1 (float), x2 (float), and y2 (float) for the Distance Formula:\n");
	scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);

	// Calculate and print out the results using user input
	distanceResult = calculate_distance_points(x1, x2, y1, y1);
	printf("Distance Formula: distanceResult = sqrt((x2 - x1)^2 + (y2 - y1)^2)\n= sqrt((%f - %f)^2 + pow(%f - %f)^2)\n= %.2f\n\n",
		x2, x1, y2, y1, distanceResult);


	// General Equation
	// Declare required variables
	double x = 0.0, z = 0.0, y = 0.0;
	int a = 0;

	// Print a prompt and gather user input
	printf("Please enter the x (float), z (float), and a (int) for the General Equation:\n");
	scanf("%lf%lf%d", &x, &z, &a);

	// Calculate and print out the results using user input
	y = calculate_general_formula(x, z, a);
	printf("General Equation: y = (73 / 12) - x * z + a / (a %% 2)\n= (73 / 12) - %f * %f + %f / (%f %% 2)\n= %.2f\n\n",
		x, z, a, a, y);
}