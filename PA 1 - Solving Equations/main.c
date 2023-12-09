/*
*	Name: Aryan Puthran
*	Date: 9/2/2023
*	Course: CPT_S 121
*	Assignment: Programming Assignment 1
*
*	Description: This program will solve equations for the user. It will ask the user for
*		inputs, and display and output accordingly.
*/

// Disable warnings pertaining to scanf being unsafe
#define _CRT_SECURE_NO_WARNINGS

// Import the required libraries for the equations
#include <stdio.h>
#include <math.h>

// Define constant variables
#define PI 3.14159
#define G 6.67e-11

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
	force = mass * acceleration;
	printf("Newton's 2nd Law: force = mass * acceleration\n= %f * %f\n= %f\n\n", mass, acceleration, force);

	// Volume of a Cylinder
	// Declare required variables
	double radius = 0.0, height = 0.0, volume_cylinder = 0.0;
	// Print a prompt and gather user input
	printf("Please enter the radius (float) and height (float) for the Volume of a Cylinder:\n");
	scanf("%lf%lf", &radius, &height);
	// Calculate and print out the results using user input
	volume_cylinder = PI * pow(radius, 2) * height;
	printf("Volume of Cylinder: volume_cylinder = PI * radius^2 * height\n= PI * %f^2 * %f\n= %f\n\n",
		radius, height, volume_cylinder);

	// Character Encoding
	// Declare required variables
	char plaintext_character = 0, encoded_character = 0;
	// Print a prompt and gather user input
	printf("Please enter a character (char) for Character Encoding:\n");
	scanf(" %c", &plaintext_character);
	// Calculate and print out the results using user input
	encoded_character = (plaintext_character - 'a') + 'A';
	printf("Encoded Character: encoded_character = (plaintext_character - 'a') + 'A'\n= (%c - 'a') + 'A'\n= %c\n\n",
		plaintext_character, encoded_character);

	// Gravity
	// Declare required variables
	double gDistance = 0.0, mass1 = 0.0, mass2 = 0.0, gForce = 0.0;
	// Print a prompt and gather user input
	printf("Please enter the gDistance (float), mass1 (float), and mass2 (float) for Gravity:\n");
	scanf("%lf%lf%lf", &gDistance, &mass1, &mass2);
	// Calculate and print out the results using user input
	gForce = G * mass1 * mass2 / pow(gDistance, 2);
	printf("Gravity: force = G * mass1 * mass2 / gDistance^2\n= G * %f * %f / %f^2\n= %f\n\n", gDistance, mass1,
		mass2, gForce);

	// Resistive Divider
	// Declare required variables
	double r1 = 0.0, r2 = 0.0, vin = 0.0, vout = 0.0;
	// Print a prompt and gather user input
	printf("Please enter the r1 (float), r2 (float), and vin (float) for Resistive Divider:\n");
	scanf("%lf%lf%lf", &r1, &r2, &vin);
	// Calculate and print out the results using user input
	vout = r2 / (r1 + r2) * vin;
	printf("Resistive Divider: vout = r2 / (r1 + r2) * vin\n= %f / (%f + %f) * %f\n= %f\n\n", r2, r1, r2, vin,
		vout);

	// Distance Formula
	// Declare required variables
	double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0, distanceResult = 0.0;
	// Print a prompt and gather user input
	printf("Please enter the x1 (float), y1 (float), x2 (float), and y2 (float) for the Distance Formula:\n");
	scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
	// Calculate and print out the results using user input
	distanceResult = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	printf("Distance Formula: distanceResult = sqrt((x1 - x2)^2 + pow(y1 - y2)^2)\n= sqrt((%f - %f)^2 + pow(%f - %f)^2)\n= %f\n\n",
		x1, x2, y1, y2, distanceResult);

	// General Equation
	// Declare required variables
	double x = 0.0, z = 0.0, y = 0.0;
	int a = 0;
	// Print a prompt and gather user input
	printf("Please enter the x (float), z (float), and a (int) for the General Equation:\n");
	scanf("%lf%lf%d", &x, &z, &a);
	// Calculate and print out the results using user input
	y = ((double) (73 / 12) - x * z + a / (a % 2));
	printf("General Equation: y = (73 / 12) - x * z + a / (a %% 2)\n= (73 / 12) - %f * %f + %d / (%d %% 2)\n= %f\n\n",
		x, z, a, a, y);
}