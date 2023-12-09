## cpts 121 programming assignments
All of my programming assignments for my CptS 121 course. Basic description of each PA is available in this file.

### Programming Assignment 1 - Solving Equations
Create a program that evaluates equations. Checking for faulty numbers aren't required.
**Equations**
1. Newton’s Second Law of Motion
    - force = mass * acceleration
3. Volume of a cylinder
    - volume_cylinder = PI * radius^2 * height
5. Character encoding
    - encoded_character = (plaintext_character - 'a') + 'A
8. Gravity
    - force = G * mass1 * mass2 / distance^2
10. Resistive divider
    - vout = r2 / (r1 + r2) * vin
12. Distance between two points
    - distance = √((x1 - x2)^2 + (y1 - y2)^2)
14. General equation
    - y = (73 / 12) - x * z + a / (a % 2)

### Programming Assignment 2 - Solving Equations using Scanning
Alter PA 1 to be modular and use scanning (scanf) for inputs. Do not check for faulty inputs.

### Programming Assignment 3 - GPA Operations
Write a program that processes numbers, corresponding to student records read from a file. You must define the following functions and process them accordingly.
**Required Functions**
1. Read a double from a file.
    - double read_double (FILE *infile)
2. Read an int from a file.
    - int read_integer (FILE *infile)
3. Find the sum of the numbers.
    - double calculate_sum (double number1, double number2, double number3, double number4, double number5)
4. Find the average.
    - double calculate_mean (double sum, int number)
5. Find the deviation.
    - double calculate_deviation (double number, double mean)
6. Find the variance.
    - double calculate_variance (double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number)
7. Find the standard deviation.
    - double calculate_standard_deviation (double variance)
8. Find the maximum number.
    - double find_max (double number1, double number2, double number3, double number4, double number5)
9. Find the minimum number.
    - double find_min (double number1, double number2, double number3, double number4, double number5)
10. Print a double to the output file.
    - void print_double (FILE *outfile, double number)

**Required Processes**
1. Find sum of GPAs.
2. Find sum of class standings.
3. Find sum of ages.
4. Find average GPA, writing to output file.
5. Find average class standing, writing to output file.
6. Find average age, writing to output file.
7. Find deviation of GPAs.
8. Find variance of GPAs.
9. Find standard deviation of GPAs, writing to output file.
10. Determine minimum GPA, writing to output file.
11. Determine maximum GPA, writing to output file.
12. Close the input and output files.

**Expected Input File Format**
Student ID (int)
GPA (double)
Class Standing (int)
Age (double)

**Expected Input File Format**
GPA Mean (double)
Class Standing Mean (double)
Age Mean (double)
GPA Standard Deviation (double)
GPA Minimum (double)
GPA Maximum (double)

### Programming Assignment 4 - Craps
Coming soon.

### Programming Assignment 5 - Yahtzee
Coming soon.

### Programming Assignment 6 - Battleship
Coming soon.

### Programming Assignment 7 - 5-Card Poker
Coming soon.
