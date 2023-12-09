/*
*	Name: Aryan Puthran
*	Date: 9/11/2023
*	Course: CPT_S 121
*	Assignment: Programming Assignment 2, equations.h
*
*	Description: This program will solve equations for the user. This file contains
*		all of the preprocessor directives and prototypes needed.
*/

// Ensures this file is made 1 time
#pragma once

// Disable warnings pertaining to scanf being unsafe
#define _CRT_SECURE_NO_WARNINGS

// Import the required libraries for the equations
#include <stdio.h>
#include <math.h>

// Define constant variables
#define PI 3.14159
#define G 6.67e-11

// Function prototypes
double calculate_newtons_2nd_law(double mass, double acceleration);
double calculate_volume_cylinder(double radius, double height);
char perform_character_encoding(char plaintext_character);
double calculate_gravity_objects(double distance, double mass1, double mass2);
double calculate_resistive_divider(double r1, double r2, double voltageIn);
double calculate_distance_points(double x1, double x2, double y1, double y2);
double calculate_general_formula(double x, double z, int a);