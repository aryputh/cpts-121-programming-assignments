## cpts 121 programming assignments
All of my programming assignments for my CptS 121 course. Basic description of each PA is available in this file.

### Programming Assignment 1 - Solving Equations
Create a program that evaluates equations. Checking for faulty numbers aren't required.
**Equations**
1. Newton’s Second Law of Motion: force = mass * acceleration
2. Volume of a cylinder: volume_cylinder = PI * radius^2 * height
3. Character encoding: encoded_character = (plaintext_character - 'a') + 'A
4. Gravity: force = G * mass1 * mass2 / distance^2
5. Resistive divider: vout = r2 / (r1 + r2) * vin
6. Distance between two points: distance = √((x1 - x2)^2 + (y1 - y2)^2)
7. General equation: y = (73 / 12) - x * z + a / (a % 2)

### Programming Assignment 2 - Solving Equations using Scanning
Alter PA 1 to be modular and use scanning for inputs. Do not check for faulty inputs.
**Equations**
1. Newton’s Second Law of Motion: force = mass * acceleration
2. Volume of a cylinder: volume_cylinder = PI * radius^2 * height
3. Character encoding: encoded_character = (plaintext_character - 'a') + 'A
4. Gravity: force = G * mass1 * mass2 / distance^2
5. Resistive divider: vout = r2 / (r1 + r2) * vin
6. Distance between two points: distance = √((x1 - x2)^2 + (y1 - y2)^2)
7. General equation: y = (73 / 12) - x * z + a / (a % 2)

### Programming Assignment 3 - GPA Operations
Write a program that processes numbers, corresponding to student records read from a file. You must define the following functions and process them accordingly.
**Required Functions**
1. double read_double (FILE *infile): Read a double from a file.
2. int read_integer (FILE *infile): Read an int from a file.
3. double calculate_sum (double number1, double number2, double number3, double number4, double number5): Find the sum of the numbers.
4. double calculate_mean (double sum, int number): Find the average.
5. double calculate_deviation (double number, double mean): Find the deviation.
6. double calculate_variance (double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number): Find the variance.
7. double calculate_standard_deviation (double variance): Find the standard deviation.
8. double find_max (double number1, double number2, double number3, double number4, double number5): Find the maximum number.
9. double find_min (double number1, double number2, double number3, double number4, double number5): Find the minimum number.
10. void print_double (FILE *outfile, double number): Print a double to the output file.

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
